/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (40.50%)
 * Total Accepted:    44K
 * Total Submissions: 108.6K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 
 * The set S originally contains numbers from 1 to n. But unfortunately, due to
 * the data error, one of the numbers in the set got duplicated to another
 * number in the set, which results in repetition of one number and loss of
 * another number. 
 * 
 * 
 * 
 * Given an array nums representing the data status of this set after the
 * error. Your task is to firstly find the number occurs twice and then find
 * the number that is missing. Return them in the form of an array.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * 
 * 
 * 
 * Note:
 * 
 * The given array size will in the range [2, 10000].
 * The given array's numbers won't have any order.
 * 
 * 
 */
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        int sz = nums.size();
        vector<int>::iterator begin = nums.begin(), end = nums.end();

        int de = 0;
        for (int i = 0; i < sz; ++i) { de = de ^ nums[i] ^ (i + 1); }

        sort(begin, end);
        unique(begin, end);
        long as = accumulate(begin, --end, 0);
        long af = (sz * (sz + 1)) / 2;
        int re = static_cast<int>(af - as);

        return {re ^ de, re};
    }
};

