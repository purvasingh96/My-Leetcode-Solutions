class Solution {
private:
    bool isValid(string s){
        if(s.length() == 0 || s.length()>3) return false;
        if(s[0] == '0' && s.length()>1) return false;
       // cout<<"stoi s: "<<s<<"\n";
        long long val = stoi(s);
        if(val >= 0 && val <=255) return true;
        return false;
    }
    
    void backtrack(string s, int len1, int len2, int len3, unordered_set<string>& res){
        int n = s.length();
        //cout<<"i1: "<<i1<<" i2: "<<i2<<" i3: "<<i3<<"\n"; 
        string s1 = s.substr(0, len1);
        string s2 = s.substr(len1, len2);
        string s3 = s.substr(len1+len2, len3);
        string s4 = s.substr(len1+len2+len3);
        
        //cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<"\n";
        if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)){
            res.insert(s1+"."+s2+"."+s3+"."+s4);
            return;
        }
        
        for(int i=1;i<=3 && i<n;i++){
            for(int j = 1;j<=3 && j<n;j++){
                for(int k=1;k<=3 && k<n;k++){
                    backtrack(s, i, j, k, res);
                }
            }
        }
        
    }
public:
    vector<string> restoreIpAddresses(string s) {
        unordered_set<string> res;
        int n = s.length();
       for(int i=1;i<=3;i++){
            for(int j = 1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    if(i+j+k<n){
                       string s1 = s.substr(0, i);
                        string s2 = s.substr(i, j);
                        string s3 = s.substr(i+j, k);
                        string s4 = s.substr(i+j+k);

                        if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)){
                            res.insert(s1+"."+s2+"."+s3+"."+s4);
                        } 
                    }
                    
                }
            }
        }
        
        return vector(res.begin(), res.end());
    }
};