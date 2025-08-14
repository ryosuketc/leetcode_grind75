# 21. Merge Two Sorted Lists

https://leetcode.com/problems/merge-two-sorted-lists/

## Comments

### step1

### step2

*   解き方の方針は簡単に立ったが、C++ でどう書くかというところでやたら時間がかかる (ポインタとかをちゃんと考えながら書くのがほぼ初めてだったので) ので、さっさと他の人の解答を見て勉強することにした。
*   https://github.com/kzhra/Grind41/pull/3/files
*   `ListNode` の  `next` はそもそもポインタなんだ。Python だと object 自体を next に入れるので少し違う。
*   `ListNode* tail = &sentinel;` のような、適宜リストを動いていく (Python だと `node = dummy` とするような) オブジェクトは、ポインタとして定義するのか。オブジェクト自体ではなくそのアドレスを使う。
*   同様に `list1`, `list2` も参照渡し。アドレスが渡されていると思って良い。
*   個人的には、引数と同じ名前 (`list1`, `list2`) を関数内で更新するのは避けたい気持ちになるのだが (引数として渡されたとき == head と、関数の途中で意味が変わるので)、あまり気にしないものだろうか。
    *   `Solution2` 一応書いておいた。正直くどいが。あと変数の命名は微妙。`list1` もポインタなので、`*_pointer` という suffix で区別するのはどうなんだ。
*   Python だと `is None` とか `is not None` が好まれるが、C++ だと似たようなルールはあるのだろうか？
    *   https://google.github.io/styleguide/pyguide.html#2144-decision
        *   > Always use if foo is None: (or is not None) to check for a None value. E.g., when testing whether a variable or argument that defaults to None was set to some other value. The other value might be a value that’s false in a boolean context!
    *   https://google.github.io/styleguide/cppguide.html#0_and_nullptr/NULL
        *   特になさそうな気もする。
    *   一応 Gemini にも聞いてみたがやはりなさそう。というかそもそも Python の `is None` についてのルールは、None だけでなく空のリストなど、他にも falsy な値があるからのはず。C++ のポインタは `nullptr` 以外 false にならない (多分) ので、必要がないような感じがする
        *   ので、`list1 != nullptr && list2 != nullptr` と書いてもよい、はず。冗長だからあまり使わないのかな。
*   https://qiita.com/toshi_machine/items/9f260bff919a7679aa86
    *   step1;l=33 で `return sentinel->next;` して失敗した
    *   C++ だとポインタはアロー演算子、オブジェクトはドット演算子なのか。
*   そういえばこの練習会ではほとんどの人はヘッダファイルを書いていない (と思う) が、たまに書いている人がいる。
*   Python の気持ちで試しに `ListNode* remaining_list = list1 or list2;` やってみたら怒られた。
    *   > Line 17: Char 19: error: cannot initialize a variable of type 'ListNode *' with an rvalue of type 'bool'
    *   三項演算子使うのが正解らしい。
    *   `Solution3` 書いてみた。
    *   https://qiita.com/raccy/items/0b25b2f106e2a813828b
        *   `int x = a ? b : c;` (C++) == `b if a else c` (Python)
        *   まあ Python の三項演算子よりはわかりやすいが、むやみに使うものでもなさそう。

```cpp
        // `?:` の返り値の方を確認するためにやってみた
        ListNode* remaining_list = list1 ? list1 : list2;
        if (remaining_list) {
            tail->next = remaining_list;
        }
        // otherwise (普通はこっちかな)
        tail->next = list1 ? list1 : list2;
```

### step3

*   遊んでみたが結局最初の書き方がやはりスタンダードかな。
