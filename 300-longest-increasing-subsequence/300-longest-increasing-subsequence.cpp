class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++){
            
            int num=nums[i];
            
            if(num>sub.back()){
                sub.push_back(num);
            } else{
                int j = binarySearch(sub, num);
                sub[j]=num;
            }
            
        }
        
        return sub.size();
    }
    
    int binarySearch(vector<int> sub,int num){
        int left=0, right=sub.size()-1;
        
        while(left<right){
            int mid = left + (right-left)/2;
            
            if(sub[mid] == num) return mid;
            else if(sub[mid] < num){
                left=mid+1;
            } else{
                right=mid;
            }
        }
        
        return left;
    }
};