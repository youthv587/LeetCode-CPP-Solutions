/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 *
 * https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
 *
 * algorithms
 * Easy (43.67%)
 * Total Accepted:    37.8K
 * Total Submissions: 86.3K
 * Testcase Example:  '["c","f","j"]\n"a"'
 *
 *
 * Given a list of sorted characters letters containing only lowercase letters,
 * and given a target letter target, find the smallest element in the list that
 * is larger than the given target.
 *
 * Letters also wrap around.  For example, if the target is target = 'z' and
 * letters = ['a', 'b'], the answer is 'a'.
 *
 *
 * Examples:
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "a"
 * Output: "c"
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "c"
 * Output: "f"
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "d"
 * Output: "f"
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "g"
 * Output: "j"
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "j"
 * Output: "c"
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "k"
 * Output: "c"
 *
 *
 *
 * Note:
 *
 * letters has a length in range [2, 10000].
 * letters consists of lowercase letters, and contains at least 2 unique
 * letters.
 * target is a lowercase letter.
 *
 *
 */
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter( vector<char> &letters, char target )
    {
        auto iter = letters.begin();
        while ( iter != letters.end() && *iter <= target ) ++iter;
        return iter == letters.end() ? letters.front() : *iter;
    }
};
