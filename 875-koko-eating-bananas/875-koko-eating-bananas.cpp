class Solution {
private:
    bool feasible(int threshold, vector<int>& piles, int h){
        int d=0;
        
        for(auto pile:piles){
            if(pile <= threshold) d+=1;
            else {
                d += (pile/threshold);
                if(pile%threshold!=0) d+=1;
            }
            
            if(d > h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        while(left<right){
            int mid = left + (right-left)/2;
            if(feasible(mid, piles, h)) right=mid;
            else left=mid+1;
        }
        
        return left;
    }
};