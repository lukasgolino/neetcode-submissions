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
    bool hasCycle(ListNode* head) {
        if (!head) {
            return false;
        }
        ListNode* left = head;
        if (!left->next) {
            return false;
        }
        ListNode* right = head->next;
        if (right == left) {
            return true;
        }
        if (!right->next) {
            return false;
        }

        // right->next->next exists
        while (right->next && right->next->next) {
            if (left == right) {
                // cycle found, return true
                return true;
            } else {
                // iterate both
                left = left->next;
                right = right->next->next;
            }
        }
        return false;
    }
};
