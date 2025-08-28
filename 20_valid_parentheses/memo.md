# 20. Valid Parentheses

https://leetcode.com/problems/valid-parentheses/

## Comments

### step1

*   Arai 60: https://github.com/ryosuketc/leetcode_arai60/pull/6/files
*   `stack.pop()` って void なんだ。Python とは違う (Python は top の値を返すので pop してそのまま変数に代入できる)。
*   最初 `char` 型を書くとき、double quote を使って失敗した: `"`

### step2

*   https://github.com/nktr-cp/leetcode/pull/7/files
    *   https://stackoverflow.com/questions/67541800/benefits-of-passing-const-reference-vs-values-in-function-in-c-for-primitive-t
        *   何も知らずに `for (char c : s)` (効率良い方) にしていたが `for (const char& c: s)` こんなのあったな。もう数問解いたら C++ 入門書的なので体系的にやったほうがいいかも。
        *   https://docwiki.embarcadero.com/Support/ja/C%2B%2B%E3%81%AE%E5%9F%BA%E7%A4%8E:%E9%96%A2%E6%95%B0%E3%81%AEconst%E5%8F%82%E7%85%A7%E3%81%AB%E3%81%A4%E3%81%84%E3%81%A6%E5%AD%A6%E3%81%B6
            *   string のコピーをしないために参照渡しをして、更にその参照が変更されませんよ、ということで const にしている
        *   こんな感じで一気に初期化できるのね、なるほど。
```cpp
        unordered_map<char, char> open_to_close = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
```

*   contd.
    *   `map.at` は例外を投げるが、そもそも `unmatched_open_brackets` には、`open_to_close` に入っているものしか積んでいないので例外処理は不要なはず。ただわかりやすさの観点では if ... contains でチェックしておいてもいいのかもしれない。
    *   https://github.com/nktr-cp/leetcode/pull/7/files#r2072357811
        *   `string_view` なるほど…
        *   https://cpprefjp.github.io/reference/string_view/basic_string_view.html

### step3

*   
