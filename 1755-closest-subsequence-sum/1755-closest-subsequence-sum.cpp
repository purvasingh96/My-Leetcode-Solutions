class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n =nums.size();
        int N = n/2;
        int N_ = n-N;
        int res = INT_MAX;
        vector<int> left, right;
        
        for(int mask=0;mask<(1<<N);mask++){
            int l=0;
            for(int i=0;i<=N;i++) {
                if(mask & (1<<i)){
                    l+=nums[i];
                }
            }
            
            left.push_back(l);
        }
        
        for(int mask=0;mask<(1<<N_);mask++){
            int r=0;
            for(int i=0;i<=N_;i++){
                if(mask & (1<<i)){
                    r+=nums[i+N];
                }
            }
            right.push_back(r);
        }
        
        sort(right.begin(), right.end());
        
        // for(auto x:left) cout<<x<<" ";
        // cout<<"\n";
        // for(auto x:right) cout<<x<<" ";
        
        for(int i=0;i<left.size();i++){
            
            int a = left[i];
            int target = goal-a;
            
            
            auto it = lower_bound(right.begin(), right.end(), target);
            if(it!=right.end()){
                res = min(res, abs((a+*(it)) - goal));
            }
            
            if(it!=right.begin()){
                res = min(res, abs((a+*(prev(it))) - goal) );
            }
            
            
        }
        
        return res;
        
    }
};