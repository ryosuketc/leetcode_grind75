# 121. Best Time to Buy and Sell Stock

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

## Comments

### step1

*   Arai 60: https://github.com/ryosuketc/leetcode_arai60/pull/50/files
*   Python で書いたやつを模倣すると `SolutionPythonMimic` のようになる。AC。
*   以下色々調べたのを含めて `Solution2` に改変
    *   言語以外のところだと、`prices[0]` を特別扱いはしなくても動く。脳内でデバッガ動かしてみるとわかる。

#### 変数の宣言と初期化

*   `SolutionWA` のようにあえて書いてみた。
*   `min_price`, `max_profit` を宣言だけして初期化せずに `std::max`, `std::min` に突っ込むとどうなるの、というのが気になったため。
    *   後述するが、宣言のみでも、何らかの値は入っているので、その値と比べることになる。

```cpp
int min_price;
std::cout << "min_price=" << min_price << "\n";
int max_profit;
std::cout << "max_profit=" << max_profit << "\n";
```

追記: `"\n"` ではなく `std::endl` を使うのが普通か (`cout` の項目で後述)。

実行結果

```
min_price=232895332
max_profit=11
```

*   LeetCode で実行するとこんな感じ。実行ごとに `min_price` は値が変わる。しかも結構大きい値。ランダムな値になるのかと思ったが、`max_profit` は 10 回くらい実行して全部 `11` だった (WA の場合のみ。AC だと)。また大抵は WA になるが、AC することもあった。
    *   今回の制約は `0 <= prices[i] <= 10**4` なので、`min_price` は概ね期待したとおりに動作しそう (`> 10**4` の値のことがほとんど)。一方 `max_profit` は十分に小さい数で初期化されているわけではないケースが多そう。
*   別の環境 (https://www.tutorialspoint.com/compilers/online-cpp-compiler.htm) で実行してみると、こんな感じ。

```
min_price=1815761432
max_profit=32766
```

*   総合すると
    *   `min_price > max_profit`
    *    `max_profit` は固定値
*   という感じだった。
*   なぜ上記のような挙動になるのか革新はないが、以前そのメモリアドレスで使用されていた値をそのまま使うようだ。
    *   https://stackoverflow.com/questions/23160666/suppose-i-declare-an-int-but-dont-initialize-it-what-value-is-it-can-someone

#### C++ での最大値、最小値

*   なので基本的には使う前には何かで初期化する (まあ当然と言えば当然)。
*   Python でいえば `inf` や `sys.maxsize` 二相当するような値を使いたい
*   具体的には、
    *   `INT_MAX`: https://cpprefjp.github.io/reference/climits/int_max.html
    *   `INT_MIN`: https://cpprefjp.github.io/reference/climits/int_min.html
*   あたりがそれにあたるだろうか。`climits.h` で定義されている。
    *   https://cpprefjp.github.io/reference/climits.html
    *   `std` namespace に存在するのかと思って、`std::INT_MAX` と書いたら怒られた。

```
Line 6: Char 30: error: expected unqualified-id
    6 |         int min_price = std::INT_MAX;
      |                              ^
/install/lib/clang/19/include/limits.h:50:19: note: expanded from macro 'INT_MAX'
   41 | #define INT_MAX   __INT_MAX__
      |                   ^
<built-in>:139:21: note: expanded from macro '__INT_MAX__'
  130 | #define __INT_MAX__ 2147483647
      |                     ^
1 error generated.
```
*   contd.
    *   C++ macro で、どの namespace にも属さないらしい。
        *   `std::numeric_limits<int>::max()` というのもあるらしいが、どっちでもいいのかな。
        *   macro についてはまたの機会に調べてみよう。とりあえず macro というくらいなんだし、テキスト置換だと思っているのだが、ざっと見た感じ、プリプロセッサで置換され、その後コンパイラが処理するようだ。

#### header, namespace

*   以前 C++ 触ったときも一瞬混乱したのだが、`#include <climits>` で記載しているのは header file (`*.h`)。
*   一方 namespace については、別の header で同じ namespace を定義することはできる。
    *   例えば `std` は多数の header で使われているが、`std::cout` を使うには `#include <iostream>` が必要。
*   Python では名前空間とファイルが同一 (モジュール) なので、まあそれがわかりやすくもあり不便でもある気がした。

#### cout

*   print debug をするにあたり、`cout` あんまり知らないなあと思った

```cpp
std::cout << "Hello world" << std::endl;
```

*   https://cpprefjp.github.io/reference/iostream/cout.html
    *   `"\n"` ではなく `std::endl` を使うのが普通か。
    *   Java だと、`System.lineSeparator()` かな。
*   `<<` とか `>>` 
    *   `<<`: https://cpprefjp.github.io/reference/ostream/basic_ostream/op_ostream.html
    *   `>>`: https://cpprefjp.github.io/reference/istream/basic_istream/op_istream.html
    *   上記 `cout` / `cin` 以外でどう使うのかあまり詳しくは見ていないが、とりあえず stream object に対して入出力する。そう考えると演算子の矢印の向きはまあ納得できるかな。stream obejct に突っ込む (`<<`) か取り出す (`>>`) か。

#### その他

*   int は小さいので、参照渡しではなく値渡しにした (for loop)
*   namespace を極力記述するようにした。


### step2

*   https://github.com/Ryotaro25/leetcode_first60/pull/41/files
    *   大体同じやり方。
    *   `std::numeric_limits<int>::max()` 使ってる。方があってよい感じはするが長い
*   https://github.com/irohafternoon/LeetCode/pull/40/files
    *   そういえば https://github.com/ryosuketc/leetcode_arai60/pull/50/files でも逆順から走査するというのあった。C++ の sort 関連はまだ全然知らないので問題で当たったら調べようと思う。
        *   とりあえず逆順で操作するだけなら `--i` していけば書ける。
        *   `int price : prices` の書き方の reverse 板ってあるのかな。
        *   ちょっと力尽きてきたのでドキュメント見るのはサボったが、Gemini にきいてみた。以下 Gemini のコード

Iterator。へーこんなのあるんだ…というか見かけたことはあったがちゃんと見たことはなかった。iterator は加減算とかできるのね。

```cpp
#include <iostream>
#include <vector>
#include <iterator> // Good practice to include for rbegin/rend

int main() {
    std::vector<int> prices = {10, 20, 30, 40, 50};

    std::cout << "Using reverse iterators:\n";
    for (auto it = prices.rbegin(); it != prices.rend(); ++it) {
        std::cout << *it << " "; // *it dereferences the iterator to get the value
    }
    // Output: 50 40 30 20 10
    std::cout << std::endl;

    return 0;
}
```

i 使う。C っぽい伝統的なやり方らしい。

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> prices = {10, 20, 30, 40, 50};

    std::cout << "Using an index-based loop:\n";
    for (int i = prices.size() - 1; i >= 0; --i) {
        std::cout << prices[i] << " ";
    }
    // Output: 50 40 30 20 10
    std::cout << std::endl;

    return 0;
}
```

これが `int::price : prices` の逆版か。C++ 20 の ranges っていう機能らしい。これは Python slice みたいにコピー発生するのかなあ。view っていう名前だからしないといいなと思いつつ、ドキュメント読む元気がなくなってきたので Gemini に投げた。
コピーは発生しなくて、あと iterate するときに初めて評価されるらしい (lazy)。

```cpp
#include <iostream>
#include <vector>
#include <ranges> // Required for std::views::reverse

int main() {
    std::vector<int> prices = {10, 20, 30, 40, 50};

    std::cout << "Using C++20 ranges:\n";
    for (int price : std::views::reverse(prices)) {
        std::cout << price << " ";
    }
    // Output: 50 40 30 20 10
    std::cout << std::endl;

    return 0;
}
```

### step3

*   上で色々書いたので今回は省略。
