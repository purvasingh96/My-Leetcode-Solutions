class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        /*
        TC: O(max(N, 1001))
        SC: O(1001) => O(1)
        */
        vector<int> total_passengers(1001, 0);
        
        for(auto x:trips) {
            total_passengers[x[1]] += x[0];
            total_passengers[x[2]] -= x[0];
        }
        
        int cap=0;
        
        for(auto x:total_passengers) {
            cap += x;
            
            if(cap > capacity) return false;
        }
        
        return true;
    }
};