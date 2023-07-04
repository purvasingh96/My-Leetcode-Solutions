class Solution {
private:
    int count(int l, int r, string& s){
        unordered_set<char> st;
        for(int i=l;i<=r;i++){
            st.insert(s[i]);
        }
        
        return st.size();
    }
public:
    int countPalindromicSubsequence(string s) {
        vector<int> l(26, INT_MAX);
        vector<int> r(26, INT_MIN);
        
        for(int i=0;i<s.length();i++){
            l[s[i]-'a'] = min(l[s[i]-'a'], i);
            r[s[i]-'a'] = max(r[s[i]-'a'], i);
        }
        
        
        
        int ans=0;
        for(int i=0;i<26;i++){
            if(l[i]!=INT_MAX && r[i]!=INT_MIN){
                // count unique char between l and r
                ans += count(l[i]+1, r[i]-1, s);
            }
        }
        
        return ans;
        
    }
};