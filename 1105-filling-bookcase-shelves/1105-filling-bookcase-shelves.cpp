class Solution {
    int dfs(int idx, int currWidth, int maxHeightSoFar, int shelfWidth, vector<vector<int>>& books, unordered_map<string, int>& dp){
        if(currWidth> shelfWidth || currWidth> shelfWidth && idx>=books.size()) return INT_MAX;
        else if(idx >= books.size()) return maxHeightSoFar;
        string t=to_string(idx)+"#"+to_string(currWidth)+"#"+to_string(maxHeightSoFar);
        // keep on same shelf
        
        if(dp.find(t)!=dp.end()) return dp[t];
        
        int nextShelf = maxHeightSoFar + dfs(idx+1, books[idx][0], books[idx][1], shelfWidth, books, dp);
        maxHeightSoFar = max(maxHeightSoFar, books[idx][1]);
        
        int sameShelf = dfs(idx+1, currWidth+books[idx][0], maxHeightSoFar, shelfWidth, books, dp);
        
        
        
        return dp[t] =  min(sameShelf, nextShelf);

    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        unordered_map<string, int> dp;
        
        return dfs(1, books[0][0], books[0][1], shelfWidth, books, dp);
    }
};