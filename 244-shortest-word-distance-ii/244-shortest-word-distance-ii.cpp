class WordDistance {
private:
    map<string, vector<int>> m;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i=0;i<wordsDict.size();i++){
            m[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto indices_1 = m[word1];
        auto indices_2 = m[word2];
        int mindist=INT_MAX;
        
        for(auto x:indices_1){
            for(auto y:indices_2){
                mindist = min(mindist, abs(y-x));
            }
        }
        
        return mindist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */