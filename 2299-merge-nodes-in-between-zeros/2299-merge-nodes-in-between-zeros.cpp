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
        ListNode* node = head;
        head = node->next;
        while (node != nullptr) {
            if (node->val == 0) {
                ListNode* temp = node->next;
                delete node;
                node = temp;
            } else if (node->next->val != 0) {
                ListNode* temp = node->next;
                node->val += temp->val;
                node->next = temp->next;
                delete temp;
            } else {
                node->next = node->next->next;
                node = node->next;
            }
        }
        return head;
    }
};