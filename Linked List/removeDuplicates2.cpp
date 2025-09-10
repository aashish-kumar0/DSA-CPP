#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    while (head) {
        if (head->next && head->val == head->next->val) {
            // Skip all nodes with the same value
            while (head->next && head->val == head->next->val) {
                head = head->next;
            }
            // Skip the last duplicate
            prev->next = head->next;
        } else {
            // No duplicate, move prev
            prev = prev->next;
        }
        head = head->next;
    }
    return dummy->next;
    }