/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Easy (58.67%)
 * Total Accepted:    26.5K
 * Total Submissions: 45.1K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * We should return its level order traversal:
 * 
 * 
 * [
 * ?    [1],
 * ?    [3,2,4],
 * ?    [5,6]
 * ]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The depth of the tree is at most 1000.
 * The total number of nodes is at most 5000.
 * 
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        if (root == nullptr) return {};

        int cnt;
        queue<Node *> queue;
        vector<int> tmp;
        vector<vector<int>> ans;

        queue.push(root);
        while (!queue.empty()) {
            cnt = queue.size();
            for (int i = 0; i < cnt; ++i) {
                tmp.push_back(queue.front()->val);
                for (auto &child : queue.front()->children) queue.push(child);
                queue.pop();
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};

