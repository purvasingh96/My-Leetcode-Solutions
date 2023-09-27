impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        let mut cache1 = vec![0; 26];

        for c in s.chars() {
            let index = (c as u8 - b'a') as usize;
            cache1[index] += 1;
        }

        for c in t.chars() {
            let index = (c as u8 - b'a') as usize;
            cache1[index] -= 1;
            if cache1[index] < 0 {
                return c;
            }
        }

        'a'
    }
}
