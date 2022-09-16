class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long long left=0, right=2e18;
        int mod = 1e9+7;
        
        
        long a = (long)A, b = (long)B, n=(long)N;
        long ans=0;
        
        while(left<=right){
            //cout<<"left: "<<left<<" right: "<<right<<"\n";
            long mid = left + (right-left)/2;
            
            long count = mid/a + mid/b - mid/lcm(a,b);
            //cout<<count<<"\n";
            
            if(count<n) left=mid+1;
            else {
                //cout<<"mid: "<<mid<<"\n";
                ans=mid;
                right=mid-1;
            }
            
        }
        
        return ans%mod;
    }
};