class Solution {
private:
    void back_track(int n, string& temp, int open, int close, vector<string>& res){
        
        
        if(temp.length() == 2*n){
            res.push_back(temp);
            return;
        }
        
        if(open<n){
            temp+="(";
            back_track(n, temp, open+1, close, res);
            temp.pop_back();
        }
        
         if(close<open){
            temp+=")";
            back_track(n, temp, open, close+1, res);
            temp.pop_back();
        }
        
        
        
    } 
public:
    
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string> res;
        back_track(n, temp, 0, 0, res);
        return res;
    }
};