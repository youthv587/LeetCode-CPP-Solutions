/*
 * @lc app=leetcode id=836 lang=cpp
 *
 * [836] Rectangle Overlap
 *
 * https://leetcode.com/problems/rectangle-overlap/description/
 *
 * algorithms
 * Easy (46.02%)
 * Total Accepted:    21.7K
 * Total Submissions: 47.1K
 * Testcase Example:  '[0,0,2,2]\n[1,1,3,3]'
 *
 * A rectangle is?represented as a?list [x1, y1, x2, y2], where?(x1, y1)?are
 * the coordinates of its bottom-left corner, and (x2,?y2)?are the coordinates
 * of its top-right corner.
 *
 * Two rectangles overlap if the area of their intersection is positive.? To be
 * clear, two rectangles that only touch at the corner or edges do not
 * overlap.
 *
 * Given two (axis-aligned) rectangles, return whether?they overlap.
 *
 * Example 1:
 *
 *
 * Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
 * Output: false
 *
 *
 * Notes:
 *
 *
 * Both rectangles rec1 and rec2 are lists of 4 integers.
 * All coordinates in rectangles will be between?-10^9 and 10^9.
 *
 *
 */
#include <vector>

using namespace std;

class Solution {
  public:
    bool isRectangleOverlap(vector<int> &A, vector<int> &B) {
        return (long)(A[2] - B[0]) * (B[2] - A[0]) > 0 &&
               (long)(A[3] - B[1]) * (B[3] - A[1]) > 0;
    }
};
