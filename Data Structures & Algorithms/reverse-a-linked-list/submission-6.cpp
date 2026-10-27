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
    ListNode* reverseList(ListNode* head) {
        ListNode* before = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* after = current->next;
            // Overwrite with what was before
            current->next = before;
            // Then update before
            before = current;
            // Update current for next loop
            current = after;
            after = current->next;
        }
        return before;
    }
};
