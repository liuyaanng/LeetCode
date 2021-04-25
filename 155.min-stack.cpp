/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * <64;32;13M[155] 最小栈
 */

// @lc code=start
class MinStack {
	stack<int> s, min_s;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int val) {
			if(min_s.empty()){
				min_s.push(val);
			} else {
				if(val <= min_s.top()){
					min_s.push(val);
				}
			}

			s.push(val);
    }
    
    void pop() {
			if(!min_s.empty() && s.top() == min_s.top()){
				min_s.pop();
			}
			s.pop();
    }
    
    int top() {
			return s.top();

    }
    
    int getMin() {
			return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
