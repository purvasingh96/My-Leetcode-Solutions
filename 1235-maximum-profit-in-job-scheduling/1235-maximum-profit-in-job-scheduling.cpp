# define pp pair<pair<int,int>, int>
class Solution {
private:
    int binary_search(vector<pp>& res, int start, int target){
        int l=start, r=res.size()-1;
        int idx = -1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(res[mid].first.first >= target){
                idx = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return idx;
        
    }
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<pp> res;
        int n = s.size();
        vector<int> dp(n, 0);
        
        for(int i=0;i<s.size();i++){
            res.push_back({{s[i], e[i]}, p[i]});
        }
        sort(res.begin(), res.end(), [](const pp& a, const pp& b){
            auto x = a.first;
            auto y = b.first;
            
            if(x.first == y.first) return x.second < y.second;
            return x.first < y.first;
            
        });
        
        
        dp[n-1] = res.back().second;
        
        for(int i=n-2;i>=0;i--){
            
            int end = res[i].first.second;
            int idx = binary_search(res, i+1, end);
            
            if(idx!=-1){
                dp[i] = res[i].second + dp[idx];
                dp[i] = max(dp[i+1], dp[i]);
            } else {
                dp[i] += max(res[i].second, dp[i+1]);
            }
            
        }
        
        return dp[0];
        
    }
};