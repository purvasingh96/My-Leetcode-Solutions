class Solution {
private:
    bool canShip(vector<int>& weights, int mid, int days){
        int total=0, d=0;
        
        for(int i=0;i<weights.size();i++){
            
            if(total+weights[i] > mid){
                d += 1;
                total=weights[i];
            } else {
                total += weights[i];
            }
        } 
        
        //cout<<"mid: "<<mid<<" total days: "<<d<<"\n";
        
        return d+1 <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int right = accumulate(weights.begin(), weights.end(), 0);
        int max_e = *max_element(weights.begin(), weights.end());
        int left = max(max_e, right/days);
        int ans=0;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            
            if(canShip(weights, mid, days)){
                ans=mid;
                right=mid-1;
            } else left = mid+1;
        }
        
        return ans;
    }
};