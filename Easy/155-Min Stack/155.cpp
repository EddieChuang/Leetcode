class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        stack = new int;
        size  = 0;
    }
    
    void push(int x) {
        if(size == 0)
        {
            stack[0] = x;
            ++size;
        }
        else
        {
            int *tmp = new int[size];
            for(int i = 0; i < size; ++i)
                tmp[i] = stack[i];
            
            delete stack;
            stack = new int[++size];
            for(int i = 0; i < size - 1; ++i)
                stack[i] = tmp[i];
            stack[size-1] = x;
            
            delete tmp;
        }
    }
    
    void pop() {
        
        if(size == 0)
            return;
        
        int *tmp = new int[--size];
        for(int i = 0; i < size; ++i)
            tmp[i] = stack[i];
        
        delete stack;
        stack = new int[size];
        for(int i = 0; i < size; ++i)
            stack[i] = tmp[i];
        
        delete tmp;
    }
    
    int top() {
        return stack[size - 1];
    }
    
    int getMin() {
        
        int mini = stack[0];
        for(int i = 0; i < size; ++i)
            mini = min(stack[i], mini);
        
        return mini;
    }
    
    int *stack;
    int size;
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */