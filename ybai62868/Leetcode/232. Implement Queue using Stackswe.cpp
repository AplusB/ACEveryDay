class Queue {
    stack<int>s1;
    stack<int>s2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        this->peek();
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if ( !s2.empty() ) return s2.top();
        while ( !s1.empty() ){
            int tmp = s1.top();
            s2.push(tmp);
            s1.pop();
        }
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (s1.empty()&&s2.empty());
    }
};
