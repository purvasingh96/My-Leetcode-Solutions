class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int N = n/2;
        int N_ = n-N;
        int x = (1<<N)+1;
        int y = (1<<N_)+1;
        
        vector<long long> left(x);
        vector<long long> right(y);
        
        for(int mask=0;mask<(1<<N);mask++){
            long long sz=0, l=0;
            for(int i=0;i<N;i++){
                if(mask&(1<<i)) {
                    sz+=1;
                    l+=nums[i];
                }
            }
            left[mask] = l;
        }
        
        for(int mask=0;mask<(1<<N_);mask++){
            long long rsz=0, r=0;
            for(int i=0;i<N_;i++){
                if(mask & (1<<i)){
                    rsz+=1;
                    r+= nums[i+N];
                }
            }
            right[mask] = r;
        }
        
        
        
        sort(right.begin(), right.end());
        
    //cout<<"working till here";
        
        int res=INT_MAX;
            
            for(auto &a:left){
                
                 int target = (goal - a);
                
                auto it = lower_bound(right.begin(), right.end(), target);
                
                if(it!=right.end()) res = min(res, int(abs(goal - (a + (*it)))) );
                
                if(it!=right.begin()){
                    //cout<<"it not v begin: "<<target<<"\n";
                    --it;
                    //cout<<"itr value: "<<*itr<<"\n";
                    res = min(res, int(abs(goal - (a + (*it)))) );
                    //cout<<res<<"\n";
                }
                
            }
         
        return res;
    }
};