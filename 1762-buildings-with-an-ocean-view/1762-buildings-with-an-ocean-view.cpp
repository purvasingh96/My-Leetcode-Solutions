class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        // monotonic decreasing array
        vector<int> res;
        
        for(int i=0;i<heights.size();i++){
            if(res.size()==0 || heights[res.back()] > heights[i]){
                res.push_back(i);
            } else {
                while(res.size()!=0 && heights[res.back()] <= heights[i]){
                    res.pop_back();
                }
                res.push_back(i);
            }
        }
        
        return res;
    }
};