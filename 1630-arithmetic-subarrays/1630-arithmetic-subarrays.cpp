class Solution {
private:
    bool check(vector<int>& nums, int l, int r){
        vector<int> temp;
        for(int i=l;i<=r;i++) temp.push_back(nums[i]);
        
        sort(temp.begin(), temp.end());
        int diff=temp[1] - temp[0];
        for(int i=2;i<temp.size();i++){
            if(temp[i] - temp[i-1]!=diff) return false;
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int i=0;i<l.size();i++){
            res.push_back(check(nums, l[i], r[i]));
        }
        
        return res;
    }
};