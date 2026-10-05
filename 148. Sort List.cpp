#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode*findMid(ListNode*head){
        ListNode*slow = head;
        ListNode*fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode*merge(ListNode*left,ListNode*right){
        if(left==NULL)return right;
        if(right==NULL)return left;
        ListNode*ans = new ListNode(-1);
        ListNode*temp = ans;
        while(left!=NULL && right!=NULL){
            if(left->val<=right->val){
                temp->next = left;
                left = left->next;
            }
            else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if(left!=NULL){
            temp->next = left;
        }
        else{
            temp->next = right;
        }
        return ans->next;

    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*mid = findMid(head);
        ListNode*left = head;
        ListNode*right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        ListNode*result = merge(left,right);
        return result;
    }
};