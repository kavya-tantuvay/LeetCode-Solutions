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
    int pairSum(ListNode* head) {
        ListNode*temp=head;
        vector<int>arr;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        int l=0,r=n-1;
        int maxi=arr[l]+arr[r];
        while(l<r){
            maxi=max(maxi,arr[l]+arr[r]);
            l++;
            r--;
        }
        return maxi;
    }
};