class Solution {
public:
    char findTheDifference(string s, string t) {
       unordered_map<int, int> m;
        for(auto c:s){
            m[c]+=1;
        }
        
        for(auto c:t){
            m[c]-=1;
            if(m[c]==0) m.erase(c);
        }
        
        return m.begin()->first;
    }
};