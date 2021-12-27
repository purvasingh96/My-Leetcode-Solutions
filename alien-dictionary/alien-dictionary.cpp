class Solution {
public:
    string alienOrder(vector<string>& words) {
        /*
        order: topological sort algo
        pseudo code:
            - traverse the dict, populate indegree and adj_list
            - if is_matched()[1]==small_word.back() return ""
            - topological sort algo
        TC:
        SC:
        */
        
        map<char, vector<char>> adj_list;
        map<char, int> indegree;
        queue<char> q;
        int z=0;
        string res="";
        
        for(int i=0;i<words.size();i++) {
            for(auto c:words[i]) {
                indegree[c]=0;
            }
        }
        
        for(int i=0;i<words.size()-1;i++) {
            string s = words[i];
            string t = words[i+1];
            
            int l1 = s.length();
            int l2 = t.length();
            
            
            
            // refernce: https://www.geeksforgeeks.org/stdmismatch-examples-c/
            auto mispair = mismatch(s.begin(), s.end(), t.begin());
            
            if(s.length() > t.length()) {
                
                if(s.rfind(t,0) == 0) {
                    return "";
                }
                
            }
            
            
            
            for(int i=0;i<min(l1, l2);i++) {
                
                if(s[i]!=t[i]) {
                    indegree[t[i]]+=1;
                    adj_list[s[i]].push_back(t[i]);
                    break;
                }
                
            }
            
            
        }
        
        
        for(auto i:indegree) {
            if(i.second == 0) {
                q.push(i.first);
                z+=1;
            }
        }
        
        if(z == 0) return "";
        
        while(!q.empty()) {
            
            char f = q.front();
            q.pop();
            res+= f;
            
            for(auto c:adj_list[f]) {
                indegree[c] -= 1;
                if(indegree[c] == 0) {
                    q.push(c);
                    z+=1;
                }
            }
            
        }
        
        
        if(z!=indegree.size()) return "";
        
        return res;
        
        
    }
};