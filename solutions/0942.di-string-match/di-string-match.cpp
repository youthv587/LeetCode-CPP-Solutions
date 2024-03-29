/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 *
 * https://leetcode.com/problems/di-string-match/description/
 *
 * algorithms
 * Easy (70.07%)
 * Total Accepted:    24.8K
 * Total Submissions: 35.4K
 * Testcase Example:  '"IDID"'
 *
 * Given a string S that only contains "I" (increase) or "D" (decrease), let N
 * = S.length.
 *
 * Return any permutation A of [0, 1, ..., N] such that for all i = 0, ...,
 * N-1:
 *
 *
 * If S[i] == "I", then A[i] < A[i+1]
 * If S[i] == "D", then A[i] > A[i+1]
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "IDID"
 * Output: [0,4,1,3,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "III"
 * Output: [0,1,2,3]
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "DDI"
 * Output: [3,2,0,1]
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= S.length <= 10000
 * S only contains characters "I" or "D".
 *
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        int i = 0, d = S.length();
        for (const auto &ch : S) res.push_back(ch == 'I' ? i++ : d--);
        res.push_back(i);
        return res;
    }
};
