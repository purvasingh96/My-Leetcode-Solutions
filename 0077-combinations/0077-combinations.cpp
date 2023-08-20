class Solution {
private:
    void backtrack(int start, int n, int k, vector<int>& temp, vector<vector<int>>& res){
        if(k == 0){
            res.push_back(temp);
            return;
        }
        
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            backtrack(i+1, n, k-1, temp, res);
            temp.pop_back();
        }
    } 
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;
        backtrack(1, n, k, temp, res);
        return res;
    }
};