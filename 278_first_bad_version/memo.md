# 278. First Bad Version

https://leetcode.com/problems/first-bad-version/

## Comments

### step1

*   当然線形探索すれば解けるわけだが、まあ不鬱に binary search すればよいだろう
*   区間をどう取るかちょっと迷ったが、今回は素直に取りうるバージョンの範囲で始めることにした。なので両端を含む区間を探索することになる。
*   mid is bad version の処理、分岐せずに書けるか？と一瞬思ったけどまあ無理そうな気がした
*   bad version がない場合の処理
    *   bad version がある前提で呼ぶなら `std::unreachable();` やエラーもありかな。
    *   バージョンとして存在しない値を返すのが良かろうという気もしたので `0` を返したが、後で考えると、定義としては `n + 1` を返すほうが妥当だと思った (`firstBadVersion` なので 0 だと全てのバージョンが bad だという形になる)

### step2

*   いやこれよく考えると mid is bad version を特別に処理しなくても素直な二分探索で解けるか、と考えが至ったので書いた
*   https://leetcode.com/problems/first-bad-version/editorial/
    *    LeetCode でもこの書き方。ただ区間の考えが微妙に違う。まあこのあたりは書き換えの範囲

### step3

*   特記なしなので今日は省略
