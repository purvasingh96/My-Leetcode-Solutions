class Solution {
private:
    int dfs(int left, int right, int k, string& s){
        vector<int> count(26, 0);
        for(int i =left;i<right;i++){
            count[s[i]-'a']+=1;
        }
        int l=0, r=0;
        
        for(int i=left;i<right;i++){
            if(count[s[i]-'a']>=k) continue;
            int next = i+1;
            while(next<right && count[s[next]-'a']<k) next+=1;
            l = dfs(left, i, k, s);
            r = dfs(next, right, k, s);
            return max(l, r);
        }
        
        return right-left;
    }
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        return dfs(0, n, k, s);
    }
};