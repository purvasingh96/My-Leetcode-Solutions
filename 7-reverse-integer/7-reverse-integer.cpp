class Solution {
public:
    int reverse(int x) {
        long long z=x;
        bool isNegative = z<0?true:false;
        if(z<0) z=z*-1;
        if(z> INT_MAX || z<INT_MIN) return 0;
        
        string val = to_string(z);
        std::reverse(val.begin(), val.end());
        
        long long y = stoll(val);
        
        if(isNegative) y = y*-1;
        
        if(y> INT_MAX || y<INT_MIN) return 0;
        return y;
    }
};