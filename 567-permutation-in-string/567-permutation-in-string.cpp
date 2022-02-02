class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m(26, 0);
        vector<int> t(26, 0);
        
        for(auto c:s1) {
            
            t[c - 'a'] += 1;
            
        }
        
        int left=0, right=0;
        
        while(right < s2.length()) {
            
            m[s2[right] - 'a'] += 1;
            
            if(m[s2[right] - 'a'] > t[s2[right] - 'a']) {
                
                int c = s2[right] - 'a';
                
                while(left <= right && m[c] > t[c]) {
                    
                    m[s2[left] - 'a'] -= 1;
                    left += 1;
                    
                }
                
            }
            
            if(right - left + 1 == s1.length()) return true;
            
            right+=1;
            
        }
        
        return false;
    }
};