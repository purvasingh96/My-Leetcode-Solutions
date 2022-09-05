class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        vector<int> ans(n, 0);
        vector<long long> times(n, 0);
        sort(meetings.begin(), meetings.end());
        
        for(int i=0;i<meetings.size();i++){
            
            int min_idx=-1;
            long long val=1e18;
            bool found_unused =false;
            int start = meetings[i][0], end=meetings[i][1];
            
            for(int j=0;j<n;j++){
                if(times[j] <= start) {
                    times[j] = end;
                    found_unused = true;
                    ans[j]+=1;
                    break;
                } 
                    if(times[j] < val) {
                        val = times[j];
                        min_idx=j;
                    }
            
            }
            
            if(!found_unused) {
                times[min_idx] += (1ll*(end - start));
                ans[min_idx] += 1;
            }
        }
        
        int res=-1, max_=0;
        for(int i=0;i<n;i++){
            if(ans[i] > max_){
                max_=ans[i];
                res=i;
            }
        }
        return res;
    }
};