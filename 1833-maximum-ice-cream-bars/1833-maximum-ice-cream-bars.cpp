class Solution {

public:
    int maxIceCream(vector<int>& costs, int coins) {
        int idx=0, total=0;
        sort(costs.begin(), costs.end());
        
        for(idx;idx<costs.size();idx++){
            total += costs[idx];
            if(total > coins) break;
        }
        return idx;
    }
};