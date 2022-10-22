class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sa(26, 0);
        vector<int> st(26, 0);
        
        for(auto c:s) sa[c-'a']+=1;
        for(auto c:t) st[c-'a']+=1;
        
        int c=0;
        for(int i=0;i<26;i++){
          if(st[i] > sa[i]) c += (st[i] - sa[i]);
        }
        
        return c;
        
    }
};