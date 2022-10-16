class Solution {
public:
    int maximumRobots(vector<int>& times, vector<int>& costs, long long budget) {
        deque<int> q;
        long long sum=0, j=0;
        int maxans = INT_MIN;
        
        for(int i=0;i<times.size();i++){
            sum += costs[i];
            
            while(!q.empty() && q.back() < times[i]){
                q.pop_back();
            }
            
            q.push_back(times[i]);
            
            while(!q.empty() && (j<=i) && ((i-j+1)*sum + q.front()) > budget){
                sum -= costs[j];
                if(q.front() == times[j]){
                    q.pop_front();
                }
                j+=1;
            }
            
            int len = (i-j+1);
            maxans = max(maxans, len);
        }
        
        return maxans;
    }
};