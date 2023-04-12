class Solution {
private:
    vector<int> ps;
    vector<int> w;
public:
    Solution(vector<int>& w) {
        ps.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            ps.push_back(ps.back() + w[i]);
        }
        this->w=w;
    }
    
    int pickIndex() {
        int idx = rand()%(ps.back());
        auto it = upper_bound(ps.begin(), ps.end(), idx) - ps.begin();
        if(it == ps.size()) return ps.size()-1;
        return it;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */