class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==0) low+=1;
        return low>high?0:(high-low)/2+1;
    }
};