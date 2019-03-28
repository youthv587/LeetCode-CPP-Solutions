/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (34.88%)
 * Total Accepted:    188K
 * Total Submissions: 538.9K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * 
 * 
 */
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) != map.end() &&
                abs(map.find(nums[i])->second - i) <= k)
                return true;
            else
                map[nums[i]] = i;
        }
        return false;
    }
};

