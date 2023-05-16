class Solution {
public:
    /*
    
    Questions that involve calculating prefix and suffix arrays often exhibit certain trademarks or characteristics. Here are some common indicators of questions that involve prefix and suffix arrays:

Array Manipulation: The question typically involves manipulating an array or a list of elements in some way, such as performing arithmetic operations, applying specific transformations, or calculating certain properties based on the array.

Cumulative Calculations: The problem often requires computing cumulative values or properties of the array, such as cumulative sums, cumulative products, cumulative maximum/minimum, or cumulative bitwise operations.

Prefix and Suffix Arrays: The question explicitly mentions or hints at the need to calculate prefix or suffix arrays. It may ask for specific values or properties related to the prefix or suffix arrays, such as the sum of all prefix sums, the maximum subarray sum ending at each index, or the product of all suffix products starting from each index.

Optimizations or Efficiency: Questions involving prefix and suffix arrays often require optimizing the algorithm or finding an efficient solution. They may ask for the minimum number of operations required, the maximum or minimum possible value achievable, or the time complexity of the algorithm.

Dynamic Programming: Many questions related to prefix and suffix arrays can be solved using dynamic programming techniques. They often involve breaking down the problem into smaller subproblems and building the solution incrementally based on the prefix or suffix array calculations.
    
    
    */
    
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n, 0);
        vector<long long> suffix(n, 0);
        vector<long long> vals(n, 0);
        for(int i=0;i<n;i++) vals[i] = nums[i];
        
        prefix[0] = vals[0];
        suffix[n-1] = vals[n-1];
        
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] | vals[i];
         }
        
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] | vals[i];
        }
        
        vals.insert(vals.begin(), 0);
        prefix.insert(prefix.begin(), 0);
        suffix.insert(suffix.begin(), 0);
        vals.push_back(0);
        prefix.push_back( 0);
        suffix.push_back(0);
        
        
        for(int i=1;i<=n;i++){
            vals[i] = (long long)(vals[i] * pow(2, k));
        }
        
        //for(int i=0;i<vals.size();i++) cout<<vals[i]<<" ";
        
        long long ans=0;
        for(int i=1;i<=n;i++) {
            long long x = vals[i] | prefix[i-1] | suffix[i+1];
            ans = max(ans, x);
        }
        
        return ans;
        
    }
};