class Solution {
public:
    int waysToSplit(vector<int>& arr) {
        // string ques
        int n =arr.size();
        long count=0;
        int mod = 1e9+7;
        
        vector<int> nums(n, 0);
        nums[0] = arr[0];
        for(int i=1;i<n;i++) nums[i] = arr[i]+nums[i-1];
        
        for(int i=0;i<n-2;i++){
            
            int ans1=-1, left=i+1, right=n-2;
            int x=nums[i], y=2*x;
            
            while(left<=right){
                
                int mid = left + (right-left)/2;
                
                if(nums[mid] >= y){
                    ans1=mid;
                    right=mid-1;
                } else left=mid+1;
                
            }
            
            if(ans1==-1) continue;
            
            int ans2=-1;
            left=ans1, right=n-2;
            
            while(left<=right){
                
                int mid = left + (right-left)/2;
                
                if(nums[n-1] - nums[mid]>= nums[mid]-nums[i]){
                    ans2=mid;
                    left=mid+1;
                } else right=mid-1;
                
            }
            
            if(ans2==-1) continue;
            count+= (ans2-ans1+1);
            
        }
        
        return  (int)(count % mod);
    }
};