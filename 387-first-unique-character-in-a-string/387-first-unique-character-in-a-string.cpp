class Solution {
public:
    int firstUniqChar(string s) {
        if(s.length()==1) return 0;
        
        vector<vector<int>> res(26);

        for(int i=0;i<s.length();i++){
            res[s[i]-'a'].push_back(i);
        }
        
        int minindex=INT_MAX;
        
        for(int i=0;i<26;i++){
            if(res[i].size()==1){
                minindex = min(minindex, res[i][0]);
            }
        }
        
        return minindex==INT_MAX?-1:minindex;
        
    }
};