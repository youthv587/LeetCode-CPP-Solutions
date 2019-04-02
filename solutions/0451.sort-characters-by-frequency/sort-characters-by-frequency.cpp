/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (55.33%)
 * Total Accepted:    87.3K
 * Total Submissions: 157.6K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 *
 * Example 1:
 *
 * Input:
 * "tree"
 *
 * Output:
 * "eert"
 *
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * "cccaaa"
 *
 * Output:
 * "cccaaa"
 *
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 *
 *
 *
 * Example 3:
 *
 * Input:
 * "Aabb"
 *
 * Output:
 * "bbAa"
 *
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 *
 *
 */
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
  public:
    string frequencySort(string s) {
        string order, res;
        map<char, int> map;
        for (const auto &ch : s) ++map[ch];
        for (const auto &p : map) order.push_back(p.first);
        sort(order.begin(), order.end(), [&](char &ch1, char &ch2) { return map[ch1] > map[ch2]; });
        for (const auto &ch : order)
            while (map[ch]--) res.push_back(ch);
        return res;
    }
};
