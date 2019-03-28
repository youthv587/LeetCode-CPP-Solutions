/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (35.12%)
 * Total Accepted:    320.1K
 * Total Submissions: 911.5K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(),
             [](Interval &i, Interval &j) -> bool { return i.start < j.start; });
        for (auto &cur : intervals)
            if (ans.empty()) ans.push_back(cur);
            else if (ans.back().end >= cur.start)
                ans.back() = Interval(ans.back().start, cur.end > ans.back().end ? cur.end : ans.back().end);
            else ans.push_back(cur);
        return ans;
    }
};

