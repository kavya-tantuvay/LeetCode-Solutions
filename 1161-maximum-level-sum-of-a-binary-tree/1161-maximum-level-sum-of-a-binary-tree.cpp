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
    int maxLevelSum(TreeNode* root) {

        /*
            in the problem we are concered with the sum at a given level , which mean bfs
            
            -> we do bfs, calculate the sum for that level and if the sum is greater than 
            the previous max_sum we update the ans and the max_sum

            in order to know if we are on the same level or not - i'm thinking of maintaining it as
            pair<TreeNode , level>
         */

         int level = 0 , level_sum = INT_MIN , ans = 0 , max_sum = INT_MIN;
         queue<pair<TreeNode*, int>> q;
         q.push({root, 1});

         while(!q.empty()){

            auto node = q.front();
            q.pop();

            // we are on a new level
            if (level < node.second){
                
                if (max_sum < level_sum){
                    max_sum = level_sum;
                    ans = level;
                }
                level_sum = 0;
                level = node.second;
            }

            // add the childs to the queue
            level_sum += node.first->val;

            if (node.first->left != nullptr){
                q.push({node.first->left, node.second + 1});
            }

            if (node.first->right != nullptr){
                q.push({node.first->right, node.second + 1});
            }

            if (q.empty()){
                if (max_sum < level_sum){
                    max_sum = level_sum;
                    ans = level;
                }
            }

            
        }
        
        return ans;
    }
};