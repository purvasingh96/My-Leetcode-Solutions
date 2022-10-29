class Solution {
private:
    int isPossible(int mid, int h, vector<int>& piles){
        long long total = 0;
        
        for(int i=0;i<piles.size();i++){
            
                total += piles[i]/mid;
                if(piles[i]%mid!=0) total+=1;
            
        }
        
        return total <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right=*max_element(piles.begin(), piles.end());
        int ans=0;
        
        
        
        while(left<=right){
            int mid = left + (right-left)/2;
            if(isPossible(mid, h, piles)){
                ans=mid;
                right=mid-1;
            } else left = mid+1;
        }
        
        return ans;
    }
};