class Solution {
private:
    bool isEnough(vector<int>& batteries, long long mid, int n){
        long long total=0, c=0;
        
        for(int i=0;i<batteries.size();i++){
            total += batteries[i];
            if(total >= mid) {
                total = total-mid;
                c+=1;
                if(c==n) return true;
            }
        }
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left=0, right=accumulate(batteries.begin(), batteries.end(), 0LL);
        long long ans;
        
        sort(batteries.begin(), batteries.end());
        
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