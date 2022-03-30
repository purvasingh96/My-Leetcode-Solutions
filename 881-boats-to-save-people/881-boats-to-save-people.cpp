class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        
        int boat = 0;
        sort(people.begin(), people.end());
        
        int left=0, right = people.size()-1;
        
        while(left<right) {
            
            
            int sum = people[left] + people[right];
            
            if(sum <= limit) {
                boat += 1;
                left += 1;
                right -=1;
            } else {
                
                if(people[left] > people[right]) {
                    boat+=1;
                    left+=1;
                } else if(people[right] > people[left]) {
                    boat+=1;
                    right-=1;
                } else {
                    boat+=2;
                    left+=1;
                    right-=1;
                }
                
            }
        } 
        
        if(left==right) boat+=1;
        
        return boat;
        
    }
};