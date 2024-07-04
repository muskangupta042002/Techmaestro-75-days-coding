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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* node=head->next;
        ListNode* ans=new ListNode(0);
        ListNode* res=ans;
        int sum=0;
        while(node!=NULL){
            if(node->val!=0){
                sum+=node->val;
                node=node->next;

            }
            else{
                ans->next=new ListNode(sum);
                ans=ans->next;
                sum=0;
                node=node->next;
            }
        }
        return res->next;
    }
};