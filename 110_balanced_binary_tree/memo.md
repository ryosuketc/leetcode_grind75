# 110. Balanced Binary Tree

https://leetcode.com/problems/balanced-binary-tree/

## Comments

### step1

*   `SolutionWA`
    *   balanced の定義に少し迷った。hover したら定義が書いてあったのでその通りに実装してみた。
    *   > A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
    *   `getMaxHeight` としたけど、そもそも height というと、最大の高さの方を示すのが定義だと思うので `getHeight` で良かったかも。
*   `Solution1`
    *   `SolutionWA` は、`[1,2,2,3,null,null,3,4,null,null,4]` (左右一方向ずつに伸びている tree) のような入力に対して動かない (左右の tree の高さの差分しか見ていないので)。
    *   左右の tree に対しても `isBalanced` をチェックする必要がある
*   `Solution2`
    *   変数に置いたりしてちょっときれいにした。`Solution1` とそこまでは変わらないかな。
*   https://cpprefjp.github.io/reference/algorithm/max.html
*   https://cpprefjp.github.io/reference/cmath/abs.html

### step2

*   https://github.com/colorbox/leetcode/pull/13/files
    *   そもそも step1 の解法で、繰り返し呼び出しが発生していること (平均で O(nlogn) になっていること) を全く考慮していなかった
        *   (1) あとから考えるとなぜ悩んでいたんだろうという感じはするが、`step1.Solution2` のコード (というか `step1` のコードは全体的にそうだが) `getHeight` で高さを計算した後、さらに `isBalanced` を再帰的に呼び出している。`getHeight` の時点で全ての子を訪問して高さを計算しているのに、`isBalanced` で再度ノードにアクセスしている。
        *   (2) そのため計算効率が悪くなるわけだが、後で書いた `step2` では height と balanced の計算を一挙に行い、再帰で上に返していくだけなので、同じ node には 1 回しかアクセスせず O(n) となる。
        *   LeetCode では (1) をトップダウン、(2) をボトムアップとして説明している。間違ってはいないのだが、上記のように、「height で計算したものを、再度 balanced で計算している」と理解したほうが個人的には納得できた。したがって、height / balanced を一挙に求める (2) の解法の方が効率がよくなる。
    *   https://discord.com/channels/1084280443945353267/1206101582861697046/1230424716645240892
        *   > だいたい選択肢は3つで
        *   > isBalancedAuxiliary など補助関数で呼ぶことがまったく想定されていないような名前にする。
        *   > pair<int, bool> get_height_and_is_balanced(TreeNode* root) のようにペアを返す。
        *   > int get_height(TreeNode* root, bool* is_balanced) という風にポインターにバランスしているかを書き込む。
    *   メモ化で遅くなったと記載があるが、C++ だとどうやって計測するのがいいんだろう。
        *   canonical な方法はよくわからんが後述
*   `Solution1`
    *   計算量観点でもそうだが、`step1.Solution2` のように、height / balanced の処理が分かれていると、`isBalanced` と `getHeight` のそれぞれで処理を追わなければならず、視線移動が多くなる。`step2.Solution1` のようにまとめるとその観点でも見通しがよい。
    *   `pair` にしたが、場合によっては独自の構造体や class を定義することもあるかもしれない。
    *    `class` と `struct` については後述
    *   `Solution2`, `Solution3` も C++ っぽい気がするのでよい書き方だと思うが、今はこれが一番しっくり来るかも
*   `Solution2`, `Solution3`
    *   `balanced` を参照とポインタでそれぞれ書き込んでみた。
    *   ポインタの方は、書き込むときに de-reference したり、引数で渡すときもアドレスに変えないといけなかったりでちょっと手間。
    *   こういうケースでは引数として参照にするかポインタにするか違いはあるのだろうか。参照の方が単純に書きやすいので違いが特にないなら参照でいい気がする。どこかで、参照はポインタのシンタックスシュガーであるというのを見た気がする (e.g. ポインタだと `*balanced = true;` だが、参照だと `balanaced = true;` でアクセスや書き込みのときに明示的に de-reference する必要がない)
    *   ところで参照が、ある変数の別名 (エイリアス) であると理解してから、参照やポインタに対する認知負荷が大分減った。
*   https://google.github.io/styleguide/cppguide.html#Function_Names
    *   Google style だと関数名って `PascalCase` が推奨なんだ。std の命名は lower_snake が多いような気がするのと、LeetCode の命名が `lowerCamelCase` なので勘違いしていた。

#### C++ での実行時間計測

Python だと iPython と `timeit` (https://docs.python.org/ja/3.13/library/timeit.html) あたりを使って簡便に実行時間を試せるが、C++ だとどうやるんだろう。

*   LLM に聞くと `std::chrono::high_resolution_clock::now()` を出してきた。
    *   https://cpprefjp.github.io/reference/chrono/high_resolution_clock/now.html
*   またコンパイラの最適化で、本来実行したい箇所が (利用されていなかったりすると) 丸ごと削除されたりするらしい。
*   じゃあ最適化を着ればいいのでは、ということで `-O0` (オーゼロ) というオプションがあるらしい
    *   https://stackoverflow.com/questions/63386189/whats-the-difference-between-a-compilers-o0-option-and-og-option
*   今回の問題で試してみようと思ったが TreeNode を使ったテストデータを作るのが面倒だったので飛ばした…。別の問題で今度やってみたい。

#### C++ class and struct

*   C++ においては `struct` と `class` はほとんど同じものらしい。デフォルトのアクセス修飾子が、`struct` は `public` で、`class` は `private` らしい。
*   https://google.github.io/styleguide/cppguide.html#Variable_Names
    *   data member について、`class` は trailing underscore をつけて、`struct` ではつけないらしい。なんで？
        *   後で気付いたが、メンバ変数の名前と、コンストラクタに渡す引数名で衝突しないようにか
*   https://google.github.io/styleguide/cppguide.html#Structs_vs._Classes
    *   > Use a struct only for passive objects that carry data; everything else is a class.
    *   今回の問題だと、この関数内部でしか使わない想定なので `class` が良さげかな、と思っていたが、単にデータのみ持つクラスと言う意味では別に `struct` でもいいのかもしれない。まあ迷ったら `class` にしろと書いてあるので一旦それで。
*   メンバ初期化子リスト
    *   コンストラクタの本体で `height_ = height` みたいにやると、`height_` が一旦初期化されてから、`height` が代入されるので効率が悪いらしい。
    *   https://zenn.dev/melos/articles/7b7fbc5fd41270
    *   https://cpprefjp.github.io/lang/cpp11/initializer_lists.html
*   `Solution4` 書いてみた。C++ で `class` や構造体はまだあまり使ったことがないので機会があればまた書く。
*   TODO: C++ の `static` よくわかってないので今度調べる。

### step3

*   5:00 くらい
*   `include` 忘れてた。`pair` は `utility`
*    `height_balanced` と `balanced` はちょっとわかりにくい。`balanced` で一気にやってもいいかも。
