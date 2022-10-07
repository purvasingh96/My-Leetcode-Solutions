class MyCalendarThree {
private:
    map<int, int> m;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        // sweep line
        m[start]+=1;
        m[end]-=1;
        int cur=0, k=1;
        for(auto x:m){
            cur+=x.second;
            k=max(k, cur);
        }
        
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */