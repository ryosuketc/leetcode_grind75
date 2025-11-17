# 217. Contains Duplicate

https://leetcode.com/problems/contains-duplicate/

## Comments

### step1

*   問題設定見て、一瞬 unique value を求める問題 (XOR 取ると duplicate は打ち消される) がよぎったが特に関係はない (どの問題か探したがちょっと出てこなかった)
*   まあ今回は dup を探すだけなので map である必要もない。set で十分

### step2

*   このあたり眺めておきたい
    *   https://cpprefjp.github.io/reference/unordered_set/unordered_set.html
        *   おなじみ ordered (二分木) か unordered (hash) かという話  
    *   `insert`, `emplace` いつも迷う問題
        *   https://cpprefjp.github.io/reference/unordered_set/unordered_set/emplace.html
        *   https://cpprefjp.github.io/reference/unordered_set/unordered_set/insert.html
    *   https://cpprefjp.github.io/lang/cpp11/range_based_for.html
        *   意外と改めて見てない気がするので後で読む
*   https://leetcode.com/problems/contains-duplicate/editorial/
    *   そういえば sort する手もあったな。なぜか脳内で候補に挙がらないことがあるので注意してみよう

### step3

*   簡単なので省略。後ほど上記 doc を見て追記するかもしれない。
