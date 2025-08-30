/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
using pp = pair<int, ListNode*>;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dnode=new ListNode(-1);
        ListNode* temp=dnode;
        priority_queue<pp,vector<pp>,greater<pp>>minh;
        for(int i=0;i<lists.size();i++){
            if(lists[i])minh.push({lists[i]->val,lists[i]});
        }
        while(!minh.empty()){
            auto it=minh.top();
            minh.pop();
            temp->next=it.second;
            if(it.second->next){
                minh.push({it.second->next->val,it.second->next});
            }
            temp=temp->next;
        }
        return dnode->next;
    }
};