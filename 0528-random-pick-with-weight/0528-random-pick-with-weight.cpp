class Solution {
public:
    vector<int> res;
    Solution(vector<int>& w) {
        int sum=0;
        for(int i=0;i<w.size();i++){
            sum += w[i];
            res.push_back(sum);
        }
    }
    
    int pickIndex() {
        int low=0, high=res.back();
        int pivot = rand()%(res.back());
        int i = upper_bound(res.begin(), res.end(), pivot) - res.begin();
        //if(i == res.size()) return i-1;
        return i;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */