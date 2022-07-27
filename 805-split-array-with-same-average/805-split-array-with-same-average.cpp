class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if(n==2) return (nums[0] == nums[1]);
        int N = n/2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<int>> left(N+1), right(n-N+1);
        
        for(int mask=0;mask<(1<<N);mask++){
            int l=0,sz=0;
            
            for(int i=0;i<N;i++){
                if(mask & (1<<i)) {
                    sz+=1;
                    l+=nums[i];
                }
            }
            left[sz].push_back(l);
        }
        
        for(int mask=0;mask<(1<<(n-N));mask++){
            int sz=0, r=0;
            for(int i=0;i<(n-N);i++){
                if(mask & (1<<i)) {
                    sz+=1;
                    r+=nums[i+N];
                }
            }
            right[sz].push_back(r);
        }
        
        
        for(int sz=0;sz<=n-N;sz++){
            sort(right[sz].begin(), right[sz].end());
        }
        
         for(int i=0;i<=(N);i++){
            cout<<i<<" -> ";
            for(auto y:left[i]){
                cout<<y<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
        for(int i=0;i<=(n-N);i++){
            cout<<i<<" -> ";
            for(auto y:right[i]){
                cout<<y<<" ";
            }
            cout<<"\n";
        }

        
        for(int sz=1;sz<=N;sz++){
            for(auto a:left[sz]){
                for(int rsz=1;rsz<=(n-N);rsz++){
                    int cur_size = rsz+sz;
                    
                    
                    double b = ((double)(sum*cur_size)/(double)n) - a;
                    
                    auto it = lower_bound(right[rsz].begin(), right[rsz].end(), b);
                    if(it!=right[rsz].end()){
                        if(*it==b){
                            if(cur_size==n) {
                                if((double)a/(double)sz==(double)b/(double)rsz) return true;
                                else continue;
                            }
                            
                            return true;
                        }
                    }
                }
                
            }
            
        }
        
        return false;
    }
};