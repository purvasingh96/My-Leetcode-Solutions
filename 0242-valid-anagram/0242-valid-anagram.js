/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    let s1 = s.split("").sort().join("");
    let t1 = t.split("").sort().join("");
    console.log(s1, t1);
    return s1==t1;
};