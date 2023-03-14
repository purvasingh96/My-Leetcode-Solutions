class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int i=1, prefix=1;
        while(i<n){
            prefix *= nums[i-1];
            res[i]=prefix;
            i+=1;
        }
        
        int j=n-2;
        prefix=1;
        while(j>=0){
            prefix *= nums[j+1];
            res[j] *= prefix;
            j--;
        }
        
        return res;
    }
};