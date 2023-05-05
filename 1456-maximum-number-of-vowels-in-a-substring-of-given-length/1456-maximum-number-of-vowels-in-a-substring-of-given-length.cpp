class Solution {
private:
    bool isVowel(char c){
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        return find(vowels.begin(), vowels.end(), c)!=vowels.end();
    }
public:
    int maxVowels(string s, int k) {
        
        int j=k;
        int c=0;
        for(int p=0;p<k;p++){
            if(isVowel(s[p])) c+=1;
        }
        
        int ans = c;
        while(j<s.length()){
            if(isVowel(s[j])) c+=1;
            if(isVowel(s[j-k])) c-=1;
            ans = max(ans, c);
            j+=1;
        }
        
        return ans;
        
    }
};