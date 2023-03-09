class Solution {
private:
    bool canEat(vector<int>& piles, int k, int h){
        long long t=0;
        for(auto p:piles){
            t += p/k;
            if(p%k!=0) t+=1;
        }
        
        return t<=h;
    }
        
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(), piles.end());
        int ans=-1;
        while(l<=r){
            int m = (l + (r-l)/2);
            if(canEat(piles, m, h)){
                ans=m;
                r=m-1;
            } else l=m+1;
        }
        return ans;
    }
};