
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res="";
        sort(nums.begin(), nums.end(), [](const int& a, const int& b){
            
            string sa = to_string(a);
            string sb = to_string(b);
            int m = sa.length(), n=sb.length();

            int i=0, j=0;

            while(i<m && j<n && sa[i]-'0' == sb[i]-'0'){
                i+=1;
                j+=1;
            }

            if(i==m || j==n) {
                string ab = sa+sb;
                string ba = sb+sa;
                
                int k=0;
                while(k<ab.length() && ab[k] == ba[k]){
                    k+=1;
                }
                
                return ab[k] > ba[k];
            }
            
            return sa[i]-'0' > sb[j]-'0';
           
        });
        
        //for(auto x:)
        
        if(nums[0] == 0) return "0";
        
        for(auto x:nums) res+= to_string(x);
        return res;
    }
};