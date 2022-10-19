class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for(auto x:words) m[x]+=1;
        vector<string> ans;
        vector<pair<int, string>> res;
        
        priority_queue<pair<int, string>> pq;
        
        for(auto x:m){
            pq.push({-x.second, x.first});
            if(pq.size() > k) pq.pop();
        }
        
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        
        sort(res.begin(), res.end());
        for(auto x:res) ans.push_back(x.second);
        
        return ans;
        
    }
};