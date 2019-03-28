/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (28.44%)
 * Total Accepted:    198.6K
 * Total Submissions: 698.5K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */
#include <vector>

using namespace std;

class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            while (0 < nums[i] && nums[i] <= nums.size() && nums[n - 1] != n) {
                nums[i] = nums[n - 1];
                nums[n - 1] = n;
                n = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); ++i) if (nums[i] != i + 1) return i + 1;
        return nums.size() + 1;
    }
};

