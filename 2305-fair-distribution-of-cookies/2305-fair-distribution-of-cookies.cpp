class Solution {
private:
    void backtrack(int i, vector<int>& cookies, vector<int>& values, int& minSum){
        
        if(i == cookies.size()){
            // calculate min Sum
            int maxSum = *max_element(values.begin(), values.end());
            minSum = min(minSum, maxSum);
            return;
        }
        
        
        for(int j=0;j<values.size();j++){
            values[j] += cookies[i];
            backtrack(i+1, cookies, values, minSum);
            values[j] -= cookies[i];
        }
        
        
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> values(k, 0);
        int minSum = INT_MAX;
        backtrack(0, cookies, values, minSum);
        return minSum;
    }
};