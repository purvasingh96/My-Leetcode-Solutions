class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> count(n, 0);
        vector<long long> ends(n, 0);
        
        for(int i=0;i<meetings.size();i++){
            int start = meetings[i][0], end=meetings[i][1];
            bool found=false;
            
            for(int i=0;i<n;i++){
                if(ends[i] <= start){
                    count[i]+=1;
                    ends[i] = end;
                    found=true;
                    break;
                }
            } 
            
            if(!found){
                int idx = min_element(ends.begin(), ends.end()) - ends.begin();
                count[idx]+=1;
                ends[idx] += (end-start);
            }
            // for(auto x:count) cout<<x<<" ";
            // cout<<"\n";
        }
        
        
        
        return max_element(count.begin(), count.end()) - count.begin();
        
    }
};