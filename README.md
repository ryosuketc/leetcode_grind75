# leetcode_grind75

This is being worked on after Arai 60: https://github.com/ryosuketc/leetcode_arai60.

*   https://www.techinterviewhandbook.org/grind75/
*   LeetCode list: https://leetcode.com/problem-list/rab78cw1/

## List of solved issues

Refer to PRs.

*   Open PRs: https://github.com/ryosuketc/leetcode_grind75/pulls
*   All PRs: https://github.com/ryosuketc/leetcode_grind75/pulls?q=is%3Apr

## Favorite repositories

*   C++
    *   https://github.com/Ryotaro25/leetcode_first60/pulls
    *   https://github.com/irohafternoon/LeetCode/pulls
    *   https://github.com/nktr-cp/leetcode/pulls
*   Python
    *   https://github.com/hayashi-ay/leetcode/pulls
    *   https://github.com/olsen-blue/Arai60/pulls
    *   https://github.com/fuga-98/arai60/pulls
        *   https://github.com/fuga-98/arai60/pull/58/files#diff-b74a144fcf30b9765b5a3057f5e09d7c6facdfa07a3f44095affab3affa62b27R56
    *   https://github.com/nittoco/leetcode/pulls
    *   https://github.com/t0hsumi/leetcode/pulls
    *   https://github.com/Mike0121/LeetCode/pulls
    *   https://github.com/TORUS0818/leetcode/pulls
    *   https://github.com/Fuminiton/LeetCode/pulls
    *   https://github.com/shining-ai/leetcode/
*   Rust
    *   https://github.com/Yoshiki-Iwasa/Arai60/pulls

## References

*   [マニュアル](https://docs.google.com/document/d/1bjbOSs-Ac0G_cjVzJ2Qd8URoU_0BNirZ8utS3CUAeLE/edit?usp=sharing)
*   [コメント集](https://docs.google.com/document/d/11HV35ADPo9QxJOpJQ24FcZvtvioli770WWdZZDaLOfg/edit?usp=sharing)
*   [Discord rytc_ channel connected via Webhook](https://discord.com/channels/1084280443945353267/1371297545514647562)
*   Arai 60: https://github.com/ryosuketc/leetcode_arai60.
*   C++ 入門系
    *   [競プロのための標準 C++](https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming)
    *   [C++の標準ライブラリデータ構造まとめ -AtCoder等, 競プロで使える-](https://qiita.com/gnbrganchan/items/616f3701b1169e834565#unordered_map)
    *   [[C++] STLの型の使い分け](https://qiita.com/h_hiro_/items/a83a8fd2391d4a3f0e1c)
    *   [C++ for Python Programmers (runestone.academy)](https://runestone.academy/ns/books/published/cpp4python/index.html)
    *   [C++ for Python Programmers (cs.kenyon.edu)](https://cs.kenyon.edu/wp-content/uploads/2020/11/CForPythonProgrammers.pdf)

## Workflow

1.   Run `create.sh` to make the relevant resources (branch, folder, files).
2.   Work on the problem (from step1 to step3, per [manual]((https://docs.google.com/document/d/1bjbOSs-Ac0G_cjVzJ2Qd8URoU_0BNirZ8utS3CUAeLE/edit?usp=sharing))).
3.   Run `prcreate.sh` to make a PR.
4.   Post a review request to Discord: [レビュー依頼](https://discord.com/channels/1084280443945353267/1239148130679783424).
5.   Work on review comments.
6.   Merge the PR (for better code search).

```shell
# Both take <directory_name> and <URL>
$ ./create.sh "8. String to Integer (atoi)" https://leetcode.com/problems/string-to-integer-atoi/description/
$ ./prcreate.sh "8. String to Integer (atoi)" https://leetcode.com/problems/string-to-integer-atoi/description/
```
