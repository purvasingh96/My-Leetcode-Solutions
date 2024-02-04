class Solution {
private:
    double helper(double x, int n, map<int, double>& dp){
        if(n==0) return 1;
        if(n==1) return x;
        if(dp.find(n)!=dp.end()) return dp[n];
        
        double prod1 = helper(x, n/2, dp);
        return dp[n] = n%2==0 ? prod1 * prod1 : prod1*prod1*x;
    }
public:
    double myPow(double x, int n) {
        map<int, double> dp;
        int power = n/2;
        if(power < 0) power = power*-1;
        
        double ans = helper(x, power, dp);
        double res = n%2==0 ? ans*ans : ans*ans*x;
        
        return n<0 ? 1/res : res;
        
    }
};