class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) return {1};
        else if(rowIndex == 1) return {1, 1};
        
        vector<int> lastRow = {1, 1};
        
        
        for(int i=2;i<=rowIndex;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int start=0;start<lastRow.size()-1;start++){
                temp.push_back(lastRow[start] + lastRow[start+1]);
            }
            temp.push_back(1);
            lastRow = temp;
            temp.clear();
        }
        
        return lastRow;
    }
};