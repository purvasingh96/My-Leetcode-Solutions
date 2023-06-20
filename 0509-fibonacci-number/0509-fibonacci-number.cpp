class Solution {
private:
    vector<vector<int>> p = {{1, 1}, {1, 0}};
    vector<vector<int>> q = {{1, 1}, {1, 0}};
    
public:
    int fib(int n) {
        if(n<=1) return n;
        
        multiply(p, n-1);
        return p[0][0];
    }
    
    void multiply(vector<vector<int>>& a, int n){
        if(n<=1) return;
        
        multiply(a, n/2);
        helper(a, a);
        
        if(n%2!=0){
            helper(a, q);
        }
        
    }
    
    void helper(vector<vector<int>>& x, vector<vector<int>>& y){
        int a = x[0][0], b = x[0][1], c=x[1][0], d=x[1][1];
        int e = y[0][0], f = y[0][1], g=y[1][0], h=y[1][1];
        
        x[0][0] = a*e + b*g;
        x[0][1] = a*f + b*h;
        x[1][0] = c*e + d*g;
        x[1][1] = c*f + d*h;
        
    }
    
};