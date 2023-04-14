class Solution {
public:
    string rearrangeString(string s, int k) {
        priority_queue<pair<int, char>> pq;
        queue<pair<pair<int, int>, char>> q;
        
        unordered_map<char, int> m;
        for(auto c:s) m[c]+=1;
        for(auto x:m){
            pq.push({x.second, x.first});
        }
        
        string res="";
        int i=0;
        while(true){
            // freq, index, char
            if(!q.empty() && q.front().first.second <= i){
                pq.push({q.front().first.first, q.front().second});
                q.pop();
            }
            
            bool found=false;
            if(!pq.empty()){
                auto f = pq.top();pq.pop();
                res.push_back(f.second);
                if(f.first-1>0) q.push({{f.first-1, i+k}, f.second});
                found=true;
            }
            
            if(res.length() == s.length()) return res;
            if(!found) return "";
            
            i+=1;
        }
        
        return res;
        
    }
};