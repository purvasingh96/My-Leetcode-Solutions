class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int i=0, j=0, ans=0;
        unordered_map<char, int> res;
        
        while(j<s.length()){
            while(i<j && res[s[j]]==1){
                res[s[i]] -= 1;
                i+=1;
            }
            
            ans = max(ans, j-i+1);
            res[s[j++]] +=1;
            
        }
        return ans;
    }
};