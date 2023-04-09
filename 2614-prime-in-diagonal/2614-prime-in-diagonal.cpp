class Solution {
private:
    
    void primeVal(vector<bool>& prime, int n){
        for(int p=2;p*p<=n;p++){
            if(prime[p] == true){
                for(int i=p*p;i<=n;i+=p){
                    prime[i]=false;
                }
            }
        }
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        vector<bool> prime(4000001, true);
        primeVal(prime, 4000001);
        int sum = nums.size()-1;
        int maxval =0;
        
        for(int i=0;i<nums.size();i++){
        
                
                if(nums[i][i]>=2 && prime[nums[i][i]]){
                    maxval = max(maxval, nums[i][i]);
                } 
                
                if(nums[i][nums.size() - i - 1]>=2 && prime[nums[i][nums.size() - i - 1]]) {
                    maxval = max(maxval, nums[i][nums.size() - i - 1]);
                }
            
        
    }
                                return maxval;
                                }
                                
};