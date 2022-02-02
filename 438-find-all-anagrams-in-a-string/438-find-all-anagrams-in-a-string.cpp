class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> m;
        map<char, int> t;
        vector<int> res;
        
        
        for(auto c:p) {
            t[c] += 1;
        }
        
        int left = 0, right=0;
        
        int n = p.length();
        
        while(right < s.length()) {
            
            m[s[right]] += 1;
            
            if(m[s[right]] > t[s[right]]) {
                
                char c = s[right];
                
                while(left <= right && m[c] > t[c]) {
                    
                    m[s[left]] -= 1;
                    left += 1;
                    
                }
                
            }
            
            if(right - left + 1 == n) {
                
                res.push_back(left);
                
            }
            
            right += 1;
            
        }
        
        return res;
        
    }
};