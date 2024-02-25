class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int expected=1;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=expected){
                k-=1;
                if(k==0){
                    return expected;
                }
                i-=1;
            }    
            expected+=1;
        }
        while(--k){
            expected+=1;
        }
        return expected;
    }
};