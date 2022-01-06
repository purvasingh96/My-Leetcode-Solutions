class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> total_passengers(1001, 0);
        
        for(auto x:trips) {
            int start = x[1];
            int end = x[2];
            
            int passenger = x[0];
            
            for(int i=start;i<end;i++) {
                total_passengers[i] += passenger;
                
                if(total_passengers[i] > capacity) return false;
            }
        }
        
        return true;
    }
};