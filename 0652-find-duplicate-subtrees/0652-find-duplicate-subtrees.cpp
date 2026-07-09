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
    string getstr(unordered_map<string,int>&mpp,TreeNode*node,vector<TreeNode*>&res){
        if(node==NULL)return "N";
        string s=to_string(node->val) + "," + getstr(mpp,node->left,res)+","+getstr(mpp,node->right,res);
        if(mpp[s]==1)res.push_back(node);
        mpp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>res;
        unordered_map<string,int>mpp;
        getstr(mpp,root,res);
        return res;
    }
};