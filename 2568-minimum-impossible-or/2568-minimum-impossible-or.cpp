class Solution {
private:
    bool isPowerOfTwo(int num){
        int res = (num)&(num-1);
        return res==0;
    }
    

    
public:
    int minImpossibleOR(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int val=0;
        
        int i=0;
        
        while(i<nums.size()){
            while(i<nums.size() && nums[i] == pow(2, val)){
                val+=1;
                i+=1;
            } 
            
            while(i<nums.size() && nums[i]!=pow(2, val)){
                i+=1;
            }
            
            if(i<nums.size() && nums[i]!=pow(2, val)) return pow(2, val);
        }
        
        return pow(2, val);
    }
};