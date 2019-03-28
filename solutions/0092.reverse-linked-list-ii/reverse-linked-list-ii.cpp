/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (34.32%)
 * Total Accepted:    183.8K
 * Total Submissions: 535.7K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note:?1 ¡Ü m ¡Ü n ¡Ü length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
class Solution {
  public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int mp = m, nq = n;
        ListNode *pre = new ListNode(0), *p = pre, *q = pre, *cur, *tmp;
        pre->next = head;
        while (--m) p = p->next;
        while (n--) q = q->next;
        q = q->next;
        cur = p->next;
        p->next = q;
        int len = nq - mp + 1;
        while (len--) {
            tmp = cur->next;
            cur->next = p->next;
            p->next = cur;
            cur = tmp;
        }
        return pre->next;
    }
};

