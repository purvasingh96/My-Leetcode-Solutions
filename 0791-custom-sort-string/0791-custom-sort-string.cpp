class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> ord(26, INT_MAX);
        int next=0;
        
        for(auto c:order){
            ord[c-'a'] = next;
            next+=1;
        }
        
        sort(s.begin(), s.end(), [&](const char& a, const char& b){
            return ord[a-'a'] < ord[b-'a'];
        });
        
        return s;
    }
};