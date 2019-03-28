/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (52.30%)
 * Total Accepted:    80.6K
 * Total Submissions: 154.1K
 * Testcase Example:  '"USA"'
 *
 * 
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 * 
 * 
 * 
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one
 * letter, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "USA"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * 
 * 
 * Note:
 * The input will be a non-empty word consisting of uppercase and lowercase
 * latin letters.
 * 
 */
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

class Solution {
  public:
    bool detectCapitalUse(string word) {
        string s = word;

        transform(word.begin(), word.end(), word.begin(),
                  [](char c) -> char { return tolower(c); });
        if (word == s) return true;

        transform(word.begin(), word.end(), word.begin(),
                  [](char c) -> char { return toupper(c); });
        if (word == s) return true;

        transform(word.begin() + 1, word.end(), word.begin() + 1,
                  [](char c) -> char { return tolower(c); });
        if (word == s) return true;

        return false;
    }
};

