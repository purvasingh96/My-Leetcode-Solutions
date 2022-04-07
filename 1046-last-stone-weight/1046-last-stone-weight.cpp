class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int max_weight = stones[0];
        
        for(auto x:stones) max_weight = max(max_weight, x);
        
        vector<int> buckets(max_weight+1);
        
        for(auto weight:stones) {
            buckets[weight] +=1;
        }
        
        int biggest_weight = 0;
        int curr_weight = max_weight;
        
        while(curr_weight > 0) {
            
            if(buckets[curr_weight] == 0) curr_weight -= 1;
            
            else if(biggest_weight == 0) {
                
                buckets[curr_weight] %= 2;
                
                if(buckets[curr_weight] == 1) biggest_weight = curr_weight;
                
                curr_weight -=1;
                
            } else {
                
                buckets[curr_weight] -= 1;
                
                if(biggest_weight - curr_weight <= curr_weight) {
                    cout<<biggest_weight - curr_weight<<"\n";
                    buckets[biggest_weight - curr_weight] += 1;
                    biggest_weight = 0;
                } else {
                    biggest_weight -= curr_weight;
                }
                
                
                
            }
            
            
            
        }
        
        return biggest_weight;
        
    }
};