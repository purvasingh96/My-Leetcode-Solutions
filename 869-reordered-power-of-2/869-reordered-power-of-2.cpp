class Solution {
private:
    // 23456
    vector<int> returnArray(int n){
        vector<int> digits(10, -1);
        
        while(n!=0){
            int t = n%10;
            if(digits[t]==-1) {
                digits[t]=0;
            }
            digits[t]+=1;
            n=n/10;
        }
        
        return digits;
    }

public:
    bool reorderedPowerOf2(int n) {
        vector<int> digitsN = returnArray(n);
        
        for(int i=0;pow(2,i)<=1e9;i++){
            int temp = pow(2, i);
            if(temp == n) return true;
            vector<int> digitsR = returnArray(temp);
            if(digitsR == digitsN) return true;
        }
        
        return false;
        
    }
};