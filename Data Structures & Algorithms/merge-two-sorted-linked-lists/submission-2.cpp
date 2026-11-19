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
    void printListNode(ListNode* node) {
        if (node->next == nullptr) {
            std::cout << "List node at " << node << " = " << node->val << " is the end \n";
        } else {
            std::cout << "List node at " << node << " = " << node->val
                      << " and next = " << node->next << "\n = ";
            printListNode(node->next);
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* outputListReturn = &dummy;

        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }

        printListNode(&dummy);
        printListNode(list1);
        printListNode(list2);

        while (list1 && list2) {
            if (list1->val < list2->val) {
                outputListReturn->next = list1;
                list1 = list1->next;
            } else {
                outputListReturn->next = list2;
                list2 = list2->next;
            }
            outputListReturn = outputListReturn->next;
        }

        while (list1) {
            outputListReturn->next = list1;
            list1 = list1->next;
            outputListReturn = outputListReturn->next;
        }

        while (list2) {
            outputListReturn->next = list2;
            list2 = list2->next;
            outputListReturn = outputListReturn->next;
        }

        return dummy.next;
    }
};
