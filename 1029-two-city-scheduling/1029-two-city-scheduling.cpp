class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] - a[1] < b[0] - b[1]);
        });
        
        int total=0;
        
        int n = costs.size()/2;
        
        
        for(int i=0;i<costs.size();i++) {
            
            if(i<n){
                total += costs[i][0];
            }  else {
                total += costs[i][1];
            }
            
        }
        
        return total;
    }
};