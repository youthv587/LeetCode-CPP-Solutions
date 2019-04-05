/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (29.98%)
 * Total Accepted:    221.2K
 * Total Submissions: 736K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 * The solution set must not contain duplicate quadruplets.
 *
 * Example:
 *
 *
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 * ? [-1,  0, 0, 1],
 * ? [-2, -1, 1, 2],
 * ? [-2,  0, 0, 2]
 * ]
 *
 *
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        int sz = nums.size();
        if (sz < 4) return res;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < sz - 3; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            for (int second = first + 1; second < sz - 2; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;
                int low = second + 1, high = sz - 1;
                int re = target - nums[first] - nums[second];
                while (low < high) {
                    int re_nums = nums[low] + nums[high];
                    if (re_nums == re) {
                        res.push_back({nums[first], nums[second], nums[low], nums[high]});
                        while (low < high && nums[low] == nums[low + 1]) ++low;
                        while (low < high && nums[high] == nums[high - 1])
                            --high;
                        ++low;
                        --high;
                    } else if (re_nums > re) --high;
                    else ++low;
                }
            }
        }
        return res;
    }
};
