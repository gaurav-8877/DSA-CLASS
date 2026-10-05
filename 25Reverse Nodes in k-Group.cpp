#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == NULL)
            return NULL;

        // Check whether k nodes are available
        ListNode* temp = head;

        for (int i = 0; i < k; i++) {
            if (temp == NULL)
                return head;

            temp = temp->next;
        }

        // Reverse k nodes
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        int count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Reverse remaining groups
        if (curr != NULL) {
            head->next = reverseKGroup(curr, k);
        }

        return prev;
    }
};