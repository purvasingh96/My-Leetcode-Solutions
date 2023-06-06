class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size()<=2) return true;
        sort(arr.begin(), arr.end());
        int diff = arr[0]-arr[1];
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i] - arr[i+1]!=diff) return false;
        }
        return true;
    }
};