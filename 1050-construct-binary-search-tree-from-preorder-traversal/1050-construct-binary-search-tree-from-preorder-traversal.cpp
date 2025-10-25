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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int>mpp;
        int ie=inorder.size()-1;
        int pe=ie;
        for(int i=0;i<=ie;i++){
            mpp[inorder[i]]=i;
        }
        TreeNode*root= bst(inorder,preorder,mpp,0,ie,0,pe);
        return root;
    }
    TreeNode* bst(vector<int>&inorder,vector<int>&preorder,unordered_map<int,int>&mpp,int is,int ie,int ps,int pe){
        if(is>ie || ps>pe)return NULL;
        TreeNode*root=new TreeNode(preorder[ps]);
        int inroot=mpp[root->val];
        int x=inroot-is;
        root->left=bst(inorder,preorder,mpp,is,inroot-1,ps+1,ps+x);
        root->right=bst(inorder,preorder,mpp,inroot+1,ie,ps+x+1,pe);
        return root;
    }
};