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
    TreeNode* makeparents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent,int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode*res=NULL;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->val==start)res=cur;
            if (cur->left) {
                parent[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right) {
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
        return res;
    }
    int findtime(TreeNode*root,TreeNode*start,unordered_map<TreeNode*,TreeNode*>&parent){
        if(!start)return 0;
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        q.push(start);
        visited[start]=true;
        int time=0;
        while(!q.empty()){
            int size=q.size();
            int fl=0;
            for(int i=0;i<size;i++){
                TreeNode*cur=q.front();
                q.pop();
                if(cur->left && !visited[cur->left]){
                    fl=1;
                    visited[cur->left]=true;
                    q.push(cur->left);
                }
                if(cur->right && !visited[cur->right]){
                    fl=1;
                    visited[cur->right]=true;
                    q.push(cur->right);
                }
                if(parent[cur] && !visited[parent[cur]]){
                    fl=1;
                    visited[parent[cur]]=true;
                    q.push(parent[cur]);
                }
            }
            if(fl){
                ++time;
            }
        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root)return 0;
        unordered_map<TreeNode*,TreeNode*>parent;
        TreeNode*st=makeparents(root,parent,start);
        if(!start)return 0;
        int maxi=findtime(root,st,parent);
        return maxi;
    }
};