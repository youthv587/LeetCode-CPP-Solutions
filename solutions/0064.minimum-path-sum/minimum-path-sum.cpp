/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (46.34%)
 * Total Accepted:    222.3K
 * Total Submissions: 479.4K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 *
 *
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 *
 *
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        for (int i = 1; i < grid.front().size(); ++i)
            grid.front()[i] += grid.front()[i - 1];
        for (int i = 1; i < grid.size(); ++i)
            grid[i].front() += grid[i - 1].front();
        for (int i = 1; i < grid.size(); ++i)
            for (int j = 1; j < grid.front().size(); ++j)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        return grid.back().back();
    }
};
