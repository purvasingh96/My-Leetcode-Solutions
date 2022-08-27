class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int N = n/2;
        
        vector<vector<int>> left(N+1), right(N+1);
        
        for(int mask=0;mask<(1<<N);mask++) {
            int sz=0, l=0, r=0;
            for(int i=0;i<=N;i++){
                if(mask & (1<<i)){
                    sz+=1;
                    l+=nums[i];
                    r+=nums[i+N];
                }
            }
            
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        
        
        for(int sz=0;sz<=N;sz++){
            sort(right[sz].begin(), right[sz].end());
        }
        
        int mindiff = INT_MAX;
        
        for(int sz=1;sz<=N;sz++){
            
            for(auto &a:left[sz]){
                int rsz = N-sz;
                int target = (total_sum - 2*a)/2;
                
                auto &v = right[rsz];
                
                auto it = lower_bound(v.begin(), v.end(), target);
                if(it!=v.end()){
                    mindiff = min(mindiff, abs(total_sum - 2*(a + (*it))));
                }
                if(it!=v.begin()){
                    mindiff = min(mindiff, abs(total_sum - 2*(a + (*prev(it)))));
                }
            }
        }
        
        return mindiff;
        
    }
};