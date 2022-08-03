class MyCalendar {
private:
    vector<vector<int>> q;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //cout<<start<<" "<<end<<"\n";
        if(q.empty() || q.back()[1] <= start){
            q.push_back({start, end});
            //cout<<"true\n";
            return true;
        } else{
            
            int left=0, right=q.size()-1;
            
            while(left<right){
                int mid = left + (right-left)/2;
                if(q[mid][0]>start){
                    right=mid;
                } else {
                    left=mid+1;
                }
            }
            
            if(left==0){
                
                if(start<q[left][0] && end<=q[left][0]){
                    q.insert(q.begin()+left, {start, end});
                    return true;
                }
                
            } else if(left>=1){
                if(start >= q[left-1][1] && end <= q[left][0]){
                    q.insert(q.begin()+left, {start, end});
                    return true;
                }
            }
            
        }
        //cout<<"false\n";
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */