/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (51.33%)
 * Total Accepted:    314.1K
 * Total Submissions: 612K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t?, write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
#include <map>
#include <string>

using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
        map<char, int> map;
        for (auto &c : s) ++map[c];
        for (auto &c : t) --map[c];
        for (auto &p : map) if (p.second != 0) return false;
        return true;
    }
};

