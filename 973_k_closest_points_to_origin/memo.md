# 973. K Closest Points to Origin

https://leetcode.com/problems/k-closest-points-to-origin/

## Comments

### step1

*   原点から一番近い安を選ぶので安直なやり方は sort だろうか
    *   ただ最初の k 個を取ればいいので、全体を sort するのは非効率な気もする
*   heap 化するのは O(N) でできるし、その後で近いやつから pop していけばよさげ
*   sort しつつ最初の k 個をえらぶというと、quick select みたいなのが思い浮かぶけど、ぱっと実装すると言われると理解度的にちょっと止まってしまうかな。
    *   とはいえ最初から quick select で実装するのも大変そうだし、heap を使った実装とかできればひとまず良さそうかな、という感覚
*   上記の通り方針はある程度浮かんだが、久々すぎで C++ で heap の書き方忘れていたり、reference を参照しながら解いたので、step1 は skip

### step2

*    色々忘れていたので https://cpprefjp.github.io/reference/queue/priority_queue.html あたりを眺めながら進めた
*   上記の書き方だと、全部 heap に突っ込んだ上で、小さい方から k 個取り出す、という方法。ただ C++ の `priority_queue` はデフォルトで最大ヒープ。
    *   Python だと負の値を入れたりして擬似的に最小ヒープを作ったりするが、C++ ではどうかな。適当に Gemini あたりと話してみた。
    *   デフォルトで `std::less` を使っているようだ。`std::less` で最大ヒープになるということは、`std::less` に渡したとき、`true` が返る値 (より小さい方) を捨てている？ということだと思うが、なんかイマイチ腹落ちしていない。
    *   その他比較用関数を無名関数で定義したりするのは普通 C++ でもやりそう (ラムダ)。
*   最小ヒープではなく、別の考えとしては、heap サイズを k 個になるように維持しつつ、最大の要素を排除していけば最終的に一番小さい k 個が残る。ので最大ヒープを使って実装することはできそう (`step2.Solution1`)。
*   実際のユークリッド距離を計算 (ルートを取る) してしまうと float の扱いで計算誤差とか色々面倒そう。実際に必要なのは大小比較のみなのでルートは取らずに2乗の合計だけ見れば良さげ。
    *   実際この方針だと、問題の制約的には`int32` あたりに収まりそう
        *   -10^4 <= xi, yi <= 10^4 なので2乗の最大値は 2 * 10^8 くらい。`int32` (singed) の上限が `2,147,483,647 ≈ 2 * 10^9` で 1桁少ないので収まる
        *   まあとはいえ実務的には `int64` とか unsigned int とか大きいの使いたい感覚。
*   https://en.cppreference.com/w/cpp/language/types.html
    *   改めて見てみると、`int` は at least 16 (C++ standard) なので、最低限 `long` が必要。64 にするなら `long long`
*   `Solution2_1`
    *   sort を使ってみる
    *   C++ 冪乗 `x**2` みたいな書き方はなさそう。`std::pow`が `<cmath>` にあるけど
        *   https://cpprefjp.github.io/reference/cmath/pow.html
    *   今回は簡便のためコピーせずに引数をそのままソートした。必要なら `std::vector<std::vector<int>> points_copy = points;` とかで deep copy される (Python のように参照渡しにはならないので留意)
*   `Solution2_2`
    *   sort だが、ラムダの部分を関数に切り出してみた
    *   最初 `static` にせずに失敗した。sort に渡す関数は 2 引数 (`this` のようなインスタンスを取らない) なので、インスタンスに紐づかない関数である必要がある
*   `Solution3`
    *   operator の overload とか使うときれいに書けそうな気がしたので書いてみた
    *   思ったより長くなったので今回の解答としてはここまでしなくてもいいかもしれない
*   `Solution4`
    *   quick select
    *   C++ だと `nth_element` というのがあるらしい。
    *   https://cpprefjp.github.io/reference/algorithm/nth_element.html
        *   > 基準となる要素よりも小さい要素が前に来るよう並べ替える。
        *   > この関数はイテレータ範囲  [first,last)  の並び替えを行うが、基準位置  nth  のみが正しい要素、つまり仮に範囲  [first,last)  全体を並び替えた際に nth に位置すべき要素となる。前半のイテレータ範囲  [first,nth)  は関数呼び出し後の位置  nth  にある要素よりも小さいことは保証されるが、そのイテレータ範囲  [first,nth)  内での要素並び順はなんら保証されない。
    *   なるほどつまり k 番目の要素をパーティションとして、それまでの要素か points[k] より小さいことを保証してくれる (ただし順序は保証されない)
    *   そもそも quick select がなぜ平均 O(N) になるのか忘れていたけど `n + n/2 + n/4 + ... + 1 ≈ 2n` か (半分を切り捨てていく)。
    *   TODO: 今回は quick select の中身は実装しなかったけど、quick sort と合わせて復讐したほうがよさそう
    *   `std::nth_element` と全く同じものではないが、Python だと `heapq.nsmallest`, `heapq.nlargest` があったりする
        *   https://docs.python.org/3/library/heapq.html#heapq.nlargest

### step3

*   色々な解放やって時間なかったので一旦スキップ。やはり `Solution1` の heap が書けたらいいかなあという気がした。
