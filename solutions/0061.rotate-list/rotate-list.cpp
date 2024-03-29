/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (26.72%)
 * Total Accepted:    182.5K
 * Total Submissions: 683.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked?list, rotate the list to the right by k places, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right:?0->1->2->NULL
 * rotate 4 steps to the right:?2->0->1->NULL
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) return head;
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *p = pre, *q = pre;
        int len;
        for (len = -1; p != nullptr; p = p->next) ++len;
        k %= len;
        p = pre;
        while (k--) q = q->next;

        while (q->next != nullptr) {
            p = p->next;
            q = q->next;
        }
        q->next = pre->next;
        pre->next = p->next;
        p->next = nullptr;

        return pre->next;
    }
};

