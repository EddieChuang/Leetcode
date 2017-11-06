class MyQueue {
public:
    
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
        stack<int> tmp;
        for(; !q.empty(); q.pop())
            tmp.push(q.top());
        
        q.push(x);
        
        for(; !tmp.empty(); tmp.pop())
           q.push(tmp.top());
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        int ret = q.top();
        q.pop();
        
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        return q.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q.empty();
    }
    
private:
    stack<int> q;
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */