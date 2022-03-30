class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        
        int boat = 0;
        sort(people.begin(), people.end());
        
        int left=0, right = people.size()-1;
        
        while(left<=right) {
            
            boat+=1;
            int sum = people[left] + people[right];
            
            if(sum <= limit) {
                
                left += 1;
            } 
            
            right-=1;
        } 
        
        
        return boat;
        
    }
};