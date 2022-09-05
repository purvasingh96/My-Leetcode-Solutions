class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        vector<long long> total_meetings(n, 0);
        vector<long long> ends(n, 0);
        sort(meetings.begin(), meetings.end());
        
        for(int i=0;i<meetings.size();i++){
            
            long long min_idx=-1;
            long long earliest_ending=1e18;
            bool found_unused =false;
            
            for(int j=0;j<n;j++){
                if(ends[j] <= meetings[i][0]) {
                    ends[j] = meetings[i][1];
                    found_unused = true;
                    total_meetings[j]+=1;
                    break;
                } 
                    if(ends[j] < earliest_ending) {
                        earliest_ending = ends[j];
                        min_idx=j;
                    }
            
            }
            
            if(!found_unused) {
                long long an = (1ll*(meetings[i][1] - meetings[i][0]));
                ends[min_idx] += an;
                total_meetings[min_idx] += 1;
            }
        }
        
        int res=-1, max_=0;
        for(int i=0;i<n;i++){
            if(total_meetings[i] > max_){
                max_=total_meetings[i];
                res=i;
            }
        }
        return res;
    }
};