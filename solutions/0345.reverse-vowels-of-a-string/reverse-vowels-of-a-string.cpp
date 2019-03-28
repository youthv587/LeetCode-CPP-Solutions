/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (41.02%)
 * Total Accepted:    146.7K
 * Total Submissions: 357.7K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */
#include <string>

using namespace std;

class Solution {
  public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i])) ++i;
            while (i < j && !isVowel(s[j])) --j;
            swap(s[i++], s[j--]);
        }
        return s;
    }

  private:
    bool isVowel(const char &ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
};

