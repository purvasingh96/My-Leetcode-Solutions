class Solution {
private:
//     int count(int target, vector<vector<int>>& walls){
//         int c=0;
//         for(int i=1;i<walls.size();i++){
//             int j = lower_bound(walls[i].begin(), walls[i].end(), target) - walls[i].begin();
//             if(walls[i][j] != target) c+=1;
//         }
        
//         return c;
//     }
    
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> count;
        
        for(int i=0;i<wall.size();i++){
            long long sum = 0;
            for(int j=1;j<wall[i].size();j++){
                sum +=wall[i][j-1];
                count[sum] +=1;
            }
        }
        
        int maxFreq = 0;
        for(auto x:count){
            maxFreq= max(maxFreq, x.second);
        }
        
        int n = wall.size();
        
        return n - maxFreq;
        
    }
};