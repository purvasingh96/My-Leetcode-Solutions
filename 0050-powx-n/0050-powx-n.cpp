class Solution {
private:
    double power(double x, int n, unordered_map<int, double>& dp){
        if(n==0){
            return 1.0;
        }
        if(n==1){
            return x;
        }
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        
        if(n%2==0){
            return dp[n] = power(x, n/2, dp) * power(x, n/2, dp);
        }
        
        return dp[n] = power(x, n/2, dp) * power(x, n/2, dp) * x;
    }
public:
    double myPow(double x, int n) {
        unordered_map<int, double> dp;
        if(n<0){
            double ans = power(x, n, dp);
            return 1/ans;
        }
        return power(x, n, dp);
    }
};