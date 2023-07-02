class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);
        for(auto x:nums) freq[x]+=1;
        int i=0;
        int k=0;
        while(i<nums.size()){
            while(freq[k]--){
                nums[i++]=k;        
            }
            k+=1;
        }
        
        
    }
};