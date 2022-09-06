class Solution {
private:
    bool feasible(int threshold, vector<int>& weights, int days){
        int total=0;
        int d=1;
        for(auto w:weights){
            total += w;
            if(total > threshold){
                total = w;
                d+=1;
                if(d>days) return false;
            }
        }
        return true;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while(left<right){
            int mid = left + (right-left)/2;
            if(feasible(mid, weights, days)){
                right=mid;
            } else{
                left=mid+1;
            }
        }
        
        return left;
    }
};