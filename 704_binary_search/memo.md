# 704. Binary Search

https://leetcode.com/problems/binary-search/

## Comments

### step1

*   ただの binary search なので超簡単
    *   …とか言っておいて、最初右を探索するか左を探索するか逆転させてしまって WA だったので辛い。
    *   2:00 くらいで書いた。
*   境界の設定はまあ色々あるかなという感じはするか、左端は含み、右端は含まないこのパターンが余分な `nums.size() - 1` とかしなくていいので一番きれいかなと思ってこれにした。
*   今回は特別なデータ構造使うわけでもないので、C++ の文法などは調べずにソラで書けた。ちょっとだけ慣れてきたかな？まあ `std` とかまだまだわからんことは多いが…
*   Python だと整数は無限だから気にしないが、C++ はオーバーフローがあり得ると思ったので `int middle = left + (right - left) / 2;` にした。実際は問題の制約的に問題ない気がするけど。
    *   `1 <= nums.length <= 10^4`

### step2

*   そもそも C++ `int` って 32 ビットで合ってるんだっけと不安になったので一応確認した。
    *   https://en.cppreference.com/w/cpp/language/types.html
        *   C++ Standard だと at least 16 bits らしい。符号付きだと 32,768から32,767、符号なしでも0から65,535の範囲だから意外と表せる範囲が狭い。
    *   data model という概念があるんだ。知らなかった。
        *   https://en.cppreference.com/w/cpp/language/types.html#Data_models
        *   これイマイチどのレイヤーに属する概念なのかわからない。OS CPU? 言語?　GCC だったらこれ、clang だったらこれとかが決まっている？
            *   https://www.jpcert.or.jp/sc-rules/c-int00-c.html
                *   言語の処理系の話なのかなたぶん
        *   「ふつう」のデータモデルってどれなの？ C++ Standard? でも int は at least 16 bits らしい。
    *   https://google.github.io/styleguide/cppguide.html#Integer_Types
        *   built-in では `int` 以外使うなということらしい
        *   社内だと `std::int64_t` みたいなのよく見るのこれか。
        *   これだと多分 `int` は 32 ビット想定な気がする
*   built-in / STL に binary search あるの？
    *   `std::binary_search`
        *   https://cpprefjp.github.io/reference/algorithm/binary_search.html
        *   これかなと思ったけど値が存在するかどうかの bool しか返さないらしい
    *   `std::lower_bound`
        *   https://cpprefjp.github.io/reference/algorithm/lower_bound.html
            *   > イテレータ範囲 [first, last) のうち、指定された要素以上の値が現れる最初の位置のイテレータを取得する。
        *   Python の `bisect.bisect_left` と同じかな。左端を探す。
            *   https://cpprefjp.github.io/reference/algorithm/lower_bound.html
                *   > ソートされた順序を保ったまま x を a に挿入できる点を探し当てます。
        *   `std::upper_bound`
            *   https://cpprefjp.github.io/reference/algorithm/upper_bound.html
            *   まあ自然な発想としてこっちは `bisect_right` か
        *   https://cpprefjp.github.io/reference/algorithm/upper_bound.html
*   `step2.Solution`
    *   `lower_bound` 使って書いてみた。イテレーター使うやつまだ慣れないけどなるほど。
    *   チェックする条件は `(it != nums.end() && *it == target)`
        *   `it != nums.end()`
            *   target が見つからなかったとき / すべての要素が target より小さかったとき
        *   `*it == target`
            *   target 自体は見つからなくても `lower_bound` は、Python 同様に考えるなら挿入点を見つけるものなので、何かの値を返す
            *   `[1, 2, 3, 5], target = 4` であれば `lower_bound` は index `3` (`5` の位置) を返す。`5 != target` なので条件を満たしていない
    *   `std::distance` でイテレータ間の距離を出す。

### step3

*   step1 のものを残しておくが問題なかったので今回はスキップ。
