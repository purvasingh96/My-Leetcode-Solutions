class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> dq;
        
        for(int i=0;i<heights.size();i++){
            if(dq.size()==0 || heights[dq.back()] > heights[i]){
                dq.push_back(i);
            } else {
                while(dq.size()!=0 && heights[dq.back()] <= heights[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        
        return dq;
    }
};