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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *temp = head, *pre = NULL;
        set<int> s(nums.begin(), nums.end());
        while (temp != NULL) {
            if (s.find(temp->val) != s.end()) {
                // ListNode* pre=
                if (pre == NULL) {
                    head = temp->next;
                    temp = head;
                } else {
                    pre->next = temp->next;
                    temp = pre;
                }
            } else {
                pre = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};