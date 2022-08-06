class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<long long, long long> m;
        
        long long i=0, r=0;
        
        while(i<tasks.size()){
            
            if(m.find(tasks[i])==m.end()){
                m[tasks[i]] = r;
                
            } else{
                int diff = r-m[tasks[i]];
                
                if( diff  <= space){ 
                    r = (m[tasks[i]] + (space+1));
                    m[tasks[i]] = r;
                } else {
                    m[tasks[i]] = r;
                }
                
            }
            
            r+=1;
            i+=1;
            
        }
        
        return r;
        
    }
};