class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // escape sequence
        string res = "";
        
        for(auto x:strs){
            string temp = "";
            for(int i=0;i<x.length();i++) {
                if(x[i] == '/'){
                    temp += "//";
                } else {
                    temp.push_back(x[i]);
                }
            }
            temp += "/:";
            res += temp;
        }
        
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        string temp="";
        int n = s.length();
        
        //cout<<s;
        
        for(int i=0;i<n;i++){
            if(i+1<n && s.substr(i, 2) == "//"){
                temp += "/";
                i+=1;
            } else if(i+1<n && s.substr(i, 2) == "/:"){
                res.push_back(temp);
                i+=1;
                temp ="";
            } else {
                temp.push_back(s[i]);
            }
            
        }
        
        return res;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));