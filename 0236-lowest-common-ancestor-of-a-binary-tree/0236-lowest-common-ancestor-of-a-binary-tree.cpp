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
    bool dfs(TreeNode*root,vector<TreeNode*>&st,TreeNode*p){
        if(root==NULL)return false;
        st.push_back(root);
        if(root==p){
            st.push_back(p);
            return true;
        }
        if(dfs(root->left,st,p) || dfs(root->right,st,p))return true;
        st.pop_back();
        return false;
    }
    vector<TreeNode*>hdfs(TreeNode*root,TreeNode*p){
        vector<TreeNode*>st;
        if(root==NULL)return st;
        dfs(root,st,p);
        return st;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>s1,s2;
        s1=hdfs(root,p);
        s2=hdfs(root,q);
        int n=min(s1.size(),s2.size());
        TreeNode*lca;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i])lca=s1[i];
            else break;
        }
        return lca;
    }
};