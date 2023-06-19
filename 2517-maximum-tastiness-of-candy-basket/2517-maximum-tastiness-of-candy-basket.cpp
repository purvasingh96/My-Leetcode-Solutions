class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l = 1, r=price.back() - price[0];
        int ans=0;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            int cnt=1;
            
            for(int i=1, j=0;i<price.size();i++){
                if(price[i] - price[j] >= mid){
                    cnt+=1;
                    j=i;
                }
            }
            
            if(cnt>=k){
                ans=mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        
        return ans;
        
    }
};