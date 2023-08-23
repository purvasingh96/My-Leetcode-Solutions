// class MyCompare{
//  public:
//     bool operator()(const pair<char, int>& a, const pair<char, int>& b){
//         if(a.second == b.second) return 
//     }
// };
class Solution {
public:
    string reorganizeString(string s) {
        // reorganise high frequency chars first
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> m;
        for(auto x:s){
            m[x]+=1;
        }
        
        for(auto x:m){
            pq.push({x.second, x.first});
        }
        
        string res="";
        while(!pq.empty()){
            if(res.length()==0 || res.back()!=pq.top().second){
                res.push_back(pq.top().second);
                auto f = pq.top();pq.pop();
                f.first -=1;
                if(f.first!=0) pq.push(f);
            }  else {
                auto f = pq.top();pq.pop();
                if(pq.empty()) return "";
                res.push_back(pq.top().second);
                auto t = pq.top();pq.pop();
                t.first -=1;
                if(t.first!=0) pq.push(t);
                pq.push(f);
            }          
        }
        return res;
    }
};