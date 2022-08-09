class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        
        int lr=0, lc=0, ur=nums.size()-1, uc=nums[0].size()-1;
        vector<int> res;
        
        while(lr<=ur && lc<=uc){
            
            for(int j=lc;j<=uc;j++){
                res.push_back(nums[lr][j]);
            }
            
            lr+=1;
            
            for(int i=lr;i<=ur;i++){
                res.push_back(nums[i][uc]);
            }
            
            uc-=1;
            
            if(lr<=ur){
               for(int j=uc;j>=lc;j--){
                    res.push_back(nums[ur][j]);
                }

                ur-=1; 
            }
            
            if(lc<=uc){
              for(int i=ur;i>=lr;i--){
                res.push_back(nums[i][lc]);
               }

                lc+=1;  
            }
            
            
            
        }
        
        return res;
        
    }
};