# 67. Add Binary

https://leetcode.com/problems/add-binary/

## Comments

### step1

*   `j >= 0` のチェックや `carry /= 2` を忘れていて fail した
*   多分三項演算子とかもっと短く書くことはできる
*   個人的には carry というと 0 or 1 の値を期待するのだが、これは計算途中でたとえば 3 になることがある (もともとの carry = 1 + a[i] + b[j])。`'1'` (char) を int に変換するのを避けるためにこうしたが、本来は carry と、その桁の計算結果は別の変数に保持したいかもしれない。
    *   step2 で追記: char -> int のうまいやり方がなかったというのもそうだが、この方針でやってもそんなにきれいに書けない気もした (結局 j の範囲判定があったり割に面倒)。

### step2

*   `Solution1`
    *   三項演算子と、index に `j--` を使うなどしてみたが、別にさほどわかりやすくはならなかった
*   `Solution2`
    *   結局三項演算子はないほうがよい
    *   `--j` を `if (j >= 0 && b[j] == '1')` の条件文内でしないように注意 (`'1'` のときしか j が進まなくなるので)
    *   `digit` 変数に一旦おいてから `push_back` するか、そのまま値を `push_back` するかは少し悩んだ。まあどっちでもいいかという感じはする。
*   https://cpprefjp.github.io/reference/algorithm/reverse.html
*   string -> int なら `stoi` がある。
    *   https://cpprefjp.github.io/reference/string/stoi.html
*   ただ char -> int はうまいやり方がなかったので `int hoge = a[0] - '0';` とか文字コードで計算する感じになりそう。
*   https://github.com/huyfififi/coding-challenges/pull/20/files
    *   短い方を zero 埋めして長さを揃えるという手もあったか
        *   C++ だと `insert` が色々な使い方がある
            *   https://cpprefjp.github.io/reference/string/basic_string/insert.html
    *   `total` 変数に一時置きするのよい

### step3

*   繰り返し練習は省略。面接中にここまで (関数の切り出しとか) やるかはともかく、このパターンがきれいな気はする。
    *   最初 `EqualizeLength` で `a`, `b` を mutate するのがなんとなく嫌で、書き込み先のアドレス受け取るかなども思ったが、そもそも `addBinary` の時点でコピーした文字列が渡されているので、mutate するするのは特に問題なさそう。
