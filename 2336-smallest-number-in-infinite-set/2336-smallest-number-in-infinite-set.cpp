class SmallestInfiniteSet {
private:
    vector<bool> live;
    priority_queue<int,vector<int>, greater<int>> pq;
public:
    SmallestInfiniteSet() {
        live.resize(1001, true);
        for(int i=1;i<=1000;i++){
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int top = pq.top();
        live[top]=false;
        pq.pop();
        return top;
        
    }
    
    void addBack(int num) {
        if(live[num]==false) {
            live[num]=true;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */