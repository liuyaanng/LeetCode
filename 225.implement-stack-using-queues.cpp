/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
	queue<int> q1, q2; 
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    /** Push element x onto stack. */
    void push(int x) {
			if(q1.empty()){
				q1.push(x);
			} else {
				q2.push(x);
				q1toq2_and_swap(q1, q2);
			}
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
			int x = q1.front();
			q1.pop();
			return x;
    }
    
    /** Get the top element. */
    int top() {
			return q1.front();
    }
    
		void q1toq2_and_swap(queue<int>& q1, queue<int>& q2){
			while(!q1.empty()){
				int x = q1.front();
				q1.pop();
				q2.push(x);
			}
			while(!q2.empty()){
				int y = q2.front();
				q2.pop();
				q1.push(y);
			}
		}
    /** Returns whether the stack is empty. */
    bool empty() {
			return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
