class Solution {
private:
    bool dfs(int i, vector<bool>& visited, vector<int>& ms, int cur_sum, int target, int k){
        
        if(k==1) return true;
        
        if(i>=ms.size()) return false;
        
        if(cur_sum == target) {
            return dfs(0, visited, ms, 0, target, k-1);
        }
        
        for(int j=i;j<ms.size();j++){
            
            if(visited[j] || cur_sum+ms[j] > target) continue;
            
            visited[j] = true;
            
            if(dfs(j+1, visited, ms, cur_sum+ms[j], target, k)){
                return true;
            }
            
            visited[j] = false;
        }
        
        return false;
    }
public:
    bool makesquare(vector<int>& ms) {
        sort(ms.begin(), ms.end(), greater<int>());
        vector<bool> visited((int)ms.size(), false);
        int sum = accumulate(ms.begin(), ms.end(), 0);
        
        if(sum%4!=0) return false;
        
        int target = sum/4;
        
        return dfs(0, visited, ms, 0, target, 4);
    }
};