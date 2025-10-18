/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // bool dfs(TreeNode*root,vector<TreeNode*>&st,TreeNode*p){
    //     if(root==NULL)return false;
    //     st.push_back(root);
    //     if(root==p){
    //         st.push_back(p);
    //         return true;
    //     }
    //     if(dfs(root->left,st,p) || dfs(root->right,st,p))return true;
    //     st.pop_back();
    //     return false;
    // }
    // vector<TreeNode*>hdfs(TreeNode*root,TreeNode*p){
    //     vector<TreeNode*>st;
    //     if(root==NULL)return st;
    //     dfs(root,st,p);
    //     return st;
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL || root==p || root==q)return root;
       TreeNode*left=lowestCommonAncestor(root->left,p,q);
       TreeNode*right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL)return right;
        else if(right==NULL)return left;
        else return root;
    }
};