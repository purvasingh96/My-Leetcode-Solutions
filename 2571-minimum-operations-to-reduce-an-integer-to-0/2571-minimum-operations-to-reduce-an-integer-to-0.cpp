class Solution {
private:
    int lowerBound(int n){
        int i=0;
        while(pow(2,i)<=n){
            i+=1;
        }
        //cout<<(i-1)<<"\n";
        return i-1;
    }
    
    int dfs(int n){
        if(n<=0) return 0;
        if(n&(n-1)==0) return 1;
        
        int left = lowerBound(n);
        int right = left+1;
        int d1 = n-pow(2, left), d2 = pow(2, right)-n;
        if(d1 < d2) return 1+dfs(d1);
        else return 1+dfs(d2);
    }
public:
    int minOperations(int n) {
        if(n&(n-1)==0) return 1;
        return dfs(n);
    }
};