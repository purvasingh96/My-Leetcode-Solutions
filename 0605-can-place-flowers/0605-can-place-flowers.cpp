class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        vector<int> temp = {0};
        temp.insert(temp.end(), nums.begin(), nums.end());
        temp.push_back(0);
        int k =nums.size();
        
        for(int i=1;i<temp.size()-1;i++){
            
                if(temp[i] ==0 && temp[i-1] !=1 && temp[i+1]!=1){
                    n-=1;
                    temp[i]=1;
                }
            
            
            if(n<=0){
                return true;
            }
        }
        
        return n<=0;
    }
};