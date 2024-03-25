class Solution {
private:
    int ps(vector<int>& nums, int start, int end){
        int sum=0;
        for(int i=start;i<end;i++){
            sum += nums[i];
        }
        return sum;
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int bestOneIndex = 0;
        vector<int> bestTwoIndex = {0, k};
        vector<int> bestThreeIndex = {0, k, k*2};
        
        int maxTotalOneSum = ps(nums, 0, k);
        int maxTotalTwoSum = ps(nums, 0, k*2);
        int maxTotalThreeSum = ps(nums, 0, k*3);
        
        
        int currOneSum = ps(nums, 0, k);
        int currTwoSum = ps(nums, k, k*2);
        int currThreeSum = ps(nums, k*2, k*3);
        
        // [1,2(i),1,2,6,7,5,1]
        
        for(int i=1;i<n-3*k+1;i++){
            currOneSum = currOneSum - nums[i-1] + nums[i+k-1];
            currTwoSum = currTwoSum - nums[i+k-1] + nums[i+2*k-1];
            currThreeSum = currThreeSum - nums[i+2*k-1] + nums[i+3*k-1];
            
            if(currOneSum > maxTotalOneSum){
                maxTotalOneSum = currOneSum;
                bestOneIndex = i;
            }
            
            if(currTwoSum + maxTotalOneSum > maxTotalTwoSum){
                maxTotalTwoSum = currTwoSum + maxTotalOneSum;
                bestTwoIndex = {bestOneIndex, i+k};
            }
            
            if(currThreeSum + maxTotalTwoSum > maxTotalThreeSum){
                maxTotalThreeSum = currThreeSum + maxTotalTwoSum;
                bestThreeIndex = {bestTwoIndex[0], bestTwoIndex[1], i+2*k};
            }
            
        }
        
        return bestThreeIndex;
        
    }
};