class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0;i<intervals.size();i++){
            if(pq.empty() || pq.top() > intervals[i][0]){
                pq.push(intervals[i][1]);
            } else {
                pq.pop();
                pq.push(intervals[i][1]);
            }
        }
        return pq.size();
    }
};