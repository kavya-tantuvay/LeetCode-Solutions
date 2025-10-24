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
class Solution {
public:
    vector<int> preo(TreeNode* root) {
        vector<int>ans;
        //MORRIS TRAVERSAL
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
                ans.push_back(cur->val);
                cur=cur->left;
            }
            else{
                prev->right=NULL;
                cur=cur->right;
            }
            }
        }
        return ans;
    }
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)return;
        vector<int>pre=preo(root);
        root->left=NULL;
        TreeNode*nroot=new TreeNode(pre[1]);
        TreeNode*right=nroot;
        for(int i=2;i<pre.size();i++){
            TreeNode*node=new TreeNode(pre[i]);
            nroot->right=node;
            nroot=nroot->right; 
        }
        root->right=right;
        
    }
};