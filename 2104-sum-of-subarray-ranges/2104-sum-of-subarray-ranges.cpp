class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ple(n, -1), nle(n, n), pge(n, -1), nge(n, n);
        deque<int> q;
        
        for(int i=0;i<n;i++){
            while(!q.empty() && nums[q.back()] >= nums[i]){
                q.pop_back();
            }
            
            if(!q.empty()) ple[i] = q.back();
            q.push_back(i);
        }
        
        q.clear();
        
        for(int i=0;i<n;i++){
            while(!q.empty() && nums[q.back()]<=nums[i]){
                q.pop_back();
            }
            
            if(!q.empty()) pge[i]=q.back();
            q.push_back(i);
        }
        
        q.clear();
        
        for(int i=n-1;i>=0;i--){
            while(!q.empty() && nums[q.back()] > nums[i]){
                q.pop_back();
            }
            if(!q.empty()) nle[i]=q.back();
            q.push_back(i);
        }
        
        q.clear();
        
        for(int i=n-1;i>=0;i--){
            while(!q.empty() && nums[q.back()] < nums[i]){
                q.pop_back();
            }
            if(!q.empty()) nge[i] = q.back();
            q.push_back(i);
        }
        
        
        long long res=0;
        for(int i=0;i<n;i++) {
            long long leftMin =i- ple[i], rightMin = nle[i]-i;
            long long leftMax = i-pge[i], rightMax = nge[i]-i;
            
            res += nums[i] * (leftMax*rightMax - leftMin*rightMin);
        }
        
        return res;
    }
};