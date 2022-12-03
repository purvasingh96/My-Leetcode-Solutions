class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(auto c:s) m[c] +=1;
        
        priority_queue<pair<int, char>> pq;
        
        for(auto c:m){
            pq.push({c.second, c.first});
        }
        
        string res="";
        
        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            
            int count = f.first, alpha = f.second;
            
            string temp(count, alpha);
            res += temp;
        }
        
        return res;
        
    }
};