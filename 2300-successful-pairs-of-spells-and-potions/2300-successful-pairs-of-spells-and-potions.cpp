#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        int n = potions.size();
        
        for(auto spell:spells){
            ll target = ceil((double)success/spell);
            int index = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
            if(index == n) res.push_back(0);
        
            else if(index ==0){
                long long prod = (ll)spell * (ll)potions[0];
                if(prod < success) res.push_back(0);
                else res.push_back(n);
            } else {
                res.push_back(n-index);
            }
        }
        
        return res;
    }
};