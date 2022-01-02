class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        unordered_map<int, int> m;
        int count=0;
        
        for(int i=0;i<time.size();i++) {
            
            for(auto x:m) {
                
                int sum = (x.first + time[i]);
                if( sum%60 == 0) {
                    count += (x.second);
                }
                
            }
            
            m[time[i]] += 1;
            
        }
        
        return count;
        
    }
};