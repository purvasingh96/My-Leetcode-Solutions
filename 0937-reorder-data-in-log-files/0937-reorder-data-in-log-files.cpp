class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
       stable_sort(logs.begin(), logs.end(), [](const string& a, const string& b){
           
           int i = a.find(" ");
           int j = b.find(" ");
           
           if(isdigit(a.back())) return false;
           if(isdigit(b.back())) return true;
           
           string aa = a.substr(a.find(" "));
           string bb = b.substr(b.find(" "));
           
           if(aa==bb) return a<b;
           return aa<bb;
           
       });
        
        return logs;
    }
};