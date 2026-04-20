class Node {
public:
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key_,int val_) {
        key = key_;
        val = val_;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
private:
    int cap;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    map<int,Node*> mp;
    void insertHead(Node* node) {
        Node* nxt = head->next;
        head->next = node;
        node->next = nxt;
        nxt->prev = node;
        node->prev = head;
    }
    void delpos(Node* node) {
        Node* nxt = node->next;
        Node* pre = node->prev;
        nxt->prev = pre;
        pre->next = nxt;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        Node* node = mp[key];
        delpos(node);
        insertHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            Node* node = mp[key];
            node->val = value;
            delpos(node);
            insertHead(node);
        }
        else {
            if(mp.size() == cap) {
                Node* ele = tail->prev;
                mp.erase(ele->key);
                delpos(ele);
            }
            Node* node = new Node(key,value);
            mp[key] = node;
            insertHead(node);
        }
    }
};
