class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int ans=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        int n = intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=pq.top()){
                pq.pop();
                pq.push(intervals[i][1]);
            } else {
                pq.push(intervals[i][1]);
            }
        }
        
        return pq.size();
    }
};