class Solution {
public:
    int bitwiseComplement(int n) {
        // reference: https://www.geeksforgeeks.org/find-ones-complement-integer/
        if(n==0) return 1;
        int bits = floor(log2(n)) + 1;
        
        return ((1 << bits)-1) ^ n;
    }
};