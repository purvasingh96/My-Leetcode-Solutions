class Solution {
public:
    int minCostII(vector<vector<int>>& cost) {
        int n = cost.size();
        int k = cost[0].size();
        if(n==0) return 0;
        
        for(int i=1;i<n;i++){
            
            int min_first=INT_MAX;
            int min_sec = INT_MAX;
            int mi=INT_MAX;
            
            for(int j=0;j<k;j++){
                if(cost[i-1][j]<min_first){
                    min_sec = min_first;
                    min_first=cost[i-1][j];
                    mi=j;
                } else if(cost[i-1][j]<min_sec){
                    min_sec=cost[i-1][j];
                }
            }
            
            cout<<min_first<<" "<<min_sec<<" "<<mi<<"\n";
            
            for(int j=0;j<k;j++){
                if(j==mi) {
                    cost[i][j]+=min_sec;
                } else{
                    cost[i][j] += min_first;
                }
            }
        }
        
        return *min_element(cost[n-1].begin(), cost[n-1].end());
    }
};