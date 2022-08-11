class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> m(2001);
        for(auto x:arr) ++m[x+1000];
        sort(m.begin(), m.end());
        
        for(int i=1;i<2001;i++){
            if(m[i] && m[i]==m[i-1]) return false;
        }
        return true;
        
    }
};