/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (36.10%)
 * Total Accepted:    279.3K
 * Total Submissions: 773.6K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */
#include <vector>

using namespace std;

class MinStack {
    typedef struct {
        int data;
        int min;
    } Elem;

  private:
    vector<Elem> stack;
    int cur;

  public:
    /** initialize your data structure here. */
    MinStack() { cur = -1; }

    void push(int x) {
        if (cur == -1)
            stack.push_back({x, x});
        else
            stack.push_back({x, ((x < stack[cur].min) ? x : stack[cur].min)});
        cur++;
    }

    void pop() {
        stack.pop_back();
        cur--;
    }

    int top() { return stack.back().data; }

    int getMin() { return stack.back().min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

