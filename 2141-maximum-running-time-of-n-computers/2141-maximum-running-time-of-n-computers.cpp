class Solution {
private:
    bool isEnough(vector<int>& batteries, long long mid, int n){
        long long total = mid*n;
        for(long long x:batteries){
            total -= min(x, mid);
        }
        return total <= 0;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left=0, right=accumulate(batteries.begin(), batteries.end(), 0LL);
        long long ans;
        while(left<=right){
            long long mid = left + (right-left)/2;
            if(isEnough(batteries, mid, n)){
                ans=mid;
                left=mid+1;
            } else right=mid-1;
        }
        
        return ans;
    }
};