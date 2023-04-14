class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        queue<pair<pair<int, int>, char>> q;
        unordered_map<char, int> m;
        for(auto c:s) m[c]+=1;
        for(auto x:m){
            pq.push({x.second, x.first});
        }
        
        int len = s.length();
        string res="";
        int n = 1;
        int i=0;
        while(true){
            if(!q.empty() && q.front().first.second == i){
                pq.push({q.front().first.first, q.front().second});
                q.pop();
            }
            bool found=false;
            if(!pq.empty()){
                auto f = pq.top();pq.pop();
                if(f.first-1>0) q.push({{f.first-1, i+n+1}, f.second});
                res.push_back(f.second);
                found=true;
            }
            
            //cout<<"res: "<<res<<"\n";
            if(!found) return "";
            if(res.length() == len) return res;
            i+=1;
        }
        return res;
        
    }
};