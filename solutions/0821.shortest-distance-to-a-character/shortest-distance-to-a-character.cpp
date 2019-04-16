/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 *
 * https://leetcode.pos/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (62.95%)
 * Total Accepted:    33.4K
 * Total Submissions: 53.1K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * Given a string S?and a character C, return an array of integers representing
 * the shortest distance from the character C in the string.
 *
 * Example 1:
 *
 *
 * Input: S = "loveleetcode", C = 'e'
 * Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 *
 *
 *
 *
 * Note:
 *
 *
 * S string length is?in?[1, 10000].
 * C?is a single character, and guaranteed to be in string S.
 * All letters in S and C are lowercase.
 *
 *
 */
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
  public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res;
        vector<int> pos = {-10001};
        for (size_t i = 0; i < S.length(); ++i) if (S[i] == C) pos.push_back(i);
        pos.push_back(10001);

        for (int i = 0; i < static_cast<int>(S.length()); ++i) {
            int j = 0;
            while (j < static_cast<int>(pos.size()) && i > pos[j]) ++j;
            res.push_back(min(i - pos[j - 1], pos[j] - i));
        }
        return res;
    }
};
