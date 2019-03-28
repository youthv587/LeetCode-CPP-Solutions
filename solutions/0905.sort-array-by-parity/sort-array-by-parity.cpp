/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 *
 * https://leetcode.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (72.28%)
 * Total Accepted:    76.5K
 * Total Submissions: 105.8K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array A of non-negative integers, return an array consisting of all
 * the even elements of A, followed by all the odd elements of A.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 * 
 * 
 * 
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> sortArrayByParity(vector<int> &A) {
        sort(A.begin(), A.end(), [](int &i, int &j) -> bool { return !(i % 2) && j % 2; });
        return A;
    }
};

