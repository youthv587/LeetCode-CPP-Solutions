/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (51.86%)
 * Total Accepted:    359.8K
 * Total Submissions: 693.9K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
#include <map>
#include <vector>

using namespace std;

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        map<int, int> map;
        for (auto iter = nums.cbegin(); iter != nums.cend(); iter++)
            map[*iter]++;

        int max = 0, ans;
        for (auto iter = map.cbegin(); iter != map.cend(); iter++)
            if (iter->second > max) {
                max = iter->second;
                ans = iter->first;
            }
            
        return ans;
    }
};

