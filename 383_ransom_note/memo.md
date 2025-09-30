# 383. Ransom Note

https://leetcode.com/problems/ransom-note/

## Comments

### step1

*   最初、「重複を許すset」みたいなデータ構造(検索や削除はO(1))があればいいのにな、と思った
    *   step2 で追記。`std::multiset`, `std::unordered_multiset`
*   あったような気がするがぱっとわからなかったので map で実装してみた (unordered_map でもよかったが、平均計算量のよい map にしてみた。そこまで深い考察はない)。
*   しばらく間が空いたので範囲 for とか一瞬書き方を忘れていた。
*   5:00 くらいで書いてみた

### step2

*   int の map に `[]` でアクセスするとき、初期値は 0 になるので、`if (!char_count.contains(c) || char_count[c] == 0)` は単に `if (char_count[c] == 0)` でよかった気はする
    *   `[]` アクセスとか、`at` とかまだちょっと苦手
        *   `[]`
            *   範囲外アクセスをチェックしない。map だと新しい要素が作られる
        *   `at`
            *   範囲外アクセスで例外を投げる。map ではキーが存在しなければ例外を投げる
        *   基本的には `at` の方が安全、`[]` の方がチェックしない分ちょっとだけ高速

*   `std::multiset`
    *   https://cpprefjp.github.io/reference/set/multiset.html
*   `std::unordered_multiset`
    *   https://cpprefjp.github.io/reference/unordered_set/unordered_multiset.html

*   `multiset` 使ってみた。
    *   `Solution1WA`: 最初、`erase` が 1 個だけ要素を削除すると思っていたが、キーに合致するものは全部削除するらしい
    *   `Solution1AC`: 正しくは iterator を使うみたい。`multiset` だときれいに (`Solution1WA` のように) 書ける想像をしていたが、これなら別に map でもいいかなという感じ
        *   ちみに `std::multiset.find` は O(logn)、`std::unordered_multiset.find` は avg. O(1), worst O(n)
            *   まあ内部実装 (binary tree vs. hash) を考えれば当然
            *   https://cpprefjp.github.io/reference/set/multiset/find.html
            *   https://cpprefjp.github.io/reference/unordered_set/unordered_multiset/find.html
*   `Solution2`
    *   > ransomNote and magazine consist of lowercase English letters.
        *   この制約見逃していた。これあるなら 26 文字なので、長さ 26 vector を用意して ++, -- していっても解ける
    *   vector 使ったが可変長配列である必要はないかもしれない。
    *   一応サイズと初期値を与えられるらしい。
        *   `std::vector<int> char_count(26, 0);` みたいに、`variable_name(args)` という書き方でコンストラクタを呼ぶの、なんかちょっと慣れない。
            *   Python なら `variable_name = ClassName(args)` とか
            *   C++ でも `std::vector<int> char_count = std::vector<int>(26, 0);` と書くことはできる。一旦オブジェクト作ってから変数に束縛するので無駄な処理がありそうだけど。
        *   vector の初期化といえば initializer list とかもある。まあこれはまた違う話。
            *   https://cpprefjp.github.io/lang/cpp11/initializer_lists.html
*   `insert` vs. `emplace`
    *   `emplace` の「要素を直接つくる」とは何かと思ったが、そもそも `insert` はコンテナ外で一時オブジェクトを作ってそれをムーブしているらしい
    *   なので基本的には `emplace` (C++11)の方が効率が良く、そちらを使う
    *   TODO: ムーブといえば、社内の詳しい人は move semantics について苦笑いしていた。あれが登場したときは色々あったらしい。そもそも move semantics の話よくわかっていないのでそのうちに調べる

### step3

*   いくつかパターン書いたので今回は省略
