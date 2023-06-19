class Solution {
private:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
public:
    int maxVowels(string s, int k) {
        int l=0, r=k-1;
        vector<int> count(26, 0);
        
        int countVowels=0, i=l, ans=INT_MIN;
        
        for(;i<=r;i++){
            count[s[i]-'a']+=1;
            if(isVowel(s[i])) countVowels += 1;
            ans = max(ans, countVowels);
        }
        
        
        for(;i<s.length();i++){
            count[s[i]-'a']+=1;
            if(isVowel(s[i])) countVowels += 1;
            
            count[s[l]-'a']-=1;
            if(isVowel(s[l])) countVowels -= 1;
            
            l+=1;
            
            ans = max(ans, countVowels);
        }
        
        return ans;
    }
};