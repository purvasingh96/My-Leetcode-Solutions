class MyComp{
 public:
    bool operator()(int& a, int& b){
        return a > b;
    }
};
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, MyComp> pq;
        
        for(int i=0;i<intervals.size();i++){
            if(pq.size()==0 || intervals[i][0]<pq.top()){
                pq.push(intervals[i][1]);
            } else {
                pq.pop();
                pq.push(intervals[i][1]);
            }
        }
        
        return pq.size();
    }
};