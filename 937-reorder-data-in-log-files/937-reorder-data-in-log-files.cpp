class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
      
        stable_sort(logs.begin(), logs.end(), [](const string& a, const string& b){
            int i = a.find(" ");
            int j = b.find(" ");
            
            if(isdigit(a[i+1])){
                
                if(isdigit(b[j+1])) return false;
                else return false;
                
            } else {
                
                if(isdigit(b[j+1])){
                    return true;
                } else{
                    
                    if(a.substr(i+1) == b.substr(j+1)) {
                        return a.substr(0, i) < b.substr(0, j);
                    }
                    
                    return a.substr(i+1) < b.substr(j+1);
                }
                
                
                
            }
            
            
        });
        
        //letter.insert(letter.end(), digit.begin(), digit.end());
        return logs;
        
    }
};