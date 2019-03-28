/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (52.92%)
 * Total Accepted:    141.2K
 * Total Submissions: 266.9K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some
 * elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 * 
 * 
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
            while ((i + 1) != nums[i] && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);               
        for (int i = 0; i < nums.size(); ++i)
            if (i + 1 != nums[i]) ans.push_back(i + 1);
            
        return ans;
    }
};

