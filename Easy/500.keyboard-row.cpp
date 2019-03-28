/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (61.82%)
 * Total Accepted:    84.3K
 * Total Submissions: 136.3K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 * 
 * 
 */
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> findWords(vector<string> &words) {
        vector<string> ans;
        map<char, int> map;
        vector<string> alphas = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        int row = 1;
        for (auto &str : alphas) {
            for (auto &ch : str) { map[ch] = row; }
            ++row;
        }

        for (auto &str : words) {
            bool flag = true;
            for (int i = 1; i < str.length(); ++i) {
                if (map[str[i]] != map[str[i - 1]]) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) ans.push_back(str);
        }
        return ans;
    }
};

