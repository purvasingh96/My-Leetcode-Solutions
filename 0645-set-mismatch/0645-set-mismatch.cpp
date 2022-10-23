class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate;
        int n = nums.size();
        vector<int> res(10001, 0);
        
        for(int i=0;i<n;i++) {
            if(res[nums[i]] > 0){
                duplicate = nums[i];
                break;
            }
            res[nums[i]]+=1;
        }
        //cout<<duplicate;
        
        int sum1 = accumulate(nums.begin(), nums.end(), 0);
        int sum2 = (n)*(n+1)/2;
        int missing = sum2 - sum1 + duplicate;
        
        return {duplicate, missing};
        
    }
};