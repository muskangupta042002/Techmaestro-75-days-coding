class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v) {
            key = k;
            val = v;
        }
    };
    int size;
    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);
    map<int, Node*> mp;
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* headNext = head->next;
        newNode->next = headNext;
        newNode->prev = head;
        head->next = newNode;
        headNext->prev=newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delNodeNext = delNode->next;
        Node* delNodePrev = delNode->prev;
        delNodePrev->next = delNodeNext;
        delNodeNext->prev = delNodePrev;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* temp = mp[key];
        mp.erase(key);
        deleteNode(temp);
        addNode(temp);
        mp[key] = head->next;
        return temp->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* k = mp[key];
            mp.erase(key);
            deleteNode(k);
        }
        if (size == mp.size()) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        
        Node* temp = new Node(key, value);
        addNode(temp);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */