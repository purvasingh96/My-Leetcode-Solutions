class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int c=0;
        
        for(int i=0;i<ages.size();i++){
            int target = (ages[i]/2) + 7;
            int low_index = upper_bound(ages.begin(), ages.end(), target) - ages.begin();
            int high_index = upper_bound(ages.begin(), ages.end(), ages[i]) - ages.begin();
            
            c += max(high_index - low_index - 1, 0);
            
        }
        return c;
    }
};