#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect whether cycle exists
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            // Cycle found
            if (slow == fast) {

                // Step 2: Find starting point of cycle
                ListNode* temp = head;

                while (temp != slow) {
                    temp = temp->next;
                    slow = slow->next;
                }

                return temp;
            }
        }

        // No cycle
        return nullptr;
    }
};

int main() {

    // Creating linked list:
    //
    // 1 -> 2 -> 3 -> 4
    //           ↑    |
    //           |____|
    //
    // Cycle starts at node 3

    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Creating cycle
    node4->next = node3;

    Solution obj;

    ListNode* result = obj.detectCycle(head);

    if (result != nullptr) {
        cout << "Cycle starts at node: " << result->val << endl;
    }
    else {
        cout << "No cycle found" << endl;
    }

    return 0;
}