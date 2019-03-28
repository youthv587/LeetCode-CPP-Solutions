/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (48.02%)
 * Total Accepted:    40.5K
 * Total Submissions: 84.4K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 * 
 */
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> findRelativeRanks(vector<int> &nums) {
        vector<pair> pairs;
        vector<string> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) pairs.push_back({i, nums[i]});
        sort(pairs.begin(), pairs.end(), [](pair &p1, pair &p2) -> bool { return p1.num > p2.num; });
        for (int i = 0; i < pairs.size(); ++i) {
            if (i >= 3) ans[pairs[i].pos] = to_string(i + 1);
            else if (i == 2) ans[pairs[i].pos] = "Bronze Medal";
            else if (i == 1) ans[pairs[i].pos] = "Silver Medal";
            else ans[pairs[i].pos] = "Gold Medal";
        }
        return ans;
    }

  private:
    struct pair {
        int pos;
        int num;
    };
};

