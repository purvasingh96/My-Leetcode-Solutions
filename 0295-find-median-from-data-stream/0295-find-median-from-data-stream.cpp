class MedianFinder {
public:
    multiset<int> low, high;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        low.insert(num);
        high.insert(*low.rbegin());
        low.erase(prev(low.end()));
        
        if(high.size() > low.size()){
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }
    
    double findMedian() {
        int sz = low.size() + high.size();
        if(sz%2==0){
            return (double)((double)(*low.rbegin()) + (double)(*high.begin())) * 0.5;
        } else {
            return (double)(*low.rbegin());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */