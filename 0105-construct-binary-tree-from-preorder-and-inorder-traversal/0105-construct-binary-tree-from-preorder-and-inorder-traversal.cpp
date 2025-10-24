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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        int pe=preorder.size()-1;
        int ie=inorder.size()-1;
        for(int i=0;i<=ie;i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,inorder,mpp,0,ie,0,pe);
        return root;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&mpp,int is,int ie,int ps,int pe){
        if(is>ie || ps>pe)return NULL;
        TreeNode*root=new TreeNode(preorder[ps]);
        int inroot=mpp[root->val];
        int x=inroot-is;
        root->left=build(preorder,inorder,mpp,is,inroot-1,ps+1,ps+x);
        root->right=build(preorder,inorder,mpp,inroot+1,ie,ps+x+1,pe);
        return root;
    }
};