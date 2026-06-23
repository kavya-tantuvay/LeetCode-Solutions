struct Node{
    Node*links[2];
    bool flag=false;
    bool containskey(int bit){
        return links[bit]!=NULL;
    }
    Node* getnode(int bit){
        return links[bit];
    }
    void putnode(int bit,Node*node){
        links[bit]=node;
    }
    bool isend(){
        return flag==true;
    }
    void setend(){
        flag=true;
    }
};
class Trie{
    private:
    Node*root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node*node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containskey(bit)){
                node->putnode(bit,new Node());
            }
            node=node->getnode(bit);
        }
    }
    int getmax(int num){
        Node*node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containskey(1-bit)){
                maxi=maxi|(1<<i);
                node=node->getnode(1-bit);
            }
            else{
                node=node->getnode(bit);
            }

        }
        return maxi;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int n=nums.size();
        for(auto it:nums){
            trie.insert(it);
        }
        int maxi=0;
        for(auto it:nums){
            maxi=max(maxi,trie.getmax(it));
        }
        return maxi;
    }
};