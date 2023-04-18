function uniquePathsWithObstacles(g: number[][]): number {
    
    let m: number = g.length;
    let n: number = g[0].length;
    if(g[m-1][n-1]==1) return 0;

    
    let dp:number[][] = Array.from(Array(m), () => new Array(n).fill(0));
    if (!g[0][0]) dp[0][0] = 1;

      for (let i = 0; i < m; i++) {
    if (g[i][0] === 1) break
    dp[i][0] = 1
  }
  for (let j = 0; j < n; j++) {
    if (g[0][j] === 1) break
    dp[0][j] = 1
  }

  for (let i = 1; i < m; i++) {
    for (let j = 1; j < n; j++) {
      if (g[i][j] === 1) {
        dp[i][j] = 0
      } else {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
      }
    }
  }

  return dp[m - 1][n - 1];
    
};