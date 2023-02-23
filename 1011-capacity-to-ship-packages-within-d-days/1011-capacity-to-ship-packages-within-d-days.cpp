class Solution {
private:
    bool possible(int target, vector<int>& weights, int days){
        int d=1;
        int sum=0;
        
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            if(sum > target){
                d+=1;
                if(d > days) return false;
                sum = weights[i];
            } 
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // min: max weight max: sum of all weights
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        int ans=-1;
        while(left<right){
            int mid = left + (right-left)/2;
            if(possible(mid, weights, days)){
                ans=mid;
                right=mid;
            } else {
                left = mid+1;
            }
        }
        
        return left;
        
    }
};