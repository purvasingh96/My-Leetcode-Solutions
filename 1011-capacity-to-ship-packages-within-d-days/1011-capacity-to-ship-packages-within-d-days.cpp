class Solution {
private:
    bool canShip(vector<int>& weights, int days, int target){
        int sum=0, d=0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            if(sum > target){
                d+=1;
                if(d > days){
                    return false;
                }
                sum = weights[i];
            }
        }
        d+=1;
        return d <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin(), weights.end(), 0);
        
        int ans=h;
        
        while(l<h){
            int mid = l + (h-l)/2;
            cout<<"mid: "<<mid<<" canship: "<<canShip(weights, days, mid)<<"\n";
            if(canShip(weights, days, mid)){
                ans = min(ans, mid);
                h=mid-1;
            } else {
                l = mid+1;
            }
        }
        
        if(canShip(weights, days, l)){
            ans = min(ans, l);
        }
        return ans;
    }
};