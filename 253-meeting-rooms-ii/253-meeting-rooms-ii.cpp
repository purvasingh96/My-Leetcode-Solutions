class MyCompare{
public:
    bool operator()(const vector<int>& a, const vector<int>& b){
        if(a[1]!=b[1]) return a[1] > b[1];
        
        return a[0] > b[0];
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, MyCompare> pq;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size();i++){
            
            if(pq.empty() || nums[i][0] < pq.top()[1]){
                pq.push(nums[i]);
            } else {
                pq.pop();
                pq.push(nums[i]);
            }
            
        }
        
        return pq.size();
    }
};