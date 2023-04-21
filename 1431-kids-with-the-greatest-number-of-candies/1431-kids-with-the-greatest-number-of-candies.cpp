class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        for(auto x:candies){
            ans.push_back((x+extraCandies >= m));
        }
        return ans;
    }
};