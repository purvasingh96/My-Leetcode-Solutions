class Solution {
private:
    int partition(vector<pair<int, int>>& nums, int start, int end){
        int pivot = nums[end].second;
        int i=start-1, j=start;
        
        while(j<end){
            if(nums[j].second <= pivot){
                i+=1;
                swap(nums[i], nums[j]);
            }
            j+=1;
        }
        
        i+=1;
        swap(nums[i], nums[end]);
        return i;
    }
    
    void quickSort(vector<pair<int, int>>& nums, int start, int end, int k){
        if(start <= end){
            int pivot = partition(nums, start, end);

            if(pivot == k){
                return;
            } else if(k < pivot){
                quickSort(nums, start, pivot-1, k);
            } else if(k > pivot){
                quickSort(nums, pivot+1, end, k);
            }
        }
        
    }
    
    int dist(vector<int>& points){
        int x1 = points[0], y1 = points[1];
        return pow(x1, 2) + pow(y1, 2);
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> nums;
        for(int i=0;i<points.size();i++){
            nums.push_back({i, dist(points[i])});
        }
        quickSort(nums, 0, nums.size()-1, k);
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            int idx = nums[i].first;
            ans.push_back(points[idx]);
        }
        
        return ans;
    }
};