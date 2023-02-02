class SummaryRanges {
private:
    set<vector<int>> res;
    int upperBound(int value, set<vector<int>>& res){
        int n = res.size();
        int idx = n, ans=n;
        
        int s = 0, e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            vector<int> temp = *next(res.begin(), mid);
            if(temp[0] >= value) {
                ans=mid;
                e=mid-1;
            } else {
                s=mid+1;
            }
        }
        
        return ans;
        
    }
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        int idx = upperBound(value, res);
        int n = res.size();
        
        cout<<idx<<"\n";
        
        if(res.size() == 0){
            res.insert({value, value});
        }
        
        else if(idx == n){
            vector<int> back = *prev(res.end());
            if(value - back[1] <= 1){
                res.erase((prev(res.end())));
                res.insert({min(back[0], value), max(back[1], value)});
            } else {
                res.insert({value, value});
            }
        } else if(idx == 0){
            
            vector<int> front = *(res.begin());
            if(front[0] - value<=1){
                res.erase(res.begin());
                res.insert({min(value, front[0]), max(value, front[1])});
            } else {
                res.insert({value, value});
            }
            
        } else {
            
            //res.insert({value, value});
            vector<int> mid = *next(res.begin(), idx);
            vector<int> prev_mid = *next(res.begin(), idx-1);
            
            //cout<<"mid[0]: "<<mid[0]<<" new_mid[0]: "<<prev_mid[0]<<"\n";
            
            if( (mid[0] - value <= 1) || (value - prev_mid[1]<=1) ){
                
                if(mid[0] - value<=1){
                    res.erase(next(res.begin(), idx));
                    mid = {min(value, mid[0]), max(value, mid[1])};
                    
                } else {
                    mid = {value, value};
                }
                
                res.insert(mid);

                if(value-prev_mid[1] <=1){
                    res.erase(next(res.begin(), idx));
                    res.erase(next(res.begin(), idx-1));
                    res.insert({min(prev_mid[0], mid[0]), max(prev_mid[1], mid[1])});
                }
            }
            
            
           else {
               res.insert({value, value});
           }
            
        }
        
                
    }
    
    vector<vector<int>> getIntervals() {
        return vector<vector<int>>(res.begin(), res.end());
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */