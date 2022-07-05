class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0, right=k;
        int n =nums.size();
        vector<int> ps(n,0);
        
        ps[0]=nums[0];
        
        for(int i=1;i<n;i++){
            ps[i] = ps[i-1]+nums[i];
        }
        
        //for(auto x:ps) cout<<x<<" ";
        
        double maxavg=(double)ps[k-1]/k;
        
        
        while(right<n){
            
            int cur_sum = ps[right] - ps[left];
            maxavg = max(maxavg, (double)cur_sum/k);
            left+=1;
            right+=1;
        }
        return (double)maxavg;
    }
};