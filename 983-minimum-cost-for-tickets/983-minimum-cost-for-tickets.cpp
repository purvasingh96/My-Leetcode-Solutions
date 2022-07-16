class Solution {
private:
    int binarysearch(int start, int end, int target, vector<int>& days){
        //if(target > days.back()) return -1;
        while(start<end){
            int mid = start + (end-start)/2;
            if(days[mid] > target){
                    end=mid;
            } else{
                start=mid+1;
            }
        }
        
        if(start<days.size() && days[start] <= target) return -1;
        return start;
    }
    
    
    int dfs(int i, vector<int>& days, vector<int>& costs, vector<int>& buffer, vector<int>& dp){
        if(i==-1) return 0;
        if(i>=days.size()) {
            return 0;
        }
        
        if(dp[i]!=-1) return dp[i];
        
        int mincost = INT_MAX;
        
        for(int j=0;j<3;j++){
                
            int new_day = days[i] + buffer[j];
            
            int new_i = binarysearch(i+1, days.size()-1, new_day, days);

            
            mincost = min(mincost, costs[j]+dfs(new_i, days, costs, buffer, dp));
            
            
        }
        
        return dp[i] = mincost;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> buffer(3);
        buffer[0] =0;
        buffer[1] = 6;
        buffer[2] = 29;
        vector<int> dp(n, -1);
        
        return dfs(0, days, costs, buffer, dp);
        
    }
};