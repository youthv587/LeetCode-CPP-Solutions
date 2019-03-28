/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (30.12%)
 * Total Accepted:    146.5K
 * Total Submissions: 486.4K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
 * reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode *fast, *slow;
        for (fast = slow = head; fast != nullptr && fast->next != nullptr; fast = fast->next->next, slow = slow->next) ;
        ListNode *cur = slow->next;
        slow->next = nullptr;
        while (cur != nullptr) {
            ListNode *tmp = cur->next;
            cur->next = slow->next;
            slow->next = cur;
            cur = tmp;
        }
        for (ListNode *lhalf = head, *rhalf = slow->next; rhalf != nullptr; lhalf = rhalf->next, rhalf = slow->next) {
            slow->next = rhalf->next;
            rhalf->next = lhalf->next;
            lhalf->next = rhalf;
        }
    }
};

