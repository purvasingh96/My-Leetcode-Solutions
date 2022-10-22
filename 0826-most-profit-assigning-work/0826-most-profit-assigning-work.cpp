class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        map<int, int> m;
        int maxSoFar=INT_MIN;
        m[0] = 0;
        
        for(int i=0;i<d.size();i++){
            m[d[i]] = max(m[d[i]], p[i]);
        }
       
        
        for(auto it:m){
            maxSoFar=max(maxSoFar, it.second);
            m[it.first]=maxSoFar;
        }
        
        int sum=0;
        
        for(int i=0;i<w.size();i++){
            
            sum += prev(m.upper_bound(w[i]))->second;
            
        }
        
        return sum;
    }
};