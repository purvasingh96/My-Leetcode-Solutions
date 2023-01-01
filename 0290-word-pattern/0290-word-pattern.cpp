class Solution {
private:
    
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, int> s2i;
        unordered_map<char, int> c2i;
        
        vector<string> arr;
        istringstream ss(s);
        string word;
        
        while(ss>>word){
            arr.push_back(word);
        }
        
        int c=0;
        for(auto x:arr) {
            if(s2i.find(x)==s2i.end()){
                s2i[x] = c++;
            }
        }
        
        int d=0;
        for(auto c:pattern){
            if(c2i.find(c)==c2i.end()){
                c2i[c] = d++;
            }
        }
        
        string s1="", s2="";
        for(auto x:arr){
            s1+= to_string(s2i[x]);
        }
        
        for(auto x:pattern){
            s2+= to_string(c2i[x]);
        }
        
        
        return s1 == s2;
    }
};