class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int left=0;
        long long ans=0;
        for(int right=0;right<prices.size();right++){
            if(right!=0 && prices[right-1]-prices[right]!=1){
                left=right;
            }
            
            ans += (right-left+1);
        }
        return ans;
    }
};