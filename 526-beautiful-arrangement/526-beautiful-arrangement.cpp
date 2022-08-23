class Solution {
private:
    void dfs(int idx, int n, int& count, int& mask) {
        if(idx>n) {
            count+=1;
            return;
        }
        
        for(int i=1;i<=n;i++){
            if( (((mask >> i) & 1) == 0) &&  (i%idx == 0 || idx%i == 0)) {
                mask = ( mask | (1<<i) );
                dfs(idx+1, n, count, mask);
                mask = (mask ^ (1<<i));
            }
            
        }
        
    }
    
public:
    int countArrangement(int n) {
        int mask=0, count=0;
        dfs(1, n, count, mask);
        return count;
        
    }
};