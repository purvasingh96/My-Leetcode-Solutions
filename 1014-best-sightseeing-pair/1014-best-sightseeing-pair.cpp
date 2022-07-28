class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        
        vector<int> right(n, 0);
        right[n-1] = values[n-1];
        
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1]-1, values[i+1]-1);
        }
        
        int res=INT_MIN;
        for(int i=0;i<n-1;i++){
            right[i]  = values[i] + right[i];
            res = max(res, right[i]);
        }
        return res;
    }
};