class Solution {
public:
    bool isPowerOfFour(int n) {
        vector<int> isPower;
        for(int i=0;pow(4,i)<=n;i++){
            isPower.push_back(pow(4, i));
        }
        
        return find(isPower.begin(), isPower.end(), n)!=isPower.end();
    }
};