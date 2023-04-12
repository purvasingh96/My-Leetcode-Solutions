let i: number=0;

function dfs(s: string): string {
    let res = "";
    while (i < s.length && s[i] !== "]") {
      if (!isNaN(parseInt(s[i]))) {
        let k = 0;
        while (!isNaN(parseInt(s[i]))) {
          k = k * 10 + parseInt(s[i]) - parseInt("0");
          i += 1;
        }
        i += 1;
        let decodedString = dfs(s);
        i += 1;
        while (k--) {
          res += decodedString;
        }
      } else {
        res += s[i++];
      }
    }
    return res;
  }

function decodeString(s: string): string {
    //s = "["+s+"]";
    //let i: number=0;
    i=0;
    return dfs(s);
};