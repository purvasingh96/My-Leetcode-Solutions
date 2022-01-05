class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        
        
        while(left<right) {
            if(s[left++] != s[right--]) return false;
        }
        
        return true;
        
    }
    
    void back_track(string s, vector<vector<string>>& res, vector<string> temp, int start) {
        
        if(start == s.length()) {
            
            res.push_back(temp);
            
            return;
            
        }
        
        for(int i=start;i<s.length();i++) {
            
            if(isPalindrome(s, start, i)) {
                
                temp.push_back(s.substr(start, i-start+1));
                
                back_track(s, res, temp, i+1);
                
                temp.pop_back();
                
            }
            
        }
        
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        
        back_track(s, res, temp, 0);
        
        return res;
        
    }
};