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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pe=postorder.size()-1;
        int ie=inorder.size()-1;
        unordered_map<int,int>mpp;
        for(int i=0;i<=ie;i++){
            mpp[inorder[i]]=i;
        }
        TreeNode*root=build(inorder,postorder,mpp,0,ie,0,pe);
        return root;
    }
    TreeNode*build(vector<int>& inorder, vector<int>& postorder,unordered_map<int,int>&mpp,int is,int ie,int ps,int pe){
        if(ps>pe || is>ie)return NULL;
        TreeNode*root=new TreeNode(postorder[pe]);
        int inroot=mpp[root->val];
        int x=ie-inroot;
        root->left=build(inorder,postorder,mpp,is,inroot-1,ps,pe-x-1);
        root->right=build(inorder,postorder,mpp,inroot+1,ie,ps-x,pe-1);
        return root;
    }
};