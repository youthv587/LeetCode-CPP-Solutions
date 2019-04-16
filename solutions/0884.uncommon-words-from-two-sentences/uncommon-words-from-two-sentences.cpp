/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 *
 * https://leetcode.com/problems/uncommon-words-from-two-sentences/description/
 *
 * algorithms
 * Easy (60.55%)
 * Total Accepted:    26.6K
 * Total Submissions: 44K
 * Testcase Example:  '"this apple is sweet"\n"this apple is sour"'
 *
 * We are given two sentences A and B.? (A sentence?is a string of space
 * separated words.? Each word consists only of lowercase letters.)
 *
 * A word is uncommon?if it appears exactly once in one of the sentences, and
 * does not appear in the other sentence.
 *
 * Return a list of all uncommon words.?
 *
 * You may return the list in any order.
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: A = "this apple is sweet", B = "this apple is sour"
 * Output: ["sweet","sour"]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: A = "apple apple", B = "banana"
 * Output: ["banana"]
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= A.length <= 200
 * 0 <= B.length <= 200
 * A and B both contain only spaces and lowercase letters.
 *
 *
 *
 *
 */
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    /**
        vector<string> uncommonFromSentences(string A, string B) {
            vector<string> res;
            map<string, int> ma, mb;
            for (const auto &s : split(A)) ++ma[s];
            for (const auto &s : split(B)) ++mb[s];
            for (const auto &ps : ma) if (ps.second == 1 && mb[ps.first] == 0) res.push_back(ps.first);
            for (const auto &ps : mb) if (ps.second == 1 && ma[ps.first] == 0) res.push_back(ps.first); 
            return res;
        }
    **/
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> res;
        map<string, int> m;
        A += " " + B;
        for (const auto &s : split(A)) ++m[s];
        for (const auto &ps : m) if (ps.second == 1) res.push_back(ps.first);
        return res;
    }

  private:
    vector<string> split(string str) {
        vector<string> res;
        string s;
        bool in = false;
        for (const auto &ch : str) {
            if (ch == ' ') {
                if (in) res.push_back(s);
                s.clear();
                in = false;
                continue;
            } else {
                s.push_back(ch);
                in = true;
            }
        }
        if (in) res.push_back(s);
        return res;
    }
};
