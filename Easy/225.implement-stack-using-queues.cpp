/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 *
 * https://leetcode.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (38.38%)
 * Total Accepted:    122.7K
 * Total Submissions: 319.8K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a stack using queues.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * 
 * 
 * Example:
 * 
 * 
 * MyStack stack = new MyStack();
 * 
 * stack.push(1);
 * stack.push(2);  
 * stack.top();   // returns 2
 * stack.pop();   // returns 2
 * stack.empty(); // returns false
 * 
 * Notes:
 * 
 * 
 * You must use only standard operations of a queue -- which means only push to
 * back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may
 * simulate a queue by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top
 * operations will be called on an empty stack).
 * 
 * 
 */
#include <queue>

class MyStack {
  private:
    std::queue<int> q1, q2;

    static int getAfterPour(std::queue<int> &, std::queue<int> &);

  public:
    MyStack() {}

    void push(int x) { q2.empty() ? q1.push(x) : q2.push(x); }

    int pop() { return q2.empty() ? getAfterPour(q1, q2) : getAfterPour(q2, q1); }

    int top() { return q2.empty() ? q1.back() : q2.back(); }

    bool empty() { return q1.empty() && q2.empty(); }
};

int MyStack::getAfterPour(std::queue<int> &q1, std::queue<int> &q2) {
    while (q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
    }
    int t = q1.front();
    q1.pop();
    return t;
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

