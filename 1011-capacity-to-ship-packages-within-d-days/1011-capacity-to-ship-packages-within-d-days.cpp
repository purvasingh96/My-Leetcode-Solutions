class Solution {
private:
    bool canShip(vector<int>& weights, int maxCap, int days){
        int d = 0;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            if(sum > maxCap){
                sum = weights[i];
                d+=1;
                if(d > days){
                    return false;
                }
            } 
        }
        // ship last batch
        d+=1;
        return d<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        cout<<high;
        
        while(low<high){
            int maxCap = low+(high-low)/2;
            //cout<<"mnaxcap: "<<maxCap<<" ship?: "<<canShip(weights, maxCap, days)<<"\n";
            if(canShip(weights, maxCap, days)){
                high = maxCap;
            } else {
                low = maxCap+1;
            }
            
        }
        return low;    
    }
    
};