# 235. Lowest Common Ancestor of a Binary Search Tree

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

## Comments

### step1

*   どこかで解いた気はするがぱっと解き方わからなかった。
*   さっと答え見たが、BST であることを失念していた。p, q が同じ側にあれば探索を続け、別の側にあるとわかればそれが LCA
*   再帰での実装は簡単。特にコメントもなし。
*   `p_val` や `q_val` を変数に置くべきかは微妙なところ。別にアロー演算子でアクセスしてもいい気がする。ちょっとだけタイプするのが楽。

### step2
*   `Solution1`
    *   最初 `//Unreachable` のコメントだけ書いていたが、最後の `return root;` ないと怒られる。コードパスの中で全部 return しましょうということだと思うが、たぶんコンパイラが到達するか判断できないからだろう。
        *   > Line 35: Char 5: error: non-void function does not return a value in all control paths [-Werror,-Wreturn-type]
*   `Solution2`
    *   https://cpprefjp.github.io/reference/utility/unreachable.html
        *   `std::unreachable` というのがあるらしい。
            *   C++ だとこれを書いておくのがいいのかな
*   https://docs.google.com/document/d/11HV35ADPo9QxJOpJQ24FcZvtvioli770WWdZZDaLOfg/edit?tab=t.0#heading=h.magvbqix7jf7 は Python の話。
*   https://docs.google.com/document/d/11HV35ADPo9QxJOpJQ24FcZvtvioli770WWdZZDaLOfg/edit?tab=t.0#heading=h.atvjch3as46b
    *   C++ に関する話まとまってた
    *   `while (1)` でも回避できる。なるほど…読みにくい気がする？
        *   そもそも無限ループのコード書いたことないかも。この練習会だと時々出てくるが。たぶんプロダクションで加工というよりは、分岐をわかりやすくしたり、選択肢のひとつとして書いてみている、という気がする。
    *   https://github.com/seal-azarashi/leetcode/pull/21#discussion_r1777314992
        *   > (別のスレッドからこの変数をどうにかしていじるなどがなければ)到達しないと思うのですが「コンパイラが到達しないことを理解してくれるか」は別問題です。一般に、一重ループの停止性問題は決定不能なので、コンパイラが停止するかしないかを100%の精度で当てることはありません。あと、コードを読んでいる人にも、停止性問題を解かせないで欲しいのでコメントを残すなりしましょうか。私は無限ループへの書き換えを推します。
*   https://github.com/olsen-blue/Arai60/pull/59#discussion_r2030548887
    *   > まず、原理的に、コンピュータがコードが到達可能か不可能かを判定することは不可能です。これはチューリングマシンの停止性問題は判定できないことからいえます。一方で、Java や Rust などは、コンパイル時に型のチェックを真面目にしていて、到達不能なコードかはある程度判定します。しかし、不完全です。このため、正確に考えると到達不可能な箇所であったとしても、コンパイラには分からない場合が多々あります。こういったときに、そこの行に例外を書くことでコンパイル可能になります。何を言っているかというと、上のような事情ならば、例外を書くのはいいですが、そうでなければ、私はデッドコードは基本的に書かないほうがよいと思っています。(せいぜいコメントでいいでしょう。)
*   結局  `std::unreachable` はありなのかな？個人的には無限ループより良さそうに思うのだけど…。
    *   あ、これめっちゃ新しい (C++23)。なるほどそれ以前の環境を考えると無限ループなどが選択肢に入ってくるのか。
*   例外はなんか重いから C++ ではあまり使わないというのも聞いたことがある。
    *   https://www.reddit.com/r/cpp/comments/ikv9kv/should_i_use_c_exceptions/
        *   この辺見ると別に良さそうな気もするけど
*   `Solution3`
    *   無限ループは `while (1)` と `while (true)` どっちがいいんだろう。個人的にはちゃんと bool を渡す方が好きだけど

### step3

*   `std::unreachable` がかっこいい (無限ループを避けたい気持ち)
