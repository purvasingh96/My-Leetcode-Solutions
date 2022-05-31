class Solution {
private:
    string spaceJustifier(string s, int maxWidth, bool isLastLine){
        if(s.length() == maxWidth){
            return s;
        }
        
        int gap = maxWidth - s.length();
        int space=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') space+=1;    
        }
        if(space == 0 || isLastLine){
            // single word or last line, left justify
            while(gap!=0){
                s+=" ";
                gap-=1;
            }
            return s;
        }
        
        int eachSlotSpace = gap/space;
        int leftOverSpace = gap%space;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == ' ' && (eachSlotSpace >0 || leftOverSpace > 0)) {
                
                int totalSpace = eachSlotSpace + (leftOverSpace -- >0 ? 1:0);
                s.insert(i, totalSpace, ' ');
                i+= totalSpace;
                
            }
        }
        
        return s;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        string output = words[0];
        
        for(int i=1;i<words.size();i++){
            if(output.length() + words[i].length() + 1 <= maxWidth){
                output += " " + words[i];
            } else{
                output = spaceJustifier(output, maxWidth, 0);
                res.push_back(output);
                output = words[i];
            }
        }
        
        output = spaceJustifier(output, maxWidth, 1);
        res.push_back(output);
        return res;
    }
};