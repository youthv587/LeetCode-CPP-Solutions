/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (47.04%)
 * Total Accepted:    186.1K
 * Total Submissions: 395.5K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 *
 *
 * Note:
 *
 *
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 *
 *
 * Follow up:
 *
 *
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 *
 *
 */
#include <map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> ans;
        map<int, int> map;
        for (const auto &n : nums1) ++map[n];
        for (const auto &n : nums2) {
            if (map.find(n) != map.end()) {
                --map[n];
                if (map[n] == 0) map.erase(n);
                ans.push_back(n);
            }
        }
        return ans;
    }
};
