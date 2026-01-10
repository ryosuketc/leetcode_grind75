# 3. Longest Substring Without Repeating Characters

https://leetcode.com/problems/longest-substring-without-repeating-characters/

## Comments

### step1

*   Arai60 で解いた問題なのでさらっと
    *   https://github.com/ryosuketc/leetcode_arai60/pull/37/files
*   愚直に O(n^2) で探索もできるなあ、などと思いつつ、sliding window として解く
*   最初 `chars_in_substring.contains(s[right])` を if 文にしたうえで `while` の条件に使ってしまっていたりしたが書いている途中でさっと書き直した。
*   最初 `max_substring_length = s.size()` で初期化してしまっており WA になった。
*   9:00 くらいで AC。あまり前解いたときのことを覚えていなかったので思ったより時間かかった。

### step2

*   step1 の弧ー０度はまあそれ自体は別にそれでいいかなという感じ。
    *   強いて言えば for でなく while で書いたほうが left, right に対称性があってきれいかもしれない
*   index 管理しておいて、left を一気に飛ばすやり方忘れていた。さっと書いてみる

### step3

*   skip
