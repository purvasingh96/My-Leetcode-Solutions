class Solution {
public:
    vector<int> res;
    
    Solution(vector<int>& w) {
        res.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            res.push_back(w[i]+res.back());
        }
    }
    
    int pickIndex() {
        //for(auto x:res) cout<<x<<" ";
        int idx = rand()%(res.back());
        return upper_bound(res.begin(), res.end(), idx) - res.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */