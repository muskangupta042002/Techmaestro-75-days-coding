class LFUCache {
public:
    class Node {
    public:
        int key;
        int val;
        int used;
        Node *prev, *next;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            used = 1;
        }
    };

    class List {
    public:
        int size;
        Node* head;
        Node* tail;
        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void addNode(Node* newNode) {
            Node* headNext = head->next;
            newNode->prev = head;
            newNode->next = headNext;
            headNext->prev = newNode;
            head->next = newNode;
            size++;
        }

        void deleteNode(Node* delNode) {
            Node* Next = delNode->next;
            Node* Prev = delNode->prev;

            Prev->next = Next;
            Next->prev = Prev;
            size--;
        }

        bool isEmpty() {
            return size == 0;
        }
    };

    unordered_map<int, Node*> mp;
    unordered_map<int, List*> freqMap;
    int maxSize, minFreq, currSize;
    
    LFUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreqMap(Node* node) {
        mp.erase(node->key);
        freqMap[node->used]->deleteNode(node);

        if (node->used == minFreq && freqMap[node->used]->isEmpty()) {
            minFreq++;
        }

        node->used += 1;

        if (freqMap.find(node->used) == freqMap.end()) {
            freqMap[node->used] = new List();
        }

        freqMap[node->used]->addNode(node);
        mp[node->key] = node;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            updateFreqMap(temp);
            return temp->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxSize == 0) {
            return;
        }

        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            temp->val = value;
            updateFreqMap(temp);
        } else {
            if (currSize == maxSize) {
                List* list = freqMap[minFreq];
                mp.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
                currSize--;
            }

            currSize++;
            minFreq = 1;

            if (freqMap.find(minFreq) == freqMap.end()) {
                freqMap[minFreq] = new List();
            }

            Node* node = new Node(key, value);
            freqMap[minFreq]->addNode(node);
            mp[key] = node;
        }
    }
};
