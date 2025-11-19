# 57. Insert Interval

https://leetcode.com/problems/insert-interval/

## Comments

### step1

*   大雑把な方針として、[interval_start, interval_end] の区間を掲げて、overlap しなくなるまで j を進める。j が進み終わったら、その時点の [interval_start, interval_end] を push_back という方針で考え始めた。
*   `SolutionWA1`
    *   しかし inner while のループ条件指定でなぜかドツボにハマって 50 分くらい考え込んでしまった
    *   多分 `interval_end` (今掲げている範囲)、`newInterval` (引数で与えられた範囲)、`intervals[j]` (overlap していたので進めようとしている範囲) の 3 つを同時に処理しようとして、条件設定がよくわからなくなってしまった模様。
    *   最終的に `if (new_interval_start <= interval_end)` のように `newInterval` だけ別で処理し (一回の処理なので `if` だけでよい)、inner while では  `interval_end` と `intervals[j]` に注目すればよいことに気づいて腹落ちした
    *   しかし `[], [5, 7]` のような入力に対して落ちてしまう。確かに overlap がない場合の処理ができないことに気づく
*   ツギハギのようで嫌だなあと思いながら、`SolutionWA2` のようにフラグを立ててみる
    *   最初、inner while にだけフラグを立てて、IN: `[[1,3],[6,9]], [2, 5]` -> OUT: `[[1,5],[6,9],[2,5]]` のようになってしまった
    *   `if (new_interval_start <= interval_end)` の中でもフラグを立てるようにした
    *   IN `[[1,5]], [0, 3]` -> OUT `[[1,5]]` (expect `[0, 5]`) のように前が extend されるケースが考慮されていない。
    *   1h 以上悩んだので一旦力尽きた


### step2

*   https://github.com/huyfififi/coding-challenges/pull/26/files
    *   一旦 step2 を見る。なるほど、overlap が発生する前、発生して skip する処理、残りの処理と段階を踏めばよかったのか…
    *   アイデアを見た段階で書き直した
    *   `step2.Solution`: ようやく AC した…
    *   余力がなかったので再帰についての部分はスキップした
*   https://github.com/huyfififi/coding-challenges/pull/26/files#r2184884440
    *   `newInterval` を `intervals` に放り込んでソートしてから処理する、という発想はなかった (以下一応転載)

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        vector<int> last_interval = intervals.front();
        for (const auto& interval : intervals) {
            if (last_interval[1] < interval[0]) {
                merged.push_back(last_interval);
                last_interval = interval;
            } else {
                last_interval[1] = max(last_interval[1], interval[1]);
            }
        }

        merged.push_back(last_interval);
        return merged;
    }
};
```

*   Python の `extend` + slice を C++ で書くとこんなかんじらしい。最後の while を書き換えられる
    *   とはいえ C++ だと while を使って書きたくなってしまう。十分単純なので。Python だと extend + slice という特有の syntax / function があるからいい気がするけど…


```py
result.extend(intervals[i:])
```

```cpp
result.insert(result.end(), intervals.begin() + i, intervals.end());
```

*   しかし今回のドツボから学べることはなんだろう？またやりそうで怖い。
    *   そもそも最初の、全部 1 ループで処理しようというのが複雑にする要因だったのだが、まあそれが必要なとき (inner loop) もあるわけで、どうやって見切りをつけるべきだったのか…
    *   なんか時々こういうのある気はする。ある特定の方針で書くと edge ケースの対応が妙にややこしくなるんだけど、別の procedure で考えると簡単、みたいな。ハマったときに切り替えられるとよいのだが面接でできる気がしないかも

### step3

*   skip
