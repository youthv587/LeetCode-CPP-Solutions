/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (37.04%)
 * Total Accepted:    130.8K
 * Total Submissions: 353.2K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ¡Ü j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
#include <vector>

using namespace std;

class NumArray {
  public:
    NumArray(vector<int> nums) {
        if (nums.size() == 0) sum.push_back(0);
        else sum.push_back(nums.front());
        for (int i = 1; i < nums.size(); ++i) sum.push_back(nums[i] + sum[i - 1]);
    }

    int sumRange(int i, int j) { return i == 0 ? sum[j] : sum[j] - sum[i - 1]; }

  private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

