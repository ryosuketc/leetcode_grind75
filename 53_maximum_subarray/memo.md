# 53. Maximum Subarray

https://leetcode.com/problems/maximum-subarray/

## Comments

### step1

*   解いたことあるような気はしつつ、解法暗記しているわけではないので exmple 見ながら考えてみた。
*   愚直に実装するなら O(n^2) (区間を決めて、その区間ごとに sum を再計算すると O(n^3) だが、running sum を持っておけば O(n^2) になる、あるいは累積和の配列を作ってもよい)
*   とはいえ subarray == 連続する要素の array で、sliding window の問題として解けそう
*   例を使っていくつかシミュレーションしてみる。要は window をいつリセットするかで、それまでの累積和が、その単一の要素より小さければよいだろうというあたりをつけた
*   脳内デバッガをちゃんと回すべきだったが、`step1.SolutionWA` のように書いて WA
    *   `max_subarray_sum = 0` ではなく `nums[i]`。`[-1]` みたいな配列で 0 を返してしまう
    *    `if subarray_sum < 0` の条件が必要。`[1, 2]` で `2` (3 ではなく) になってしまう
*   `SolutionAC` で 9:00 くらいで AC

### step2

*   https://github.com/ryosuketc/leetcode_arai60/pull/45/files
    *   ああ、DP の問題でもあったのか。Kadane's Algorithm とか。今回はちょっと深煎りしないけど。
    *   `Solution1`: max 使えばもっとシンプルに書ける (if 分岐を消せる)
*   https://github.com/konnysh/arai60/pull/4#discussion_r1835271603
    *   `INT_MIN` とかそういえばあったが、`std::numeric_limits<int>::min()` がモダン。最近使ってないので、C++ 番 `math.inf` どう書くのか忘れていた
    *   https://cpprefjp.github.io/reference/climits/int_min.html
    *   https://cpprefjp.github.io/reference/limits/numeric_limits.html
    *   `Solution2`: 一応これが一番シンプルかな

### step3

*   skip
