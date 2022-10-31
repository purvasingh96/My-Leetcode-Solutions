class MyCalendarTwo {
private:
    map<int, int> m;
public:
    bool canAdd(){
        int sum=0;
        
        //for(auto x:m) cout<<x.first<<"=>"<<x.second<<"\n";
        
        for(auto it:m){
            sum += it.second;
            if(sum == 3) return false;
        }
        return true;
    }
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        m[start]+=1;
        m[end]-=1;
        bool ans = canAdd();
        
        if(!canAdd()) {
            m[start]-=1;
            m[end]+=1;
        }
        
//         cout<<"\nans: "<<ans;
//         cout<<"\n=====\n";
        return ans;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */