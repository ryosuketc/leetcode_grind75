# 226. Invert Binary Tree

https://leetcode.com/problems/invert-binary-tree/

## Comments

### step1

*   Python で解いたことがあるのでそれを模倣する (Arai 60 ではなかったようだが) (`Solution1`)
*   `nullptr` を返したのでいいのかよくわからない。AC にはなった。Python では `None` にしていたのでそれを踏襲した。
    *   `None` (Python) と `nullptr` (C++) が概ね等価だと思っているが、LeetCode の Solution で `NULL` (C++) を使っているのを見かけた
        *   https://qiita.com/go_astrayer/items/6afb1592a8a5763fede1
        *   なるほどつまり `nullptr` 一択か (`NULL` はただの `0`)
*   一応 `Solution2` のように書けば変数の数は減らせるが読みにくい。

### step2

*   https://github.com/Ryotaro25/leetcode_first60/pull/71/files
    *   `std::swap` というのがあるんだ。なるほど。
    *   まず swap するとあとの `invertTree` の call を left, right 入れ替えずに書ける (`Solution1`)。
    *   後述の `swap` に関する議論を含めると、今回は `using std::swap` としたほうが良いのか。`TreeNode` に専用の `swap` がある可能性もあるため。
*   https://cpprefjp.github.io/reference/utility/swap.html
    *   > そのため、 swap() 関数を呼び出す場合は、直接 std::swap(a, b); と呼び出すのではなく、

```cpp
using std::swap;
swap(a, b);
```

*   contd.
    *   > のように呼び出し、各クラスに対し個別に定義された swap がある場合には そちらが呼ばれるようにするべきである。
    *   こうすることで、常に最適な `swap` が呼ばれる (型に対して特殊な `swap` が定義されている場合はそちらを呼び出す) というのが理解できなかった。Gemini に聞いてみた。
    *   `using std::swap;` と書いているコード上で、単に `swap` と書いた場合、`std::swap` が常に呼び出されるわけではないのですか。`using` 宣言は、`std::swap` の短縮形 (エイリアス) として `swap` を使用する宣言だと思っていました。
    *   回答以下

いいえ、常にstd::swapが呼び出されるわけではありません。そして、その挙動こそが、この書き方 (using std::swap; swap(a, b);) をする最大の理由です。

using宣言は、単純なエイリアス（別名）というよりも、「現在のスコープに関数の『候補』を一つ追加する」 と理解すると分かりやすいです。

## コンパイラによる関数の探し方と選び方
コンパイラが swap(a, b); というコードに出会ったとき、どの関数を呼び出すべきかを決めるために、以下の2段階のプロセスを踏みます。

### 1. 関数の候補探し (Name Lookup)
コンパイラは、呼び出すべきswap関数の候補を複数の場所から探します。

現在のスコープ: using std::swap; と書かれているため、コンパイラはここで 候補①: std::swap を見つけます。

引数の名前空間 (引数に依存した名前解決 / ADL): これが最も重要なポイントです。コンパイラは、swapに渡された引数 a と b の型が属している名前空間の中も自動的に探します。

もし a と b が、あるライブラリ MyLib で定義された MyLib::MyObject 型だった場合、コンパイラは MyLib 名前空間の中も探し、候補②: MyLib::swap を見つけます (もし存在すれば)。

この時点で、コンパイラの手元には複数の候補（この例では std::swap と MyLib::swap）がリストアップされます。

### 2. 最適な関数の決定 (Overload Resolution)
次に、コンパイラはリストアップされた候補の中から、引数の型に**最も一致する（最も特殊化された）**関数を1つだけ選び出します。

候補①: std::swap は、どんな型でも受け取れる汎用的なテンプレートです。

候補②: MyLib::swap は、MyLib::MyObject 型専用に作られた非テンプレート関数です。

C++のルールでは、テンプレートよりも、引数の型が完全に一致する非テンプレート関数の方が優先されます。

したがって、コンパイラは MyLib::MyObject にとって最適化された候補② MyLib::swap を選択します。もし、引数の型に専用の swap がなければ (ADLで見つからなければ)、唯一の候補である std::swap が選ばれます。

*   contd.
    *   つまり私は `using` 宣言を一種のエイリアス (そちらが呼ばれるようにする) だと思っていたのだが、間違いであるらしい。
        *   > using宣言は、単純なエイリアス（別名）というよりも、「現在のスコープに関数の『候補』を一つ追加する」 と理解すると分かりやすいです。
        *   https://en.cppreference.com/w/cpp/language/namespace.html#Using-directives
            *   読み込めてはいないが公式はここ
    *   型に依存して最適な関数を探す機能、Argument-Dependent Lookup, ADL というらしい。

*   `move`
    *   ところで `std::swap` でこんなふうに書いてあった。なるほど `move` というのがあるんだ。
    *   どちらもまだ読み込めていないが…move すると move された値は GC が動いたタイミングで garbage collect されるのかな。
        *   https://zenn.dev/mafafa/articles/cba24383d46900
        *   https://cpprefjp.github.io/lang/cpp11/rvalue_ref_and_move_semantics.html

```cpp
template <class T>
void swap(T& a, T& b) {
  T t = std::move(a);
  a = std::move(b);
  b = std::move(t);
}
```

*   今回は再帰メインだが、一応 `queue` も書いてみた (`Solution2`)。
    *   C++ は専用の `queue` オブジェクトがあるので、単に `push`, `pop` と書くだけで FIFO で処理してくれるんだな。便利 (Python は deque を使うのでたまに LIFO と間違える)
    *   https://cpprefjp.github.io/reference/queue/queue.html
*   https://google.github.io/styleguide/cppguide.html#Namespaces
    *   `include` と `using` の順番など。明記箇所はイマイチよくわからないがこんな例があった。まあ普通に `include` は一番最初だろう。
        *   > More complex .cc files might have additional details, like flags or using-declarations.

```cpp
#include "a.h"

ABSL_FLAG(bool, someflag, false, "a flag");

namespace mynamespace {

using ::foo::Bar;

...code for mynamespace...    // Code goes against the left margin.

}  // namespace mynamespace
```

*   contd.
    *   https://google.github.io/styleguide/cppguide.html#Names_and_Order_of_Includes
        *   `include` 内部の順番はこんな感じ。

> In dir/foo.cc or dir/foo_test.cc, whose main purpose is to implement or test the stuff in dir2/foo2.h, order your includes as follows:

1. dir2/foo2.h.
2. A blank line
3. C system headers, and any other headers in angle brackets with the .h extension, e.g., <unistd.h>, <stdlib.h>, <Python.h>.
4. A blank line
5. C++ standard library headers (without file extension), e.g., <algorithm>, <cstddef>.
6. A blank line
7. Other libraries' .h files.
8. A blank line
9. Your project's .h files.

e.g.

```cpp
#include "foo/server/fooserver.h"

#include <sys/types.h>
#include <unistd.h>

#include <string>
#include <vector>

#include "base/basictypes.h"
#include "foo/server/bar.h"
#include "third_party/absl/flags/flag.h"
```

### step3

*   再帰
