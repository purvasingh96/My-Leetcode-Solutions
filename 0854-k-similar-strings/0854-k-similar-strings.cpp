class Solution {
public:
    int kSimilarity(string s1, string s2) {
        queue<pair<string, int>> q;
        q.push({s1, 0});
        unordered_set<string> seen;
        
        while(!q.empty()){
            
            auto f = q.front();
            q.pop();
            
            string curr = f.first;
            int steps = f.second;
            
            
            if(curr == s2) return steps;
            
            int i=0;
            while(i<s1.length() && curr[i] == s2[i]) i++;
            
            for(int j=i+1;j<s1.length();j++){
                if(curr[j] == s2[i]){
                    swap(curr[j], curr[i]);
                    if(seen.find(curr)==seen.end()) {
                        q.push({curr, steps+1});
                        seen.insert(curr);
                    }
                    swap(curr[j], curr[i]);
                }
            }
            
            
        }
        
        return 0;
        
    }
};