class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int N = n/2;
        vector<vector<int>> left(N+1), right(N+1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        for(int mask=0;mask<(1<<N);mask++){
            int sz=0, l=0, r=0;
            
            for(int i=0;i<N;i++){
                // check if ith bit is set
                if(mask& (1<<i)) {
                    sz+=1;
                    l += nums[i];
                    r += nums[i+N];
                }
            }
            
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        
        for(int sz=0;sz<=N;sz++){
            sort(right[sz].begin(), right[sz].end());
        }
        
        int res = INT_MAX;
        
        for(int sz=1;sz<=N;sz++){
            for(auto &a:left[sz]){
                int b =  (sum - 2*a)/2;
                int rsz = N - sz;
                
                auto &v = right[rsz];
                
                auto it = lower_bound(v.begin(), v.end(), b);
                
                if(it!=v.end()) res = min(res, abs(sum - 2*(a+(*it))));
                if(it!=v.begin()){
                    
                    auto itr = it;
                    --it;
                    res = min(res, abs(sum - 2*(a+(*it))));
                }
            }
        }
        
        return res;
    }
};