/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (33.47%)
 * Total Accepted:    358.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * Example:
 *
 *
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
#include <queue>

using namespace std;

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto lstcompare = [](ListNode *l1, ListNode *l2) -> bool { return l1->val > l2->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(lstcompare)> queue(lstcompare);
        
        ListNode *pre = new ListNode(0), *tail = pre;
        for (auto &lst : lists) if (lst != nullptr) queue.push(lst);
        
        while (!queue.empty()) {
            tail->next = queue.top();
            tail = tail->next;
            queue.pop();
            if (tail->next != nullptr) queue.push(tail->next);
        }
        return pre->next;
    }
};
