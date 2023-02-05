class Solution {
private:
    vector<int> convert(int num){
        
        string x = to_string(num);
        int n = x.length();
        vector<int> res(n);
        int idx = n-1;
        
        while(num!=0){
            int t = num%10;
            num = num/10;
            res[idx--] = t;
        }
        
        return res;
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        
        for(auto n:nums){
            vector<int> c =convert(n);
            res.insert(res.end(), c.begin(), c.end());
        }
        
        return res;
    }
};