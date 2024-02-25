class Solution {
private:
    bool dp[41][41][2000] = {};
    bool helper(string s1, string s2, int i, int j, int diff){
        if(i>=s1.length() && j>=s2.length()){
            return diff==0;
        }
        
        if(dp[i][j][diff+1000]==false){
            dp[i][j][diff+1000] = true;
        
        
        if(isdigit(s1[i])){
            
            int digit=0;
            for(int p = i; p < s1.length() && isdigit(s1[p]); p++){
                digit = digit*10 + (s1[p]-'0');
                if(helper(s1, s2, p+1, j, diff-digit)){
                    return true;
                }
            }
            return false;
        }
        
        if(isdigit(s2[j])){
            
            int digit=0;
            
            for(int p = j; p < s2.length() && isdigit(s2[p]); p++){
                digit = digit*10 + (s2[p]-'0');
                if(helper(s1, s2, i, p+1, diff+digit)){
                    return true;
                }
            }
            return false;
        }
        
        if(diff>0){
            return i<s1.length() && helper(s1, s2, i+1, j, diff-1);
        }
        
        if(diff < 0){
            return j<s2.length() && helper(s1, s2, i, j+1, diff+1);
        }
        
        if(!isdigit(s1[i]) && !isdigit(s2[j])){
            return i<s1.length() && j<s2.length() && s1[i] == s2[j]
                && helper(s1, s2, i+1, j+1, diff);
        }
        }
        return false;
    }
public:
    bool possiblyEquals(string s1, string s2) {
        
        return helper(s1, s2, 0, 0, 0);
    }
};