/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.63%)
 * Total Accepted:    506.8K
 * Total Submissions: 2.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;

        auto begin = nums.begin(), end = nums.end();
        sort(begin, end);

        for (auto left = begin; left != end - 2; ++left) {
            if (left != begin && *left == *(left - 1)) continue;
            if (*left > 0) break;

            auto mid = left + 1, right = end - 1;
            while (mid < right) {
                if (mid != left + 1 && *mid == *(mid - 1)) {
                    ++mid;
                    continue;
                }
                if (*left + *mid > 0) break;

                if (*left + *mid + *right > 0) --right;
                else if (*left + *mid + *right < 0) ++mid;
                else {
                    ans.push_back({*left, *mid, *right});
                    ++mid;
                    --right;
                }
            }
        }
        return ans;
    }
};

