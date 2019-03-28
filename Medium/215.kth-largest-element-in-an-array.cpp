/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (46.57%)
 * Total Accepted:    341.3K
 * Total Submissions: 732.8K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
#include <map>
#include <vector>

using namespace std;

class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        map<int, int> map;
        for (auto &n : nums) ++map[n];
        auto iter = map.crbegin();
        int sum = 0;
        while ((sum += iter->second) < k) ++iter;
        return iter->first;
    }
};

