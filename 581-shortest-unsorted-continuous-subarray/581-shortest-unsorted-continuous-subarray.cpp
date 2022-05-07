class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        
        deque<int> q;
        int left=nums.size()+1, right=nums.size()+1, maxidx=0, maxnum=INT_MIN;
        
        q.push_back(0);
        
        for(int i=1;i<nums.size();i++) {
            
            if(nums[i] >= nums[q.back()]) {
                q.push_back(i);
            } else {
                
                right = i;
                
                while(!q.empty() && nums[i] < nums[q.back()]) {
                    
                    left = min(left, q.back());
                    
                    if(nums[q.back()] > maxnum) {
                        maxnum = nums[q.back()];
                        maxidx=q.back();
                    }
                    
                    q.pop_back();
                    
                }
                
                q.push_back(i);
                q.push_back(maxidx);
                
            }
            
        }
        
        //cout<<right<<" "<<left;
        if(left == right) return 0;
        
        return (right-left+1);
    }
};