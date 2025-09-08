# 1. Two Sum

https://leetcode.com/problems/two-sum/

## Comments

### step1

*   Arai 60: https://github.com/ryosuketc/leetcode_arai60/pull/11
    *   Python で解いているので方針はわかる。Arai 60 で (Python で) 解いた問題は、復習と、「C++ で書く」という部分にのみ注目する。あまり多くの解法を試すということは一旦しないかも (C++ に慣れるのを優先)。
*   https://qiita.com/gnbrganchan/items/616f3701b1169e834565
    *   とりあえずデータ構造が全くわからんので見る。
    *   `vector` は `list` (Python) に近い感じかな
        *   静的なのは `std::array`: https://en.cppreference.com/w/cpp/container/array.html
    *   `multiset` の存在意義がよくわからん。キーの重複を許す set ってそれ `vector` でいいんじゃないの？ああまあ検索は速いのか。
        *   https://qiita.com/h_hiro_/items/a83a8fd2391d4a3f0e1c
    *   `unordered_map`: 今回の問題で使うのはこれかな。Python の dict (厳密には Python dict は最近のバージョンでは ordered だが) 相当が `map`, `unordered_map` かな。
*   "C++ for Pythonistas" みたいなのないかなと思って探してみる。しっかりは見てないけどこの辺があった。
    *   https://runestone.academy/ns/books/published/cpp4python/index.html
    *   https://cs.kenyon.edu/wp-content/uploads/2020/11/CForPythonProgrammers.pdf
*   https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/vector
    *   `{}` で定義されるのはリストらしい？

### step2

*   https://github.com/nktr-cp/leetcode/pull/12/files
    *   map には  `contains` というのがあるのか
*   https://github.com/Shinkomori19/arai60/pull/2/files
    *   例外処理とか
*   https://github.com/nktr-cp/leetcode/pull/12/files

### step3

*   
