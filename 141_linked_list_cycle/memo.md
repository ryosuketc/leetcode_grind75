# 141. Linked List Cycle

https://leetcode.com/problems/linked-list-cycle/

## Comments

### step1

*   まあこれは何度も解いているので…
    *   https://github.com/ryosuketc/leetcode_arai60/pull/1/files
*   `set` と `unordered_set`、今回別に order いらないんだけど最悪計算量が悪くなる可能瀬尾を考えると、どっちでもいいときのデフォルトはとりあえず `set` でいいのかなあという気がしている。
    *   https://docs.google.com/document/d/11HV35ADPo9QxJOpJQ24FcZvtvioli770WWdZZDaLOfg/edit?tab=t.0#heading=h.rxnrgw1lj851
        *   どっちでもいいのではという風潮
*   https://cpprefjp.github.io/reference/set/set.html
    *   `contains` C++20 からなので割と新しい。なんでこれがなかったんだろう。まあ `count` とかすればいいのはそうだけど。
    *   `insert_range` なんてのも新しい。C++23

### step2

*   フロイドのうさぎとかめも一応書いてみた
*   https://github.com/nktr-cp/leetcode/pull/2/files
*   Python の `==` vs. `is` (値比較と、オブジェクト / メモリアドレス) の話
    *   たぶん C++ `==` は値の比較。オブジェクトの比較はポインタを使う (ポインタの `==` はメモリアドレスの比較)
    *   より厳密には `operator==` の実装依存、という話で、型によって違うという話だと思うが、個別の型でどう実装されているかまではチェックしていない
        *   https://en.cppreference.com/w/cpp/language/operators.html
        *   Java のジェネリクスみたいな話なんだと思っているが、ジェネリクス使った実装はやったことがない
*   TODO: 上記 cppreference のようなテンプレートを使った書き方とかはまだ勉強していない。テンプレートもいずれは勉強する


### step3

*   何度も解いているやつなので省略
