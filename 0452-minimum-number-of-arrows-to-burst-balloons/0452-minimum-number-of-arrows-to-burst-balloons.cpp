class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> res;
        int ans=1,end=points[0][1];
        
        for(int i=1;i<points.size();i++){
            if(points[i][0] > end){
                end=points[i][1];
                ans+=1;
            } else{
                end=min(end, points[i][1]);
            }
        }
        
        return ans;
    }
};