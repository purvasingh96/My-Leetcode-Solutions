class Solution {

public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = i;
            } else{
                int prev = m[nums[i]];
                if(abs(i-prev) <= k) {
                    return true;
                }
                
                m[nums[i]] = i;
            }
            
        }
        
//         for(auto it:m){
//             vector<int> res = it.second;
//             if(res.size() >= 2){
//                 int x = abs(res[0] - res[1]);
//                 if(x<=k) return true;
                
//                 for(int i=2;i<res.size();i++){
                   
//                     if(abs(res[i] - res[i-1])<=k) return true;
                    
//                 }
//             }
//         }
        
        return false;
        
    }
};