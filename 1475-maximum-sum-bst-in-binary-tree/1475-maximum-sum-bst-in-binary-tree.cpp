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
class NodeValue{
    public:
    int minNode,maxNode,maxSum;
    NodeValue(int minNode,int maxNode,int maxSum){
        this->minNode=minNode;
        this->maxNode=maxNode;
        this->maxSum=maxSum;
    }
};
class Solution {
private:
     int maxSumOverall = 0;
    NodeValue helper(TreeNode*root){
        if(root==NULL){
            return NodeValue(INT_MAX,INT_MIN,0);
        }
        
        auto left=helper(root->left);
        auto right=helper(root->right);
        if(left.maxNode<root->val && root->val<right.minNode){
            int currSum = root->val + left.maxSum + right.maxSum;
            maxSumOverall = max(maxSumOverall, currSum);
            
            return NodeValue(min(root->val,left.minNode),max(root->val,right.maxNode),currSum);
        }
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSum,right.maxSum));
    }
public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSumOverall;
    }
};