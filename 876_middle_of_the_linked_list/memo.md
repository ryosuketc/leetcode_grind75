# 876. Middle of the Linked List

https://leetcode.com/problems/middle-of-the-linked-list/

## Comments

### step1

*   slow, fast を使うか、あるいは 2 pass でノードの総数を求めてから 2nd pass で返すというのもできるだろう
*   slow, fast が 1 pass なのと、シミュレーションする限りシンプルに書けそうだったのでそうした。
*   ただ production なら後者の方法で書くかもしれない。読み手にとってはより直感的だと思う
*   問題の例に与えられている、node が偶数、奇数のときでそれぞれシミュレーションした

```cpp
// 1,1 -> 2,3 -> 3,5 (fast->next == nullptr)
// 1,1 -> 2,3 -> 3,5 -> 4,nullptr (fast == nullptr)
```

*   あとは edge case として node 数が 0, 1, 2 のあたりも脳内でテストした。
*   7:00 くらいで AC

### step2

*   2 pass も一応書いた。思ったより冗長になったけど、一応こっちのほうがわかりやすいかなという気はする。
    *   size (length) を求める関数だったので、例に倣って 1-index にしたが 0-index でもよかったかもしれない。ただその場合 head == nullptr のとき何を返すのかとか、関数名どうするかとか考慮すべき要素が増える気はする。
    *   two "middle"s のとき first を返してください、みたいなのにも対応しやすいとは思う。

### step3

*   step1 のほうがよいかなという気がする。`fast`, `slow` の変数名は好みがあるかもしれない。
