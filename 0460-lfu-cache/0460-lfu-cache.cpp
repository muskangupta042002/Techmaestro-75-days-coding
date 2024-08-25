class LFUCache {
public:
    class Node {
    public:
        int key;
        int val;
        int used;
        Node *next, *prev;
        Node(int k, int v) {
            key = k;
            val = v;
            used = 1;
        }
    };

    class List {
    public:
        int size;
        Node *head, *tail;
        List() {
            size = 0;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }
        void addNode(Node* node) {
            Node* headNext = head->next;
            node->prev = head;
            node->next = headNext;
            head->next = node;
            headNext->prev = node;
            size++;
        }

        void deleteNode(Node* node) {
            Node* delNext = node->next;
            Node* delPrev = node->prev;
            delPrev->next = delNext;
            delNext->prev = delPrev;
            size--;
        }

        bool isEmpty() { return size == 0; }
    };
    int maxSize, minFreq, currSize;
    unordered_map<int, Node*> mp;
    unordered_map<int, List*> freqMap;
    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq = 0;
        currSize = 0;
    }

    void updateFreqMap(Node* node) {
        mp.erase(node->key);

        freqMap[node->used]->deleteNode(node);
        if (node->used == minFreq && freqMap[node->used]->isEmpty()) {
            minFreq++;
        }
        node->used++;
        if (freqMap.find(node->used) == freqMap.end()) {
            freqMap[node->used] = new List();
        }
        freqMap[node->used]->addNode(node);
        mp[node->key] = node;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* temp = mp[key];
        updateFreqMap(temp);

        return temp->val;
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
            freqMap[node->used]->addNode(node);
            mp[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */