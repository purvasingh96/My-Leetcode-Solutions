class Solution {

public:
    bool reorderedPowerOf2(int n) {
        string n_str = to_string(n);
        sort(n_str.begin(), n_str.end());
        
        for(int i=0;(1<<i)<=1e9;i++){
            int temp = (1<<i);
            string temp_str = to_string(temp);
            sort(temp_str.begin(), temp_str.end());
            if(temp_str == n_str) return true;
        }
        
        return false;
        
    }
};