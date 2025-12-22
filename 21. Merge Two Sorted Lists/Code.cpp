// This is my own approach as a learner of Data Structures & Algorithms
//
// GitHub   : github.com/raghuramofficial07
// LinkedIn : https://in.linkedin.com/in/raghuram1241
//

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // Create a dummy node to act as the starting point of the merged list
        ListNode* dummy = new ListNode(0);

        // Tail pointer used to build the merged list step by step
        ListNode* tail = dummy;

        // Traverse both lists simultaneously and compare their values
        while (l1 != nullptr && l2 != nullptr) {

            // Attach the node with the smaller value to the merged list
            if (l1->val < l2->val) {
                tail->next = new ListNode(l1->val);
                tail = tail->next;
                l1 = l1->next;
            } else {
                tail->next = new ListNode(l2->val);
                tail = tail->next;
                l2 = l2->next;
            }
        }

        // Append remaining nodes from list l1 (if any)
        while (l1 != nullptr) {
            tail->next = new ListNode(l1->val);
            tail = tail->next;
            l1 = l1->next;
        }

        // Append remaining nodes from list l2 (if any)
        while (l2 != nullptr) {
            tail->next = new ListNode(l2->val);
            tail = tail->next;
            l2 = l2->next;
        }

        // Return the head of the merged list (skipping the dummy node)
        return dummy->next;
    }
};
