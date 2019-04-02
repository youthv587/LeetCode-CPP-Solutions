/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (53.87%)
 * Total Accepted:    187.1K
 * Total Submissions: 346.7K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Note:
 *
 *
 * You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 *
 *
 */
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> res;
        map<int, int> map;
        auto comp = [](pair<int, int> &p1, pair<int, int> &p2) -> bool { return p1.second < p2.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> queue(comp);
        for (const auto &n : nums) ++map[n];
        for (const auto &p : map) queue.push(make_pair(p.first, p.second));
        while (k--) {
            res.push_back(queue.top().first);
            queue.pop();
        }
        return res;
    }
};
