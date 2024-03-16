class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        
        int m = tasks.size();
        unordered_map<long long,long long>validTime;

        for(int i = 0; i < m; i++) {
            validTime[tasks[i]] = 0;
        }

        long long time = 0;
        for(int i = 0; i < m; i++) {
            if(validTime[tasks[i]] <= time) {
                validTime[tasks[i]] = time + space + 1;
                time++; 
            } else {
                time = validTime[tasks[i]];
                validTime[tasks[i]] = time + space + 1;
                time++;
            }
        }

        return time;
        
    }
};