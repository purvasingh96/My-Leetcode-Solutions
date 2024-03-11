class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int maxSum = INT_MIN;
        int l=0;
        
        for(int r=0;r<fruits.size();r++){
            m[fruits[r]]+=1;
            
            if(m.size() > 2){
                while(l<r && m.size()>2){
                    m[fruits[l]]-=1;
                    if(m[fruits[l]] == 0){
                        m.erase(m.find(fruits[l]));
                    }
                    l+=1;
                }
            }
            
            int sum = r-l+1;
            maxSum = max(sum, maxSum);

        }
        
        return maxSum;
    }
};