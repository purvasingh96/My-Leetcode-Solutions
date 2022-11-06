class Solution {
private:
    int parseNum(string& s, int& i){
        int temp=0;
        
        for(;i<s.length() && isdigit(s[i]);i++){
            temp = temp*10 + (s[i]-'0');
        }
        return temp;
    }
    
    int parseExp(string s, int& i){
        
        vector<int> nums;
        char op = '+';
        
        for(;i<s.length() && op!=')';i++){
            
            int temp = 0;
            if(s[i] == ' ') continue;
            int n = s[i] == '(' ? parseExp(s, ++i) : parseNum(s, i);
            
            if(op == '+') nums.push_back(n);
            else if(op == '-') nums.push_back(-n);
            
            op = s[i];
            
        }
        
        int res=0;
        while(nums.size()!=0) {
            res += nums.back();
            nums.pop_back();
        }
        
        return res;
    }
    
public:
    int calculate(string s) {
        int i=0;
        return parseExp(s, i);
    }
};