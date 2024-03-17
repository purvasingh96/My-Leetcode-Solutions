class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        for(int i=0;i<heights.size();i++){
            if(ans.size() == 0 || heights[ans.back()] > heights[i]){
                ans.push_back(i);
            } else {
                while(ans.size()!=0 && heights[ans.back()] <= heights[i]){
                    ans.pop_back();
                }
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};