class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int i=0, j=0;
        vector<vector<int>> ans;
        while(i<a.size() && j <b.size()){
            int start = max(a[i][0], b[j][0]);
            int end = min(a[i][1], b[j][1]);
            
            if(start<=end){
                ans.push_back({start, end});
            }
            
            if(a[i][1] < b[j][1]){
                i+=1;
            } else {
                j+=1;
            }
        }
        
        return ans;
    }
};