/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (30.97%)
 * Total Accepted:    170.8K
 * Total Submissions: 550.9K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their
 * start times.
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 *
 */
// * Definition for an interval.
// struct Interval {
//     int start;
//     int end;
//     Interval() : start(0), end(0) {}
//     Interval(int s, int e) : start(s), end(e) {}
// };
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
  public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(),
             [](Interval &v1, Interval &v2) -> bool { return v1.start < v2.start; });
        for (const auto &interval : intervals) {
            if (res.size() == 0) res.push_back(interval);
            else {
                Interval last = res.back();
                if (last.end >= interval.start)
                    res.back() = Interval(last.start, last.end > interval.end
                                                          ? last.end
                                                          : interval.end);
                else res.push_back(interval);
            }
        }
        return res;
    }
};

