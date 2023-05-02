class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg=0;
        
        for(auto x:nums){
            if(x<0) neg+=1;
            else if(x==0) return 0;
        }
        
        if(neg%2==0) return 1;
        return -1;
    }
};