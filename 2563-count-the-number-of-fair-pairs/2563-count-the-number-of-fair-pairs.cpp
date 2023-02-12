class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        map<pair<int, int>, int> m;
        long long ans=0;
       sort(nums.begin(), nums.end());
           
          
        for(int i=0;i<nums.size();i++){
            
            int key = nums[i];
            int l1 = lower-key;
            int l2 = upper-key;
            
            
            //cout<<"l1: "<<l1<<" l2: "<<l2<<"\n";
            auto start = lower_bound(nums.begin()+i+1, nums.end(), l1)-nums.begin();
            auto end = upper_bound(nums.begin()+i+1, nums.end(), l2)-nums.begin();
            
            ans += (end-start); 
            
            
            
            
        }
        
        return ans;
        
    }
};