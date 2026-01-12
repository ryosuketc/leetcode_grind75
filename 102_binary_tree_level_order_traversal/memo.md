# 102. Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/

## Comments

### step1

*   Arai60 で解いた問題
*   https://github.com/ryosuketc/leetcode_arai60/pull/26/files
*   とりあえず各 level ごとに処理する方法。queue を使おうかと思ったが nodes (current level) と next_nodes の入れ替えだけで pop などするわけではなかったので vector のまま書いた
*   とはいえ久々に解いたので12:00くらいかかっった。ちょっとlevelの区切りをどうやって見つけるんだったか悩んでしまった。

### step2

*   一応 queue を使う方法。
*   あとは上記自分の解答のように (node, level) の tuple を queue に入れていく方法もあるが、level ごとに処理する今回の方法がよりわかりやすいとは思う。

### step3

*   skip
