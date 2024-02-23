class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& n1, vector<vector<int>>& n2) {
     
        vector<vector<int>> ans;
        
        int i=0, j=0;
        
        while(i<n1.size() && j<n2.size()){
            int start = max(n1[i][0], n2[j][0]);
            int end = min(n1[i][1], n2[j][1]);
            
            if(start<=end){
                ans.push_back({start, end});
            }
            
            if(n1[i][1] < n2[j][1]){
                i+=1;
            } else {
                j+=1;
            }
        }
        
       
        
        
        return ans;
        
        
    }
};