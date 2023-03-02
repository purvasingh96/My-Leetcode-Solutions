class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int i=0, ans=0;
        for(int d=1;d<=1e5;d++){
            while(!pq.empty() && pq.top()<d){
                pq.pop();
            }    
            
            while(i<events.size() && events[i][0] == d){
                pq.push(events[i++][1]);
            }
            
            if(!pq.empty()){
                pq.pop();
                ans+=1;
            }
        }
        
        return ans;
    }
};