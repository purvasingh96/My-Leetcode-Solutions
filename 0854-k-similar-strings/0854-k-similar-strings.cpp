class Solution {
public:
    int kSimilarity(string s1, string s2) {
        queue<pair<string, int>> q;
        q.push({s1, 0});
        unordered_set<string> seen;
        
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            string cur = f.first;
            int steps = f.second;
            
            if(f.first == s2) return f.second;
            
            int i=0;
            while(i<cur.length() && cur[i] == s2[i]) i+=1;
            
            for(int j=i+1;j<cur.length();j++){
                if(cur[j] == s2[i]){
                    swap(cur[j], cur[i]);
                    if(seen.find(cur) == seen.end()) {
                        q.push({cur, steps+1});
                        seen.insert(cur);
                    }
                    swap(cur[j], cur[i]);
                }
            }
        }
        return 0;
    }
};