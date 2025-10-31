# 169. Majority Element

https://leetcode.com/problems/majority-element/

## Comments

### step1

*   `std::unreachable` の括弧を忘れていてエラー
    *   `std::unreachable`
        *   https://cpprefjp.github.io/reference/utility/unreachable.html

```
Line 16: Char 9: warning: expression result unused [-Wunused-value]
   16 |         std::unreachable;
      |         ^~~~~~~~~~~~~~~~
Line 17: Char 5: error: non-void function does not return a value in all control paths [-Werror,-Wreturn-type]
   17 |     }
      |     ^
1 warning and 1 error generated.
```

*   `return -1` などいくつかの選択肢はあると思うが。
*   O(1) の解法があるのかは気になったけど、ぱっと思いつかなかった。過半数を占めるのだから足したり引いたりしたらできそうな気もするが、「今までの出現回数」を覚えておくアプローチだと O(n) になるので…。

### step2

*   https://leetcode.com/problems/majority-element/editorial/
    *   思ったより色々な解法があった
*   space O(1) だと Boyer-Moore Voting Algorithm というのがあるらしい。
    *   `Solution 1` で書いてみた
    *   なるほど相殺、という考え方。bit XOR で、unique element を見つけるのになんとなく似ている。
    *   https://discord.com/channels/1084280443945353267/1084283898617417748/1193461706857390100
    *   Boyer-Moore Voting Algorithm bit を使った解法もあるようだが、今回は深堀りしていない
*   他の候補としては、sort するというのもある。sort は候補になかったので考えられるようにしたい。
    *   `nums[nums.size() / 2];` のようにインデックスに計算式入れるの特殊な文法があったっけ？と思ったが、よく考えると配列中央のインデックスを求めているだけだった
*   https://github.com/huyfififi/coding-challenges/pull/19/files
*   https://github.com/NobukiFukui/Grind75-ProgrammingTraining/pull/34/files

#### Boyer-Moore Voting Algorithm

Boyer-Moore 投票アルゴリズム（Boyer-Moore Voting Algorithm）は、配列の中で**過半数を占める要素（Majority Element）**を $O(N)$ の時間計算量と $O(1)$ の空間計算量で見つけるための、非常に賢いアルゴリズムです。

##### 🎯 中核となる考え方: 「相殺（そうさい）」

このアルゴリズムの根本的なアイデアは「**異なる要素同士をペアにして相殺させていく**」というものです。

問題の前提として、多数派要素は「配列の半分（$\lfloor n/2 \rfloor$）を超える」数だけ存在します。

これは、**「多数派要素の数」は「それ以外のすべての要素の数を合計したもの」よりも必ず多い**ことを意味します。



この状況を「多数派の軍（M軍）」と「少数派の連合軍（O軍）」の戦いだと考えてみてください。

* M軍の兵士の数は、O軍の全兵士の合計よりも多いです。
* もし、M軍の兵士1人とO軍の兵士1人が1対1で相打ち（相殺）になったとしても...
* ...最終的には、O軍は全滅し、M軍の兵士が**必ず**生き残ります。

Boyer-Moore 投票アルゴリズムは、この「相殺」プロセスをシミュレートします。

---

##### ⚙️ アルゴリズムの動作 (How it works)

使用する変数は2つだけです。

1.  `candidate` (候補者): 現在「多数派かもしれない」と考えている要素。
2.  `count` (カウント): その `candidate` の「現在の勢力（相殺されずに残っている数）」。

アルゴリズムの手順は以下の通りです。

1.  `count` を `0` で初期化します。`candidate` は何でも構いません（どうせ `count=0` なので）。
2.  配列 `nums` の各要素 `num` について、順番に処理します。
    a.  **もし `count` が `0` ならば:**
        * 今までの `candidate` は、他の要素によって完全に相殺されてしまいました。
        * 新しい `candidate` として、現在の要素 `num` を選び、`count` を `1` にします。
    b.  **もし `count` が `0` でないならば:**
        * **もし `num` が `candidate` と同じ**なら、仲間が来たので `count` を 1 増やします (`count++`)。
        * **もし `num` が `candidate` と異なる**なら、敵が来たので相殺します。`count` を 1 減らします (`count--`)。
3.  配列を最後まで処理し終わった時点で、`candidate` に残っている要素が、求める多数派要素です。

---

##### 注意点

このアルゴリズムが機能するのは、**「多数派要素が必ず存在する」という前提**がある場合です。

もし「多数派要素が存在しないかもしれない配列」（例: `[1, 2, 3]`）でこのアルゴリズムを実行すると、何らかの値（この場合は `3`）が返ってきますが、それは多数派要素ではありません。

（その場合、アルゴリズムの実行後に「本当に `candidate` が過半数か？」を**もう一度配列をスキャンして確認する**（検証フェーズ）必要がありますが、LeetCode のこの問題ではその必要はありません。）


### step3

*   skip
