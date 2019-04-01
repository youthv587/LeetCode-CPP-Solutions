/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * https://leetcode.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (67.55%)
 * Total Accepted:    12.9K
 * Total Submissions: 19.3K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * Given an array?A of strings made only from lowercase letters, return a list
 * of all characters that show up in all strings within the list (including
 * duplicates).??For example, if a character occurs 3 times?in all strings but
 * not 4 times, you need to include that character three times?in the final
 * answer.
 *
 * You may return the answer in any order.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: ["bella","label","roller"]
 * Output: ["e","l","l"]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: ["cool","lock","cook"]
 * Output: ["c","o"]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] is a lowercase letter
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
    vector<string> commonChars(vector<string> &A) {
        const int nalpha = 26;
        vector<string> res;
        vector<int> last(nalpha, 100), curr(nalpha, 0);
        for (const auto &str : A) {
            for (const auto &ch : str) ++curr[ch - 'a'];
            for (int i = 0; i < nalpha; ++i) last[i] = last[i] > curr[i] ? curr[i] : last[i];
            transform(curr.begin(), curr.end(), curr.begin(), [](int i) -> int { return 0; });
        }
        for (int i = 0; i < nalpha; ++i) while (last[i]-- > 0) res.push_back(string(1, i + 'a'));
        return res;
    }
};
