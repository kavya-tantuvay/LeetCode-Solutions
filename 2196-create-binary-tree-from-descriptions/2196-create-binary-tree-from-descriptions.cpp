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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n=descriptions.size();
        unordered_map<int,TreeNode*>nodes;
        set<int>st;
        nodes.reserve(n+1);
        
        for(auto &d:descriptions){
            int p=d[0]; //parent
            int c=d[1]; //child
            int isl=d[2]; //is left
            if(!nodes.contains(p)){
                nodes[p]=new TreeNode(p);
            }
            if(!nodes.contains(c)){
                nodes[c]=new TreeNode(c);
            }
            if(isl)nodes[p]->left=nodes[c];
            else nodes[p]->right=nodes[c];
            st.insert(c);
        }
        TreeNode* root=new TreeNode(0);
        for(auto it:nodes){
            if(!st.contains(it.first))root=it.second;
        }
        return root;
    }
};