/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (45.01%)
 * Total Accepted:    236.1K
 * Total Submissions: 524.5K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer?numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ?    [1],
 * ?   [1,1],
 * ?  [1,2,1],
 * ? [1,3,3,1],
 * ?[1,4,6,4,1]
 * ]
 * 
 * 
 */
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<int> row1 = {1};
        vector<int> row2 = {1, 1};
        if (numRows == 0)
            return {};
        else if (numRows == 1)
            ans.push_back(row1);
        else {
            ans.push_back(row1);
            ans.push_back(row2);
            for (int i = 2; i < numRows; ++i) {
                tmp.push_back(1);
                for (int j = 1; j < i; ++j) {
                    tmp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
                tmp.push_back(1);
                ans.push_back(tmp);
                tmp.clear();
            }
        }
        return ans;
    }
};

