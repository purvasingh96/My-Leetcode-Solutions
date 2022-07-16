class Solution {
private:
    void dfs(int idx, int target, vector<int>& temp, vector<vector<int>>& ans, vector<int>& arr){
        
        if(target ==0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<arr.size();i++){
            
            if(i>idx && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            
            temp.push_back(arr[i]);
            dfs(i+1, target-arr[i], temp, ans, arr);
            temp.pop_back();
            
        }
            
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int> temp;
        vector<vector<int>> ans;
        dfs(0, target, temp, ans, arr);
        return ans;
    }
};