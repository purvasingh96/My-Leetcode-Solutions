class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> wordset(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        
        int level = 1;
        
        while(!q.empty()) {
            
            int size = q.size();
            
            for(int i=0;i<size;i++) {
                
                string front = q.front();
                q.pop();
                
                for(int j=0;j<front.length();j++) {
                    
                    char temp = front[j];
                    
                    for(char c = 'a';c<='z';c++) {
                        
                        front[j] = c;
                        
                        string next = front;
                        
                        if(wordset.find(next) != wordset.end()) {
                            
                            if(next == endWord) return level+1;
                            
                            q.push(next);
                            wordset.erase(next);
                            
                        }
                        
                    }
                    
                    front[j] = temp;
                    
                }
                
            }
            
            level += 1;
            
            
        }
        
        return 0;
        
    }
};