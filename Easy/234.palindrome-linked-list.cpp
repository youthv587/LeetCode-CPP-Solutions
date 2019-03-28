/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (35.53%)
 * Total Accepted:    240.3K
 * Total Submissions: 676.3K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode *head) {
        if (head == nullptr) return true;
        ListNode *slow, *fast, *cur, *tmp;
        slow = fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        cur = slow->next;
        slow->next = nullptr;
        while (cur != nullptr) {
            tmp = cur->next;
            cur->next = slow->next;
            slow->next = cur;
            cur = tmp;
        }
        cur = slow->next;
        tmp = head;
        while (cur != nullptr) {
            if (cur->val != tmp->val) return false;
            cur = cur->next;
            tmp = tmp->next;
        }
        return true;
    }
};

