class MovingAverage {
public:
    int capacity;
    double sum;
    deque<int> nums;
    MovingAverage(int size) {
        sum=0.0;
        capacity = size;
    }
    
    double next(int val) {
        if(nums.size() == capacity){
            sum-=nums[0];
            nums.pop_front();
        }
        nums.push_back(val);
        sum += val;
        int n = nums.size();
        double avg = (sum/n);
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */