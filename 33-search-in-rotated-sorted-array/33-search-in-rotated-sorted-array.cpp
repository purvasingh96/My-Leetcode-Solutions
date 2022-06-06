class Solution {
private:
    int find_rotation_index(vector<int>& nums, int left, int right){
        if(nums[left]<nums[right]) return 0;
        
        while(left<=right){
            
            int mid = left + (right-left)/2;
            
            if(nums[mid] > nums[mid+1]){
                return mid+1;
            } else if(nums[mid] < nums[left]){
                right=mid-1;
            } else{
                left=mid+1;
            }
            
        }
        return 0;
    }
    
    int binary_search(vector<int>& nums, int left, int right, int target){
        
        while(left<=right){
            
            int mid = left + (right-left)/2;
            
            if(nums[mid] == target) return mid;
            
            else if(nums[mid] > target) {
                right=mid-1;
            } else{
                left = mid+1;
            }
            
        }
        
        return -1;
        
    }
    
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        if(n==1){
            return nums[0]==target?0:-1;
        }
        
        int rotateIndex = find_rotation_index(nums, 0, n-1);
        
        if(nums[rotateIndex] == target) return rotateIndex;
        
        if(rotateIndex == 0){
            return binary_search(nums, 0, n-1, target);
        } else if(target < nums[0]){
            return binary_search(nums, rotateIndex, n-1, target);
        } 
        
        return binary_search(nums, 0, rotateIndex, target);
    }
};