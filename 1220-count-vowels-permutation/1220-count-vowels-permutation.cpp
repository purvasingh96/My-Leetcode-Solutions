class Solution {
public:
    int countVowelPermutation(int n) {
        map<char, vector<char>> m;
        m['a'] = {'e'};
        m['e'] = {'a', 'i'};
        m['o'] = {'i', 'u'};
        m['u'] = {'a'};
        m['i'] = {'a', 'e', 'o', 'u'};
        
        vector<int> dp(26, 0);
        
        
        vector<int> chars = {'a', 'e', 'i', 'o', 'u'};
        
        for(auto c:chars){
            dp[c-'a'] = 1;
        }
        int MOD = 1000000007;
        for(int i=2;i<=n;i++){
            vector<int> new_row(26, 0);
            for(auto c:chars){
                
                for(auto x:m[c]){
                    
                    new_row[c-'a'] =  new_row[c-'a']%MOD + (dp[x-'a']%MOD);
                    
                }
                
            }
            
            dp=new_row;
            
        }
        
        int sum=0;
        
        for(auto c:dp){
            sum= sum%MOD + c%MOD;
        }
        return sum%MOD;
    }
};