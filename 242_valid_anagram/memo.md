# 242. Valid Anagram

https://leetcode.com/problems/valid-anagram/

## Comments

### step1

*   `map` と `unordered_map`
    *   https://cpprefjp.github.io/reference/map/map.html
    *   https://cpprefjp.github.io/reference/unordered_map/unordered_map.html
    *   `map` は binary tree、`unordered_map` は hash で実装されているらしい。
    *   ああだから `map` の計算量は平均・最悪とも O(logN) で
    *   `unordered_map` は償却 O(1)、ただし最悪 O(N) なのか (合ってる？)
        *   hash strategy がイケてなくて全部衝突すると O(N)
    *   全く同じことが `set` vs. `unordered_set` でも言える
    *   なんか最悪計算量が悪くなるの嫌だし、この辺は知識として把握したうえで、なんでもないなら `map`, `set` を使うほうが安定しているのでいい気がする…というのが私の好みではあるんだが Modern C++ における一般的な engineering practice としてはどうなんだろう。
*   `unordered_map` の例にこんなのがある
    *   https://cpprefjp.github.io/reference/unordered_map/unordered_map.html

```cpp
std::unordered_map<std::string, int> um{ {"1st", 1}, {"2nd", 2}, {"3rd", 3}, };
```
*   contd.
    *   前コメントもらった initializer list というやつだと思うけど、`um {...}` とスペース開けるのが普通では？違うのかな。
    *   https://cpprefjp.github.io/lang/cpp11/initializer_lists.html
    *   C++ (だけではないと思うけど)、スペースとかインデントとか改行とか割と無頓着だよな。どっちがいいかはわからないけど。

```cpp
std::vector<int> v1 = {1, 2, 3};
std::vector<int> v2 {1, 2, 3};

```

*   `at` と `[]`
    *   `at` は範囲外で例外を投げる。
    *   `[]` は未定義動作
    *   https://stackoverflow.com/questions/9376049/when-should-i-use-vectorat-instead-of-vectoroperator
    *   基本的に `at` を使うほうがいいのかな？
    *   `map` の存在しないキーにアクセスした場合、指定された型の初期値で初期化されるらしい (`int` なら `0`、ポインタなら `nullptr` などというように)
        *   ローカル変数の宣言のみの場合は未定義動作になるはずだが、これはどういう違いなんだろう。
    *   `find` というのもあるみたい
        *   https://cpprefjp.github.io/reference/map/map/find.html
        *   見つからならなかったら `end()` というのを返すらしい
*   `std::unordered_map::count`、そもそもキーがユニークなんだから意味ある？と思った。使い所はよくわからんけど (`mulptimap`？あたりとインターフェース揃えるためなのかな)
*   `Solution`
    *   `map` に対する for 文をどう書くのがいいか苦闘した。
    *   他の解答も眺めて `for (const auto& [s_char, s_char_count] : s_char_to_count)` で Python の unpack みたいに書けることを知った。
    *   const 参照で受けるべきか値で受けるべきかまだよくわからん
    *   そもそも `map` を範囲 for で回すと pair が返るっぽいので、こんな感じでアクセスする。可読性が低い気がするが慣れの問題？
        

```cpp
        for (const auto& pair : s_char_to_count) {
            if (pair.second != t_char_to_count[pair.first]) {
                return false;
            }
        }
```

*   contd.
    *   `getCountMap` はコピーが発生する可能性を考えると書き込み先を引数でもらった方がいいのかな
    *   https://github.com/ryosuketc/leetcode_grind75/pull/5#discussion_r2274647457
        *   *追記:* いや、参照 (かポインタ) を引数に渡せばコピーはされないのか。

### step2

*   このバリエーションはいくつもあって、今回は 2 つ map を使ったけどこんな感じでも解けるだろう。
    *   sort して全部比べる。
    *   1 map だけ用意して、最後に全要素が `0` になっているか確認する
        *   https://github.com/eito2002/LeetCode/pull/2/files
    *   sort のやり方確認しようと思ったけど、他の要素でお腹いっぱいなのでまた今度。
*   `Solution1`
    *   pair をそのまま使う
    *   この場合、`pair` という変数名は普通なのかな
*   `Solution2`
    *   find を使う
    *   この場合、`it` という変数名は普通なのかな
    *   C++ の場合、`pair` とか `it` みたいな、それ自体はあまり重要じゃないんだけど、みたいな中間変数的なものが発生しがちで、それには短い名前で済ませたくなる。C++ の慣習としてはありなのかな？
*   `Solution3`
    *   getCountMap に書き込み先を渡す
    *   https://github.com/ryosuketc/leetcode_grind75/pull/5#discussion_r2274647457 を模倣してなんとか書いてみたけどポインタとか参照とか de-reference とか大分わけわからなくなってきた。時間をかけてゆっくり考えるとまあ意味はわかるんだけど。

### step3

*   step1 のやり方で、`getCountMap` だけ、`s` を参照で受け取るようにした。コピーは NRVO とか信じてなんとかならないだろうか…
    *   追記:
        *   いや、参照 (かポインタ) を引数に渡せばコピーはされないのか。
        *   参照渡しをする、しないによるコピー (引数に渡す時のコピー) と RVO のとき問題になっているコピーを同一視してしまっていた気がする。
        *   前者は、ポインタか参照を関数の引数に渡せばよい。
        *   後者は値を返すときにコピーされる問題で、嫌なら最初から書き込み先のアドレスを渡して関数内でそこに書いていくか、あるいは (N)RVO が効くことを期待するか
        *   …という理解であっているかな。
*   (N)RVO の理解は浅い気がする
    *   https://cpprefjp.github.io/lang/cpp17/guaranteed_copy_elision.html
