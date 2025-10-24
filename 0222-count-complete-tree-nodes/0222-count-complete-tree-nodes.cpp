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
    int findlh(TreeNode*node){
        int ht=0;
        while(node){
            ht++;
            node=node->left;
        }
        return ht;
    }
    int findrh(TreeNode*node){
        int ht=0;
        while(node){
            ht++;
            node=node->right;
        }
        return ht;
    }
    
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int lh=findlh(root);
        int rh=findrh(root);
        if(lh==rh)return (1<<lh)-1;
        return 1+(countNodes(root->left)+countNodes(root->right));
    }
};