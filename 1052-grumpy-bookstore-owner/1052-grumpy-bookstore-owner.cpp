class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int alreadySatisfied=0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0){
                alreadySatisfied+=customers[i];
                customers[i]=0;
            }
        }
        
        int maxval=0, current=0;
        for(int i=0;i<customers.size();i++){
            current += customers[i];
            if(i>=minutes){
                current -= customers[i-minutes];
            }
            maxval = max(maxval, current);
        }
        
        return maxval + alreadySatisfied;
    }
};