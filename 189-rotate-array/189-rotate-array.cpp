class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k%n!=0) {
            
            nums.resize(2*n);
            
            for(int i=0;i<n;i++) {
                
                int pos = n + (i+k)%n;
                
                nums[pos] = nums[i];
                
            }
            
            nums.erase(nums.begin(), nums.begin()+n);
            
        }
        
    }
};