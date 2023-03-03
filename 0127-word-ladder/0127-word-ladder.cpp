class Solution {
public:
    int ladderLength(string start, string end, vector<string>& res) {
       if(find(res.begin(), res.end(), end)==res.end()) return 0;
       unordered_map<string, vector<string>> m;
        for(auto word:res){
            for(int i=0;i<word.length();i++){
                string temp = word.substr(0, i) + "*" + word.substr(i+1);
                m[temp].push_back(word);
            }
        }
        
        unordered_map<string, bool> visited;
        visited[start]=true;
        queue<pair<string, int>> q;
        
        int level=1;
        q.push({start,level});
        while(!q.empty()){
            auto f = q.front();q.pop();
            string s = f.first;
            int level = f.second;
            //cout<<s<<" "<<level<<"\n";
            if(s==end) return level;
            
            for(int i=0;i<s.length();i++){
                string temp = s.substr(0, i) + "*" + s.substr(i+1);
                for(auto word:m[temp]){
                    if(visited.find(word)==visited.end()){
                        visited[word]=true;
                        q.push({word, level+1});
                    }
                }
            }
            
            
        }
        
        return 0;
    }
};