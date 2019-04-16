/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (49.05%)
 * Total Accepted:    55.7K
 * Total Submissions: 113.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array of size n, find the minimum number of moves
 * required to make all array elements equal, where a move is incrementing n -
 * 1 elements by 1.
 *
 * Example:
 *
 * Input:
 * [1,2,3]
 *
 * Output:
 * 3
 *
 * Explanation:
 * Only three moves are needed (remember each move increments two elements):
 *
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 *
 *
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves( vector<int> &nums )
    {
        int res = 0, min = *min_element( nums.cbegin(), nums.cend() );
        for ( const auto &n : nums ) res += n - min;
        return res;
    }
};
