class MovingAverage {
public:
    int k;
    deque<int> cache;
    int sumSoFar;
    MovingAverage(int size) {
        k = size;
        sumSoFar =0;
    }
    
    double next(int val) {
        sumSoFar += val;
        cache.push_back(val);
        if(cache.size()>k){
            sumSoFar -= cache[0];
            cache.pop_front();
            return (double)sumSoFar/k;
        } else {
            return (double)sumSoFar/(cache.size());
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */