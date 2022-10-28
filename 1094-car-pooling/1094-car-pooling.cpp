class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int> ls(1100, 0);
        
        for(int i=0;i<trips.size();i++){
            int start = trips[i][1], end=trips[i][2], val = trips[i][0];
            ls[start] += val;
            ls[end] -= val;
        }
        
        int prev=0;
        
        for(int i=0;i<ls.size();i++){
            ls[i] += prev;
            prev = ls[i];
            if(ls[i] >capacity) return false;
        }
        return true;
        
    }
};