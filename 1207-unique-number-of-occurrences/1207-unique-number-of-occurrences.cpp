class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        map<int, int> y;
        
        for(auto x:arr){
            m[x]+=1;
        }
        
        for(auto x:m){
            if(y[x.second]>0) return false;
            y[x.second]+=1;
        }
        
        return true;
        
    }
};