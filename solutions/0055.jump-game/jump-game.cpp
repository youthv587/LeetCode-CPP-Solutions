/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (31.50%)
 * Total Accepted:    245K
 * Total Submissions: 777.7K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
#include <vector>

using namespace std;

class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int maxstep = -1;
        for (auto iter = nums.cbegin(); iter != nums.cend() - 1; ++iter) {
            maxstep = *iter > maxstep - 1 ? *iter : maxstep - 1;
            if (maxstep == 0) return false;
        }
        return true;
    }
};

