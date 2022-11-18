class MedianFinder {
private:
    int sz, l, r;
    multiset<int> nums;
    multiset<int>::iterator mid;
public:
    MedianFinder() {
        sz=0;
        mid=nums.begin();
    }
    
    void addNum(int num) {
        sz+=1;
        nums.insert(num);
        
        if(sz==1) mid=nums.begin();
        
        else if(num < *mid){
            mid = (sz%2!=0) ? mid : prev(mid);
        } else {
            mid = (sz%2!=0) ? next(mid) : mid;
        }
        
    }
    
    double findMedian() {
        if(sz%2==0){
            return (double)(*mid + *next(mid))*0.5;
        } else{
           return (double)(*mid); 
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */