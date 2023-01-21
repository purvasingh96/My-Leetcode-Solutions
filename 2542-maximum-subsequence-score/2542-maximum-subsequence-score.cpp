class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        long long sum=0;
        long long ans=INT_MIN;
        for(int i=0;i<nums1.size();i++){
            res.push_back({nums2[i], nums1[i]});
        }
        
        sort(res.begin(), res.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=nums1.size()-1;i>=0;i--){
            pq.push(res[i].second);
            sum += res[i].second;
            
            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k) {
                ans = max(ans, (long long)(res[i].first*sum));
            }
        }
        
        return ans;
    }
};