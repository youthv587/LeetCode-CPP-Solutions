/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (49.48%)
 * Total Accepted:    243K
 * Total Submissions: 491.2K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
#include <string>
#include <unordered_map>

using namespace std;

// class Solution_1 {
//   public:
//     int firstUniqChar(string s) {
//         unordered_map<char, int> map;
//         for (auto &c : s) ++map[c];
//         for (auto &c : s) if (map[c] == 1) return s.find_first_of(c);
//         return -1;
//     }
// };

class Solution {
  private:
    typedef struct {
        int pos;
        bool isRepeat;
    } data;

  public:
    int firstUniqChar(string s) {
        int ans = s.length();
        unordered_map<char, data> map;
        for (int i = 0; i < s.length(); ++i)
            if (map.find(s[i]) == map.end()) map.insert({s[i], {i, false}});
            else map[s[i]].isRepeat = true;
        for (auto &m : map) if (m.second.isRepeat == false && m.second.pos < ans)
            ans = m.second.pos;
        return ans == s.length() ? -1 : ans;
    }
};

