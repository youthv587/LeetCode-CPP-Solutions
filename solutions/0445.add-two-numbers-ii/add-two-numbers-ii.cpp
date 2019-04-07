/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (49.54%)
 * Total Accepted:    85.1K
 * Total Submissions: 171.5K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 *
 *
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 *
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stack>

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        std::stack<int> n1, n2;
        for (ListNode *p = l1; p != nullptr; p = p->next) n1.push(p->val);
        for (ListNode *p = l2; p != nullptr; p = p->next) n2.push(p->val);
        int carry = 0;
        ListNode *pre = new ListNode(0);
        while (!n1.empty() || !n2.empty() || carry != 0) {
            if (!n1.empty()) {
                carry += n1.top();
                n1.pop();
            }
            if (!n2.empty()) {
                carry += n2.top();
                n2.pop();
            }
            ListNode *node = new ListNode(carry % 10);
            node->next = pre->next;
            pre->next = node;
            carry /= 10;
        }
        return pre->next;
    }
};
