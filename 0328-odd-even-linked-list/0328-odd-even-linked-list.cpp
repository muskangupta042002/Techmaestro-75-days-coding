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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newNode=new ListNode(0);
        ListNode *temp=newNode, *odd=head, *even =head->next;
        while(odd!=NULL && odd->next!=NULL){
            newNode->next=new ListNode(odd->val);
            newNode=newNode->next;
            odd=odd->next->next;
            
        }
        
        
        if(odd!=NULL){
            newNode->next=new ListNode(odd->val);
            //odd=odd->next->next;
            newNode=newNode->next;
        }
        while(even!=NULL && even->next!=NULL){
            newNode->next=new ListNode(even->val);
            newNode=newNode->next;
            even=even->next->next;
            
        }
        if(even!=NULL){
            newNode->next=new ListNode(even->val);
            newNode=newNode->next;
        }
        return temp->next;
    }
};