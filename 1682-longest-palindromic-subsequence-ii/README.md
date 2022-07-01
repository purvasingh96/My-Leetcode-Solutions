<h2><a href="https://leetcode.com/problems/longest-palindromic-subsequence-ii/">1682. Longest Palindromic Subsequence II</a></h2><h3>Medium</h3><hr><div><p>A subsequence of a string <code>s</code> is considered a <strong>good palindromic subsequence</strong> if:</p>

<ul>
	<li>It is a subsequence of <code>s</code>.</li>
	<li>It is a palindrome (has the same value if reversed).</li>
	<li>It has an <strong>even</strong> length.</li>
	<li>No two consecutive characters are equal, except the two middle ones.</li>
</ul>

<p>For example, if <code>s = "abcabcabb"</code>, then <code>"abba"</code> is considered a <strong>good palindromic subsequence</strong>, while <code>"bcb"</code> (not even length) and <code>"bbbb"</code> (has equal consecutive characters) are not.</p>

<p>Given a string <code>s</code>, return <em>the <strong>length</strong> of the <strong>longest good palindromic subsequence</strong> in </em><code>s</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "bbabab"
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest good palindromic subsequence of s is "baab".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "dcbccacdb"
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest good palindromic subsequence of s is "dccd".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 250</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>
</div>