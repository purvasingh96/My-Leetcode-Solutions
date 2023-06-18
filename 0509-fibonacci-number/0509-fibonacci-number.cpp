class Solution {
private:
    vector<vector<int>> f = {{1, 1}, {1, 0}};
    vector<vector<int>> m = {{1, 1}, {1, 0}};
public:
    int fib(int n) {
        if(n<=1) return n;
        multiply(f, n-1);
        return f[0][0];
    }
    
    void multiply(vector<vector<int>>& f, int n){
        if(n<=1) return;
        multiply(f, n/2);
        
        helper(f, f);
        
        if(n%2!=0){
            helper(f, m);
        }
    }
    
    void helper(vector<vector<int>>& f1, vector<vector<int>>& f2){
        int a = f1[0][0], b = f1[0][1], c = f1[1][0], d = f1[1][1];
        int e = f2[0][0], f = f2[0][1], g = f2[1][0], h = f2[1][1];
        
        f1[0][0] = (a*e + b*g);
        f1[0][1] = (a*f + b*h);
        f1[1][0] = (c*e + d*g);
        f1[1][1] = (c*f + d*h);
    }
    
    
};