class Solution {

public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
	int res = 0, m = size(A), n = size(A[0]);
	for (int row = 0; row < m; row++)
		for (int col = 1; col < n; col++)
			A[row][col] += A[row][col - 1];
	//         cursum, occurences
	unordered_map<int, int> mp;
	for (int colStart = 0; colStart < n; colStart++) {
		for (int colEnd = colStart; colEnd < n; colEnd++) {
			int cursum = 0;
			mp = {{0, 1}};
			for(int row = 0; row < m; row++){
				cursum += A[row][colEnd] - (colStart ? A[row][colStart - 1] : 0);    
				// mp[sum-target] will give number of submatrices found having sum as 'sum - target'
				res += mp[cursum - target];
				mp[cursum]++;
			}
		}
	}
	return res;    
}
        
};