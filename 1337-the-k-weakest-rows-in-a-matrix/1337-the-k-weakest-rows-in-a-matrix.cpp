class MyCompare{
  public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first!=b.first) return a.first < b.first;
        return a.second < b.second;
    };
};


class Solution {
public:
    
    int strength(vector<int>& nums) {
        
        int left = 0, right = nums.size()-1;
        
        while(left <= right) {
            
            int mid = left + (right-left)/2;
            
            if(nums[mid] == 1) {
                left = mid+1;
            } else {
                right = mid-1;
            }
            
        }
        
        return left;
        
    }
    
    
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> pq;
        
        for(int i=0;i<mat.size();i++){
            
            int str = strength(mat[i]);
            pq.push(make_pair(str, i));
            
            if(pq.size() > k) {
                pq.pop();
            }
            
        }
        
        vector<int> res(k);
        
        for(int i=k-1;i>=0;i--) {
            res[i]  =pq.top().second;
            pq.pop();
        }
        
        return res;
        
        
    }
};