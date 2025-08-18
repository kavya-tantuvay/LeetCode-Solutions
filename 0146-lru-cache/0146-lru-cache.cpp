class LRUCache {
public:
    class node{
        public:
        int  key;
        int val;
        node* next;
        node*prev;
        node(int key_,int val_){
            key=key_;
            val=val_;
         }
    };
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*>mpp;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(node* nnode){
        node*baadme=nnode->next;
        node*pehle=nnode->prev;
        baadme->prev=pehle;
        pehle->next=baadme;
    }
    void insertAfterHead(node *nnode){
        node*baadme=head->next;
        nnode->next=baadme;
        head->next=nnode;
        nnode->prev=head;
        baadme->prev=nnode;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end())return -1;
        node*nnode=mpp[key];
        int res = nnode -> val;
        deleteNode(nnode);
        insertAfterHead(nnode);
        mpp[key]=head->next;
        return res;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            node*nnode=mpp[key];
            nnode->val=value;
            deleteNode(nnode);
            insertAfterHead(nnode);
           
        }
        else{
            if(mpp.size()==cap){
                node*nnode=tail->prev;
                mpp.erase(nnode->key);
                deleteNode(nnode);
                node*newnode=new node(key,value);
                insertAfterHead(newnode);
                mpp[key] = newnode;
            }
            else{
                node*newnode=new node(key,value);
                insertAfterHead(newnode);
                mpp[key]=newnode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */