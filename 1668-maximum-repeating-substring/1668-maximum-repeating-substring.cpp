class Solution {
private:
    vector<int> generateLPS(string s){
        int n = s.length();
        vector<int> lps(n, 0);
        
        for(int j=0, i=1;i<n;){
            if(s[i]==s[j]){
                lps[i]=j+1;
                i+=1;
                j+=1;
            } else{
                if(j==0){
                    i+=1;
                } else{
                    j=lps[j-1];
                }
            }
        }
        
        return lps;
    }
public:
    int maxRepeating(string sequence, string word) {
        if(word == sequence) return 1;
        int n = word.length();
        int maxc=0;
        
        while(word.size() < sequence.length()){
            
            word+=word;
        }
        
        vector<int> lps = generateLPS(word);
       
        for(int i=0, j=0;i<sequence.length();){
            if(word[j] == sequence[i]){
                i+=1;
                j+=1;
                
            } else {
                
                //cout<<j<<" "<<n<<" "<<maxc<<" "<<(j/n)<<"\n";
                if(j==0) i+=1;
                else j =lps[j-1];
            }
            
            if(j%n==0){
                maxc = max(maxc, j/n);
            }
        }
        
       
        return maxc;
        
    }
};