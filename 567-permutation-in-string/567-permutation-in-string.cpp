class Solution {
public:
    bool checkPermutation(vector<int> s1, vector<int> s2) {
        
        for(int i=0;i<26;i++) {
            
            if(s1[i] != s2[i]) return false;
        }
        
        return true;
        
    }
    
    
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        
        vector<int> s1_map(26, 0);
        vector<int> s2_map(26, 0);
        // O(l1)
        
        for(int i=0;i<s1.length();i++){
            
            s1_map[(s1[i] - 'a')] += 1;
            s2_map[(s2[i] - 'a')] += 1;
            
        }
        
        for(int i=0;i<s2.length() - s1.length();i++) {
            
            if(checkPermutation(s1_map, s2_map)) return true;
            
            s2_map[s2[i+s1.length()] - 'a'] += 1;
            s2_map[s2[i] - 'a'] -= 1;
            
        }
        
        return checkPermutation(s1_map, s2_map);
        
    }
};