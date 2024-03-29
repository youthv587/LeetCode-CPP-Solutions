/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 *
 * https://leetcode.com/problems/maximize-distance-to-closest-person/description/
 *
 * algorithms
 * Easy (40.45%)
 * Total Accepted:    29.3K
 * Total Submissions: 72K
 * Testcase Example:  '[1,0,0,0,1,0,1]'
 *
 * In a row of seats, 1 represents a person sitting in that seat, and 0
 * represents that the seat is empty. 
 *
 * There is at least one empty seat, and at least one person sitting.
 *
 * Alex wants to sit in the seat such that the distance between him and the
 * closest person to him is maximized. 
 *
 * Return that maximum distance to closest person.
 *
 *
 * Example 1:
 *
 *
 * Input: [1,0,0,0,1,0,1]
 * Output: 2
 * Explanation:
 * If Alex sits in the second open seat (seats[2]), then the closest person has
 * distance 2.
 * If Alex sits in any other open seat, the closest person has distance 1.
 * Thus, the maximum distance to the closest person is 2.
 *
 *
 * Example 2:
 *
 *
 * Input: [1,0,0,0]
 * Output: 3
 * Explanation:
 * If Alex sits in the last seat, the closest person is 3 seats away.
 * This is the maximum distance possible, so the answer is 3.
 *
 *
 * Note:
 *
 *
 * 1 <= seats.length <= 20000
 * seats contains only 0s or 1s, at least one 0, and at least one 1.
 *
 *
 *
 *
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest( vector<int> &seats )
    {
        int maxzero = 0, dis = 0, lzero, rzero, i, j;
        for ( i = 0, lzero = 0; i < seats.size() && seats[ i ] == 0; ++i, ++lzero ) ;
        for ( j = seats.size() - 1, rzero = 0; j >= 0 && seats[ j ] == 0; --j, ++rzero ) ;
        while ( i <= j ) {
            if ( seats[ i++ ] == 0 ) ++dis;
            else {
                maxzero = maxzero < dis ? dis : maxzero;
                dis = 0;
            }
        }
        return max( ( maxzero + 1 ) / 2, max( lzero, rzero ) );
    }
};
