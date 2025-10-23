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
    vector<int>preo(TreeNode*root){
        vector<int>ans;
        if(root==NULL)return ans;
        pre(root,ans);
        return ans;
    }
    void pre(TreeNode*root,vector<int>&ans){
        if(root==NULL)return;
        ans.push_back(root->val);
        pre(root->left,ans);
        pre(root->right,ans);
    }
    
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        vector<int>pre=preo(root);
        int n=pre.size();
        return n;
    }
};