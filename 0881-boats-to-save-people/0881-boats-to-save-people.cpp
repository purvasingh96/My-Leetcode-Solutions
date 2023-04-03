class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l=0, r=people.size()-1;
        
        int count=0;
        while(l<=r){
            if(l==r) {
                count+=1;
                break;
            }
            if(people[l] + people[r] > limit){
                count+=1;
                r-=1;
            } else {
                count+=1;
                l+=1;
                r-=1;
            }
        }
        
        return count;
        
    }
};