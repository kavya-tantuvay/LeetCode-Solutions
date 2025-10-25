/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
 stack<TreeNode*>mystack;
 bool reverse=true;

public:
   
    BSTIterator(TreeNode* root,bool isreverse) {
        reverse=isreverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode*node=mystack.top();
        mystack.pop();
        int ans=node->val;
        if(!reverse)pushAll(node->right);
        else pushAll(node->left);
        return ans;
    }
    
    bool hasNext() {
        return !mystack.empty();
    }
private:
void pushAll (TreeNode*root){
    while(root){
        mystack.push(root);
        if(reverse==false)root=root->left;
        else root=root->right;
    }
}
};
class Solution {
public:
    vector<int>inorder(TreeNode*root){
        vector<int>ans;
        if(root==NULL)return ans;
        TreeNode*cur=root;
        while(cur){
            if(cur->left==NULL){
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode*prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
    
    bool findTarget(TreeNode* root, int k) {
        // vector<int>arr=inorder(root);
        // int n=arr.size();
        // int left=0;
        // int right=n-1;
        // while(left<right){
        //     int sum=arr[left]+arr[right];
        //     if(sum==k)return true;
        //     else if(sum<k)left++;
        //     else right--;
        // }
        // return false;
        if(!root)return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k)return true;
            else if(i+j<k)i=l.next();
            else j=r.next();
        }
        return false;
    }
};