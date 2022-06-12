class Solution {
private:
    void back_track(int start, vector<int>& cookies, int k, vector<int>& res, int& minsum){
        if(start == cookies.size()){
            int maxsum = *max_element(res.begin(), res.end());
            minsum = min(minsum, maxsum);
            return;
        }
        
        for(int i=0;i<k;i++){
            res[i] += cookies[start];
            back_track(start+1, cookies, k, res, minsum);
            res[i] -= cookies[start];
        }
        
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> res(k,0);
        int minsum=INT_MAX;
        back_track(0, cookies, k, res, minsum);
        return minsum;
    }
};