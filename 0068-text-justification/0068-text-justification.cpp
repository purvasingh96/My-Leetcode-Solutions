class Solution {
private:
    string leftJustify(vector<string>& s, int maxWidth, int sz){
        string res="";
        int extraSpace = maxWidth - sz;
        for(auto word:s) {
            res+=(" "+word);
        }
        res = res.substr(1);
        while(extraSpace--) res +=" ";
        return res;
    }
    
    string justifyValue(vector<string>& v, int maxWidth, int sz){
        
        int spaces = (v.size()-1);
        int diff = maxWidth - sz;
        bool foundFirstSpace=false;
        int extraSpaceLeft = spaces==0?diff:diff%spaces;
        
        int evenSpaces = spaces==0?0:diff/spaces;        
        string res="";
        
        for(auto word:v){
            res += word;
            res+=" ";
          
            
            int temp = evenSpaces;
            while(temp-- >0) res+=" ";
            
            if(extraSpaceLeft){
                res+=" ";
                extraSpaceLeft-=1;
            }
        }
        
        while(extraSpaceLeft--) res+=" ";
        
       return res.substr(0, maxWidth); 
    }
    
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> q;
        vector<string> res;
        
        int spaces=0;
        int sz=0, i=0, wordsLength=0;
        
        while(i<words.size()){
            q.push_back(words[i]);
            wordsLength += words[i].length();
            sz= (wordsLength + (q.size()-1));
            
            if(sz > maxWidth){
                q.pop_back();
                sz-=(words[i].length()+1);
                res.push_back(justifyValue(q, maxWidth, sz));
                
                sz=0;
                q.clear();
                wordsLength=0;
            } else{
                i+=1;
            }
        }
        
        if(sz>0) res.push_back(leftJustify(q, maxWidth, sz));
        
        return res;
    }
};