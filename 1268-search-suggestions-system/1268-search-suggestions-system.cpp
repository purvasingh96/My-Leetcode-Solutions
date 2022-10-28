class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string s) {
        sort(products.begin(), products.end());
        string prefix="";
        int l=0;
        int n = products.size(), m = s.length();
        
        vector<vector<string>> res(m, vector<string>());
        
        for(int i=0;i<s.length();i++){
            
            auto start = lower_bound(products.begin(), products.end(), s.substr(0, i+1));
            auto end = lower_bound(start, min(start+3, products.end()), s.substr(0, i)+(char)(s[i]+1) );
            
            res[i] = vector<string>(start, end);
            
        }
        
        return res;
        
    }
};