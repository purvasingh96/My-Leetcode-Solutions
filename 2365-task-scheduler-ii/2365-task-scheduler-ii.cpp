class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> m;
        
        for(auto x:tasks) m[x]=0;
        
        long long t=1;
        for(int i=0;i<tasks.size();i++){
            if(m[tasks[i]] <= t) {
                m[tasks[i]]=t+space+1;
            } else if(m[tasks[i]]==0){
                m[tasks[i]]=t+space+1;
            } else {
                t = m[tasks[i]];
                m[tasks[i]] = t+space+1;
            }
            t+=1;                
        }
        
        return t-1;
        
    }
};