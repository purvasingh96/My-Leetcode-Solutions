class MyCompare{
public:
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // store idx in pq
        // till pq.top is within (i to j) range: keep max as pq.top()
        // pop pq.top
        
        priority_queue<vector<int>, vector<vector<int>>, MyCompare> pq;
        for(int i=0;i<k;i++){
            pq.push({i, nums[i]});
        }
        
        vector<int> res;
        res.push_back(pq.top()[1]);
        int start = 1;
        for(int end=k;end<nums.size();end++){
            pq.push({end, nums[end]});
                while(!pq.empty() && (pq.top()[0] <start)){
                    pq.pop();
                }
            
            res.push_back(pq.top()[1]);
            start+=1;
        }
        
        return res;
        
    }
};