class Solution {
private:
    vector<long long> power_i;
    
    void powersOfTwo(int n){
        power_i.resize(n);
        power_i[0] =1;
        int mod=1e9+7;
        
        for(int i=1;i<n;i++){
            power_i[i] = (power_i[i - 1] * 2) % mod;
        }
    }
    
    int bs(vector<int>& nums, int i, int target){
        int l=0, r=i-1;
        int ans=-1;
        
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid] + nums[i] <= target){
                ans = mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        if(l!=i && nums[l] + nums[i] <= target) return l;
        return ans;
    }
    
    long long power(int r, int l){
        int mod = 1e9+7;

        //if(r==41) cout<<(power_i[41]%mod)<<" "<<(power_i[32]%mod)<<"\n";
        long long prod = power_i[l]*(power_i[r-l]-1);
        return prod%mod;
    }
    
public:
    int numSubseq(vector<int>& nums, int target) {
        powersOfTwo(nums.size());
        
        sort(nums.begin(), nums.end());
        //for(auto x:nums) cout<<x<<" ";
        int mod = 1e9+7;
        vector<long long> ps;
        ps.push_back(0);
        
        for(int i=0;i<nums.size();i++){
            
            int n = bs(nums, i, target);
            //cout<<"i: "<<i<<" n: "<<n<<"\n";
            int r = i, l=i-n-1;
            long long count = power(r,l);
            //cout<<"i: "<<i<<" count: "<<count<<"\n";
            count = count%mod;
            
            if(nums[i]*2<=target) count+=1;
            long long sum = count + ps.back();
            sum=(sum)%mod;
            
            ps.push_back(sum);
        }
        
        
        
        return (int)ps.back();
        
    }
};