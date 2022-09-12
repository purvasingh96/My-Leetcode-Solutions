class MyCompare{
public:
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a[1] > b[1];
    }    
};


class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<vector<int>> res;
        int mod = 1e9+7;
        
        for(int i=0;i<n;i++){
            res.push_back({e[i], s[i]});
        }
        
        // decreasing order of efficiency
        sort(res.begin(), res.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0];
        });
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        
        long long ans=INT_MIN, total_speed=0;
        
        for(auto x:res){
            if(pq.size() == k) {
                total_speed -= pq.top();
                pq.pop();
            }
            pq.push(x[1]);
            total_speed += x[1];
            ans = max(ans, (total_speed * x[0]));
            
        }
        
        return ans%mod;
        
    }
};