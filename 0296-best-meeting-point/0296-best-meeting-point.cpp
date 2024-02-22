class Solution {
private:
    int dist(vector<int>& points, int i){
        int d=0;
        for(auto x:points){
            d += abs(x - i);
        }
        
        return d;
    }
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> cols;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        sort(cols.begin(), cols.end());
        int r = rows[rows.size()/2];
        int c = cols[cols.size()/2];
        return dist(rows, r) + dist(cols, c);
    }
};