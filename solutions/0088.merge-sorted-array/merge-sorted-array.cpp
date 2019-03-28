/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (35.14%)
 * Total Accepted:    341.4K
 * Total Submissions: 971.7K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output:?[1,2,2,3,5,6]
 * 
 * 
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    void merge(vector<int> &v1, int m, vector<int> &v2, int n) {
        for (int i = m, j = 0; i < m + n; ++i, ++j) v1[i] = v2[j];
        sort(v1.begin(), v1.begin() + m + n);
    }
};
