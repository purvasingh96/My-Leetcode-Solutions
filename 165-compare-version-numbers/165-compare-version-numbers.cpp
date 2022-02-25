class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        vector<string> v1, v2;
        string item1, item2;
        char delim = '.';
        
        
        
        while(getline(ss1, item1, delim)) {
            v1.push_back(item1);
        }
        
        while(getline(ss2, item2, delim)) {
            v2.push_back(item2);
        }
        
        int n1 = v1.size();
        int n2=v2.size();

        
        int revision1, revision2;
        
        for(int i=0;i<max(n1, n2);i++) {
            revision1 = i<n1 ? stoi(v1[i]):0;
            revision2 = i<n2 ? stoi(v2[i]):0;
            if(revision1 != revision2) return revision1 < revision2 ? -1:1;
            
        }
        
        return 0;
        
    }
};