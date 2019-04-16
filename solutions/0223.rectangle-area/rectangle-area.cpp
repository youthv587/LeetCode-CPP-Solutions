/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (35.64%)
 * Total Accepted:    85.3K
 * Total Submissions: 239.2K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 *
 *
 *
 * Example:
 *
 *
 * Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
 * Output: 45
 *
 * Note:
 *
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 *
 */
#include <cmath>

using namespace std;

class Solution {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int cover_area = (min(D, H) > max(B, F) ? (min(D, H) - max(B, F)) : 0) *
                         (min(C, G) > max(A, E) ? (min(C, G) - max(A, E)) : 0);
        return (D - B) * (C - A) - cover_area + (H - F) * (G - E);
    }
};
