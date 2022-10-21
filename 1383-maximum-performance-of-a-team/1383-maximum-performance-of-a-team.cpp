# define pp pair<int,int>

class MyCompare{
public:
    bool operator()(const pp& a, const pp& b){
        return a.second >= b.second;
    }
};

class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        // speed, efficiency
        int mod = 1e9+7;
        vector<pp> res;
        for(int i=0;i<n;i++){
            res.push_back({e[i], s[i]});
        }
        
        sort(res.begin(), res.end(), [](const pp& a, const pp& b){
            return a.first > b.first;
        });
        
        priority_queue<int, vector<int>, greater<int>> is;
        
        long sum=0;
        int mineff=INT_MAX;
        long maxPerf = INT_MIN;
        
        
        for(int i=0;i<n;i++){
            
            is.push(res[i].second);
            sum += res[i].second;
            
            if(is.size() > k){
                int top = is.top();
                is.pop();
                sum -= top;
            }
            
            long currPerf = res[i].first * sum;
            maxPerf = max(maxPerf, currPerf);
            
        }
        
        return maxPerf%mod;
        
    }
};