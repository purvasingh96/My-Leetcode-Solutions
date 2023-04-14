#define pp pair<int, int>

class MyComp{
public:
    bool operator()(pp& a, pp& b){
        // i, val
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pp, vector<pp>, MyComp> pq;
        int i=0;
        for(i=0;i<k;i++){
            pq.push({i, nums[i]});
        }
        vector<int> res;
        res.push_back(pq.top().second);
        
        while(i<nums.size()){
            pq.push({i, nums[i]});
            if(i-pq.top().first+1 <=k){
                res.push_back(pq.top().second);
            } else {
                while(!pq.empty() && i-pq.top().first+1 > k){
                    pq.pop();
                }
                if(!pq.empty()) res.push_back(pq.top().second);
            }
            i+=1;
        }
        
        return res;
    }
};