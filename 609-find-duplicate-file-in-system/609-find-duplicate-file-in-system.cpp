class Solution {

public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> m;
        vector<vector<string>> res;
        
        for(auto path:paths) {
            path+=" ";
            string dir="";
            
            int pos = path.find(" ");
            dir = path.substr(0, pos);
            
            string file = path.substr(pos+1);
            int end=0;
            
            while((end=file.find(" "))!=string::npos){
                int start = file.find("(");
                string filename = file.substr(0, start);
                string content = file.substr(start+1, end-start-2);
                
                string fpath = dir+"/"+filename;
                
                m[content].push_back(fpath);
                
                file=file.substr(end+1);
            }
            
            
        }
        
        for(auto x:m){
            if(x.second.size()>1){
                res.push_back(x.second);
            }
        }
        
        return res;
        
    }
};