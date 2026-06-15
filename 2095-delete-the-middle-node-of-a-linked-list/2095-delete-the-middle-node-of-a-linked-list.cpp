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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)return NULL;
       int cnt=0;
       ListNode*temp=head;
       while(temp){
        cnt++;
        temp=temp->next;
       } 
       int midd=cnt/2;
       temp=head;
       while(temp){
        midd--;
        if(midd==0){
            ListNode*delnode=temp->next;
            temp->next=temp->next->next;
            delete(delnode);
            return head;
        }
        temp=temp->next;
       }
       return head;
    }
};