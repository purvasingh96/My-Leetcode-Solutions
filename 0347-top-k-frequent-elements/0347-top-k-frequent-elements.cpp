class Solution {
private:
    // number, freq
    int partition(vector<pair<int, int>>& nums, int start, int end){
        int pivot = nums[end].second;
        int i=start-1, j=start;
        
        for(;j<end;j++){
            if(nums[j].second >= pivot){
                i+=1;
                swap(nums[i], nums[j]);
            }
        }
        i+=1;
        swap(nums[i], nums[end]);
        return i;
    }
    
    void quickSort(vector<pair<int, int>>& nums, int start, int end, int k){
        if(start<=end){
            int pivot = partition(nums, start, end);
            if(k <= pivot){
                quickSort(nums, start, pivot-1, k);
            } else {
                quickSort(nums, pivot+1, end, k);
            }
        }
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto x:nums){
            m[x]+=1;
        }
        vector<pair<int, int>> res;
        for(auto x:m){
            res.push_back({x.first, x.second});
        }
        quickSort(res, 0, res.size()-1, k);
        for(auto x:res){
            cout<<x.first<<" ";
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(res[i].first);
        }
        
        return ans;
    }
};