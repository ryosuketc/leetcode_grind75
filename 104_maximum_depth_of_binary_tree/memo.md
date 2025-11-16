# 104. Maximum Depth of Binary Tree

https://leetcode.com/problems/maximum-depth-of-binary-tree/

## Comments

### step1

*   まあ再帰で書こうかな、と思って 4:00 で AC
*   `root` みたいな引数の関数を使うとなんか認知不可が高い気がする (`root` は木全体の根であって、再帰それぞれの根であるという感覚がないからな気がする)

### step2

*   引数名を `node` (`root` ではなく) にしたかったので、`GetDepth` のような private 関数を使おうかと思ったが、結局 depth って定義上はより深い方を返す (そうでないなら、右と左の pair を返すとかはできるけど) ということになり、そうすると `maxDepth` と全く同じ機能になるので分ける必要もない気がした。
*   一方でまあ深さを追加の引数として取って再帰するなら別の関数にする意味はある
*   Arai60 で解いている
    *   https://github.com/ryosuketc/leetcode_arai60/pull/21/files
    *   再帰のスタックオーバーフローとかを気にするなら、上記の通り iterative な解き方もあるかもしれない。上記は Python で書いたが、C++ なら `step2.Solution` みたいな感じかな。

### step3

*   省略
