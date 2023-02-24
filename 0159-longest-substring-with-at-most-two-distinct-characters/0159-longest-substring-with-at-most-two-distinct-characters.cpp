class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> m;
        
        int left=0, ans=0;
        
        for(int right=0;right<s.length();right++){
            m[s[right]]+=1;
            
            while(left<right && m.size() > 2){
                m[s[left]]-=1;
                if(m[s[left]]==0) m.erase(s[left]);
                left+=1;
            }
            
            ans = max(ans, right-left+1);
        }
        
        return ans;
        
    }
};