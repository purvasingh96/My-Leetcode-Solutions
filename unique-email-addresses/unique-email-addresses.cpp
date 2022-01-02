class Solution {
public:
    string returnCleanEmail(string s) {
        
        string local_name="", domain_name="";
        
        int i=0;
        for(i=0;i<s.length();i++) {
            if(s[i] == '@') {
                break;
            }
        }
        
        local_name = s.substr(0, i);
        domain_name = s.substr(i);
        int j=0;
        
        for(j=0;j<local_name.length();j++) {
            
            if(local_name[j] == '.') {
                local_name.erase(local_name.begin()+j);
            } else if(local_name[j] == '+') {
                break;
            }
        }
        
        string cleanEmail = local_name.substr(0, j) + domain_name;
        
        //cout<<s<<" "<<cleanEmail<<"\n";
        
        return cleanEmail;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        map<string, int> m;
        
        for(auto email:emails) {
            m[returnCleanEmail(email)] += 1;
        }
        
        return m.size();
    }
};