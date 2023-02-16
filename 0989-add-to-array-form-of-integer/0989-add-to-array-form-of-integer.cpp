class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> res;
        int carry = 0, i=n-1, pos=n-1;
        
        while(i>=0){
            int val = num[i] + (k%10);
            if(carry!=0) val += carry;
            res.push_back(val%10);
            carry = val/10;
            i-=1;
            k=k/10;
        }
        
        while(k!=0){
            
                int val = k%10;
                val += carry;
                res.push_back(val%10);
                carry = val/10;
            k=k/10;
            
        }
        
        if(carry!=0) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
        
    }
};