class MovingAverage {
private:
    queue<int> q;
    int n;
    int prefix_sum=0;
    
public:
    MovingAverage(int size) {
        n = size;
        prefix_sum=0;
    }
    
    double next(int val) {
        q.push(val);
        prefix_sum += val;
        if(q.size()>n) {
            int front = q.front();
            prefix_sum -= front;
            q.pop();
        }
        
        return (double)prefix_sum/q.size();
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */