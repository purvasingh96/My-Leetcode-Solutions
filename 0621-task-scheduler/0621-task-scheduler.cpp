class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        unordered_map<char, int> m;
        for(auto c:tasks) m[c]+=1;
        for(auto x:m){
            pq.push(x.second);
        }
        
        int t=1;
        
        while(true){
            if(!q.empty() && q.front().second == t){
                pq.push(q.front().first);
                q.pop();
            }
            int f=0;
            if(!pq.empty()){
                f =pq.top();pq.pop();
                if(f-1>0) q.push({f-1, t+n+1});    
            }
            if(pq.empty() && q.empty()) return t;
            t+=1;
            
        }
        
        return t;
        
    }
};