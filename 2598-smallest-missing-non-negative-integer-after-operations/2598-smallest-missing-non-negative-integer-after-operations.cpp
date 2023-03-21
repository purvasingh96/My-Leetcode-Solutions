class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
            
            nums[i] =nums[i]%value;
            if(nums[i]<0) nums[i] +=value;
            m[nums[i]]+=1;
        }
        
        sort(nums.begin(), nums.end());
        int k=0;
        while(true){
            if(m[k%value]==0) return k;
            m[k%value]-=1;
            k+=1;
        }
        
        return k;
    }
};