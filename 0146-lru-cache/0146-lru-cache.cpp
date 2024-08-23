class LRUCache {
public:
    int size;

    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);

    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        size = capacity;
        head->prev = NULL;
        head->next = tail;
        tail->prev = head;
        tail->next = NULL;
    }

    void addNode(Node* newNode) {
        Node* headNext = head->next;
        newNode->next = headNext;
        newNode->prev = head;
        head->next = newNode;
        headNext->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return temp->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
            // update location and this at head
        }

        if (size == mp.size()) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */