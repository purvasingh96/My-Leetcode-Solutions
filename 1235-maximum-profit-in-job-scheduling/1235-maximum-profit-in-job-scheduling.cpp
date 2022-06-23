class Solution {
public:
    int memo[50001];
    int dfs(vector<vector<int>>& jobs, vector<int>& start, int n, int pos){
        if(pos>=n){
            return 0;
        }
        
        if(memo[pos]!=-1) return memo[pos];
        
        int next = lower_bound(start.begin(), start.end(), jobs[pos][1]) - start.begin();
        
        int skip = dfs(jobs, start, n, pos+1);
        int include = jobs[pos][2] + dfs(jobs, start, n, next);
        
        return memo[pos] = max(skip, include);
        
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        memset(memo, -1, sizeof(memo));
        
        for(int i=0;i<startTime.size();i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        for(int i=0;i<profit.size();i++){
            startTime[i] = jobs[i][0];
        }
        
        return dfs(jobs, startTime, profit.size(), 0);
    }
};