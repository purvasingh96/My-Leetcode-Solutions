/**
 * @param {string} s
 * @return {string[]}
 */

function dfs(s, temp, m, ans, center){
    let valid = true;
    for(let [k,v] of m.entries()){
        if(v>=2){
            m.set(k, m.get(k)-2);
            temp += k;
            dfs(s, temp, m, ans, center);
            temp = temp.slice(0, -1);
            m.set(k, m.get(k)+2);
            valid=false;
        }
    }
    
    if(valid){
        console.log("here");
        let rev = temp;
        rev = temp.split("").reverse().join("");
        ans.val.push(temp+center+rev);
    }
}


var generatePalindromes = function(s) {
    let m = new Map();
    let odd=0;
    let center="";
    let ans={val: []};
    
    for(let c of s) {
        m.set(c, (m.get(c)??0)+1);
    }
    console.log(m);
    
    for(let [k, v] of m.entries()){
        if(v%2!=0) {
            odd+=1;
            center=k;
        }
        console.log(odd);
        if(odd>1) return ans.val;
    }
    
    
    
    let temp="";
    dfs(s, temp, m, ans, center);
    return ans.val;
};