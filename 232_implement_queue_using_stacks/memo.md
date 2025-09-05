# 232. Implement Queue using Stacks

https://leetcode.com/problems/implement-queue-using-stacks/

## Comments

### step1

*   久々に取り組んだ
*   問題文から、2 つ stack を使うことが明らかだったので、その方針で考えてみた。
*   一旦移して順番を入れ替える (reverse) はまあ思いついて、ただ O(n) なんだよな、と思いつつ、O(1) がないか 3:00 くらい考えたが思いつかなかった。
*   `st`, `st_aux` よりはいい名前があるだろうと思ったが、あまり思いつかなかったのでこのまま
    *   最初 `stack`, `stack_aux` としていたが、`std::stack` と衝突する
*   最初、`pop` の方で入れ替え処理を書こうとして、数行書いたあたりで、`pop` する処理と混ざって面倒なので、`push` で書いたほうがいいかな、と思った
    *   l11-14, 別になくても動くなと、後から読み直して気付いた
    *   後から考えると、おそらく一般的なユースケースでは `pop` の方が頻度が低そうなので、そちらを O(n)、`push` を O(1) 二死したほうがよかったのかもしれない 
*   `peek`, `pop` の empty check はメソッドにしてもいい
    *   ただそれ以前に例外を投げていいのかちょっと迷った (https://github.com/ryosuketc/leetcode_grind75/pull/10#discussion_r2295004606)
    *   ただ今回だと int を返さなければならないが、"特殊な int" というのが思いつかなかった。どのような int でも queue に入る可能性があるので、特定の int をエラーとして扱うのは無理がある
    *   ので結局今回は例外を選択
*   最初、Python のクセか、`st`, `st_aux` をコンストラクタ内で定義して怒られた。
    *   C++ だと、宣言と初期化が分離している (コンストラクタでは初期化を行う)

### step2

*   https://leetcode.com/problems/implement-queue-using-stacks/editorial/
    *   amortized O(1) の書き方があるらしい。
        *   なるほど、普段は `st` に LIFO のまま push しておく
        *   `pop` が呼ばれたとき、**かつ `st_aux` が空の場合のみ**に一気に `st_aux` に移す。`st_aux` に要素が残っていれば (`st_aux` は FIFO で積んでいるので) 単純に top を返して pop すればよい。
        *   `front` で状態管理しようとして失敗した (`MyQueue1`)
*   Gemini と相談したりあれこれしてたらこの実装が良さそう (`MyQueue2`)
    *   `front` による状態管理はしない
    *    `st`, `st_aux` は役割的に `stack_in`, `stack_out` がよさそう。省略形 `st` も避けておく
    *   `stack_in`, `stack_out` 間の処理を `peek` に移動し、`pop` から `peek` を呼ぶようにした
    *   このクラスの `empty()` を利用。
 *   `exception`
    *   https://en.cppreference.com/w/cpp/error/exception.html
    *   C++ だと上のような standard exceptions がある。まだぜんぶは覚えてないけど
    *   C++ 例外も Python と同様に階層構造があるようだ。上位のものを指定すると下位をまとめて catch できる (はず)

### step3
*   `step2.MyQueue2` と同じ
