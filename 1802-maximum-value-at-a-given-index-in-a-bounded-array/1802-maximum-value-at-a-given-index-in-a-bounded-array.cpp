// https://www.youtube.com/watch?v=MjpAAE3-hYg&ab_channel=CherryCoding%5BIIT-G%5D

class Solution {
private:
    long long val(int n) {
        return (long long)n*(n+1)/2;
    }
    bool check(int n, int index, int mid, int maxSum){
        int rsize = n - index - 1;
        int lsize = index;
        long long sum=mid;
        int m = mid-1;
        
        if(m >= rsize){
            sum += val(m) - val(m-rsize);
        } else {
            sum += val(m) + 1*(rsize - m);
        }
        
        if(m >= lsize){
            sum += val(m) - val(m - lsize);
        } else {
            sum += val(m) + 1*(lsize - m);
        }
        
        return sum <= maxSum;
    }
    
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r=maxSum;
        int ans=1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(n, index, mid, maxSum)){
                ans=mid;
                l =mid+1;
            } else r=mid-1;
        }
        
        return ans;
    }
};