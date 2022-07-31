class Solution {

public:
    int maximumGroups(vector<int>& grades) {
        vector<int> res;
        int i=1, n = grades.size();
        res.push_back(1);
        int cs =1;
        
        while(cs<=n){
            i+=1;
            res.push_back(i);
            cs+=i;
            if(cs==n) return res.size();
        }
        
        return res.size()-1;
    }
};