class Solution {
public:
    vector<int> prefixSum;
    Solution(vector<int>& w) {
        int sum=0;
        for(auto x:w){
            sum+=x;
            prefixSum.push_back(sum);
        }
    }
    
    int pickIndex() {
        int x = rand()%(prefixSum.back());
        int y = upper_bound(prefixSum.begin(), prefixSum.end(), x) - prefixSum.begin();
        return y;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */