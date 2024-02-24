class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> low, high;
        vector<double> ans;
        
        for(int i=0;i<nums.size();i++){
            if(i>=k){
                // remove the put of window element
                if(nums[i-k] <= *low.rbegin()){
                    low.erase(low.find(nums[i-k]));
                } else {
                    high.erase(high.find(nums[i-k]));
                }
            }
            
            low.insert(nums[i]);
            
            // balance
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
            
            if(high.size() > low.size()){
                low.insert(*high.begin());
                high.erase(high.begin());
            }
            
            
             if(i>=k-1){
                double median;
                if(k%2==0){
                    median = ((double)*low.rbegin() + (double)*high.begin()) * 0.5;
                } else {
                    median = (double)(*low.rbegin());
                }
                ans.push_back(median);    
            }
            
        }
        
        return ans;
    }
};