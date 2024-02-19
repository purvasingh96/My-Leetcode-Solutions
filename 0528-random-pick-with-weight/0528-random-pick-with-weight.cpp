class Solution {
public:
    vector<int> ps;
    Solution(vector<int>& w) {
        int sum=0;
        for(int i=0;i<w.size();i++){
            sum += w[i];
            ps.push_back(sum);
        }
    }
    
    int pickIndex() {
        int idx = rand()%(ps.back());
        
        auto it = upper_bound(ps.begin(), ps.end(), idx);
        return it - ps.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */