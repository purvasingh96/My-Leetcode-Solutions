class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m(26, 0);
        vector<int> t(26, 0);
        vector<int> res;
        
        
        for(auto c:p) {
            t[c - 'a'] += 1;
        }
        
        int left = 0, right=0;
        
        int n = p.length();
        
        while(right < s.length()) {
            
            m[(s[right]-'a')] += 1;
            
            if(m[(s[right]-'a')] > t[(s[right]-'a')]) {
                
                char c = s[right];
                
                while(left <= right && m[(c - 'a')] > t[(c - 'a')]) {
                    
                    m[s[left] - 'a'] -= 1;
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