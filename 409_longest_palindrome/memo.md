# 409. Longest Palindrome

https://leetcode.com/problems/longest-palindrome/

## Comments

### step1

*   最初、与えられた文字列の substring の中で最長の文字列を返すのかと思って 10 分くらい考えながら書いていた。途中で問題設定が違っているのに気付いたのでやり直し
    *   https://leetcode.com/problems/longest-palindromic-substring/editorial/
    *   ちなみに今書きかけのやり方だと、start_index は center の文字の想定なので、奇数長さの palindrome しか取れない。
    *   正しくは偶数長さも考える必要があるので、2 つ index (e.g. `i, j`)を取るようにして、`i, i` と `i, i + 1` から expand していく必要がある
*   気を取り直して問題を見直してから再度取り組み
    *   割とすんなり書いた。

### step2

*   このあたりの解放がある
    *   LeetCode の editorial とほぼ同じ解答になっているようだ
    *   https://github.com/huyfififi/coding-challenges/pull/17/files
    *   https://github.com/Kitaken0107/GrindEasy/pull/27/files
*   step1 の解法以外だと、概ね map を構築しながら 1 pass O(n) (vs. O(2n) in step1) で解く方法と、set を使って 2 ずつ足しながら書く方法がある。
    *   ただ個人的には 2 pass が一番素直で、面接で期待されるとしたらこれかなと思う。ここからどう発展問題にしていくかはあまり思いつかないけど、上記の substr の問題に切り替えるとかかな。あまり今の問題の延長線上という感じはしないけど。
*   else なくそうとすると `Solution1` のようには書けるけど読みにくく感じる。`Solution2` でも、`step1.Solution` でもどっちでもいいかなという気がする。

### step3

*   省略
