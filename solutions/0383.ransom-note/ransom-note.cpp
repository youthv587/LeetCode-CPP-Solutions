/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (49.44%)
 * Total Accepted:    106.2K
 * Total Submissions: 214.7K
 * Testcase Example:  '"a"\n"b"'
 *
 *
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom
 * note can be constructed from the magazines ; otherwise, it will return
 * false.
 *
 *
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 *
 *
 * Note:
 * You may assume that both strings contain only lowercase letters.
 *
 *
 *
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 *
 *
 */
class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        int *s = (int *)calloc(26, sizeof(int));
        for (int i = 0; magazine[i] != '\0'; ++i) ++s[magazine[i] - 'a'];
        for (int i = 0; ransomNote[i] != '\0'; ++i) --s[ransomNote[i] - 'a'];
        for (int i = 0; i < 26; ++i)
            if (s[i] < 0) return false;
        return true;
    }
};
