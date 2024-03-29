/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 *
 * https://leetcode.com/problems/jewels-and-stones/description/
 *
 * algorithms
 * Easy (82.88%)
 * Total Accepted:    215K
 * Total Submissions: 259.5K
 * Testcase Example:  '"aA"\n"aAAbbbb"'
 *
 * You're given strings J representing the types of stones that are jewels, and
 * S representing the stones you have.? Each character in S is a type of stone
 * you have.? You want to know how many of the stones you have are also
 * jewels.
 * 
 * The letters in J are guaranteed distinct, and all characters in J and S are
 * letters. Letters are case sensitive, so "a" is considered a different type
 * of stone from "A".
 * 
 * Example 1:
 * 
 * 
 * Input: J = "aA", S = "aAAbbbb"
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: J = "z", S = "ZZ"
 * Output: 0
 * 
 * 
 * Note:
 * 
 * 
 * S and J will consist of letters and have length at most 50.
 * The characters in J are distinct.
 * 
 * 
 */
#include <algorithm>
#include <string>
using namespace std;

class Solution {
  public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        for (const char &c : J) { res += count(S.cbegin(), S.cend(), c); }
        return res;
    }
};

// class Solution_2 {
//   public:
//     int numJewelsInStones(string J, string S) {
//         int res = 0, j_len = J.length(), s_len = S.length();

//         for (int i = 0; i != j_len; ++i)
//             for (int j = 0; j != s_len; ++j)
//                 if (J[i] == S[j]) res++;

//         return res;
//     }
// };

