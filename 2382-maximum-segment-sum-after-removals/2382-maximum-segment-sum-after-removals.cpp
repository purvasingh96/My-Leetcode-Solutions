class Solution {
public:
    #define ll long long
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<ll> pre(n, 0);
        pre[0] = nums[0];
        
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+nums[i];
        }
        
        // stores removed indices
        set<int> removed_indices;
        removed_indices.insert(-1);
        removed_indices.insert(n);
        
        multiset<ll> segment_sum;
        segment_sum.insert(pre.back());
        
        vector<ll> ans;
        
        for(int i=0;i<n;i++){
            
            int curr = removeQueries[i];
            
            auto it = removed_indices.lower_bound(curr);
            int right = *it;
            int left = *(prev(it));
            
            ll cur_sum = pre[right-1] - (left==-1?0:pre[left]);
            
            segment_sum.erase(segment_sum.find(cur_sum));
            
            ll left_sum = (curr==0?0:pre[curr-1]) - (left==-1?0:pre[left]);
            ll right_sum = (right==0?0:pre[right-1]) - pre[curr];
            
            segment_sum.insert(left_sum);
            segment_sum.insert(right_sum);
            
            removed_indices.insert(curr);
            
            ans.push_back(*(segment_sum.rbegin()));
            
        }
        
        return ans;
        
    }
};