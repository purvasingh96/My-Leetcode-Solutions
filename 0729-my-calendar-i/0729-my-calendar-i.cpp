class MyCalendar {
private:
    vector<vector<int>> res;
    int bs(int target, vector<vector<int>>& res){
        int l=0, r=res.size()-1;
        int ans=-1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(res[mid][0]>=target){
                ans=mid;
                r=mid-1;
            } else {
                l = mid+1;
            }   
        }
        
        return ans;
    }
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        /*
            it is end: push_back
            it is beginning: insert at 0th pos
            it is bw 0-n: check
        
        */
        
        vector<int> target = {start, end};
        
        if(res.empty()){
            res.push_back(target);
            return true;
        }
        int it = bs(start, res);
        
        
        if(it==-1){
            if(start >= res.back()[1]){
                res.push_back(target);
                return true;
            } 
            return false;
            
        } 
        else if(it == 0){
            if(end <= res[0][0]) {
                res.insert(res.begin()+it, target);
                return true;
            }
            return false;
        } 
        else{
            
            if(res[it][0] >= end && res[it-1][1]<=start){
                res.insert(res.begin()+it, target);
                return true;
            } else return false;
            
        }
        
        
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */