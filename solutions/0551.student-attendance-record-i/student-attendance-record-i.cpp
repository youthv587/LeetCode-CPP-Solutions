/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 *
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (45.16%)
 * Total Accepted:    49.4K
 * Total Submissions: 109.3K
 * Testcase Example:  '"PPALLP"'
 *
 * You are given a string representing an attendance record for a student. The
 * record only contains the following three characters:
 *
 *
 *
 * 'A' : Absent.
 * 'L' : Late.
 * ?'P' : Present.
 *
 *
 *
 *
 * A student could be rewarded if his attendance record doesn't contain more
 * than one 'A' (absent) or more than two continuous 'L' (late).
 *
 * You need to return whether the student could be rewarded according to his
 * attendance record.
 *
 * Example 1:
 *
 * Input: "PPALLP"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "PPALLL"
 * Output: False
 *
 *
 *
 *
 *
 */
#include <string>

using namespace std;

class Solution {
  public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        for (const auto &ch : s) {
            a += (ch == 'A');
            l = (ch == 'L') ? (l + 1) : 0;
            if (a > 1 || l > 2) return false;
        }
        return true;
    }
};
