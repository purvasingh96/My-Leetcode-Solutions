class Solution {
private:
    int dfs(int idx, int currWidth, int maxHeightSoFar, int shelfWidth, vector<vector<int>>& books, unordered_map<string, int>& dp){
        
        if(currWidth> shelfWidth) return INT_MAX;
        if(idx >= books.size()) return maxHeightSoFar;
        string t=to_string(idx)+"#"+to_string(currWidth)+"#"+to_string(maxHeightSoFar);
        
        if(dp.find(t)!=dp.end()) return dp[t];
        
        // keep curr book in next shelf
        int nextShelf = maxHeightSoFar + dfs(idx+1, books[idx][0], books[idx][1], shelfWidth, books, dp);
        
        // includes curr book in the same shelf
        maxHeightSoFar = max(maxHeightSoFar, books[idx][1]);
        int sameShelf = dfs(idx+1, currWidth+books[idx][0], maxHeightSoFar, shelfWidth, books, dp);
        
        
        // minimum max height achievable.
        return dp[t] = min(sameShelf, nextShelf); 
        
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        unordered_map<string, int> dp;
        return dfs(1, books[0][0], books[0][1], shelfWidth, books, dp);
    }
};