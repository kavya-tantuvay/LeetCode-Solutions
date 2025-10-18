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
    void dfs(vector<string>&ans,string path,TreeNode*root){
        if(root==NULL)return;
        path+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
        }
        else{
            dfs(ans,path+"->",root->left);
            dfs(ans,path+"->",root->right);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root==NULL)return ans;
        string ds="";
        dfs(ans,ds,root);
        return ans;
    }
};