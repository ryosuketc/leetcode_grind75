# 125. Valid Palindrome

https://leetcode.com/problems/valid-palindrome/

## Comments

### step1

*   とりあえず最小限のリファレンスで解いてみた。
*   https://cpprefjp.github.io/reference/cctype/isalnum.html
    *   signature が `int isalnum(int ch);` で、int を返すことになっているが、bool じゃないんだ。C の名残？
*   https://cpprefjp.github.io/reference/locale/tolower.html
*   個人的には、最初のループで alnum でないやつの除去 + 小文字変換をやってから、2 回目のループで palindrome check をしたい。
    *   除去 +  小文字変換は private な関数に切り出して string_view? を返すとかしたい。

### step2

*   https://github.com/colorbox/leetcode/pull/7/files
    *   `+=` しながら `checker` 文字列を作っている。Python だと文字列コピーが発生する (ただし最適化の実装による) のでやりたくない感じなんだが、C++ だとどうなの？
    *   上記だと `checker` を reverse している。
    *   step1 でのコメントも踏まえて `step2/Solution` はとりあえず書いてみた。関数では文字列コピーして返しているから冗長な感じはする。できればコピーはせずに使いたい気もする (できるのかな？無理そう)
*   https://cpprefjp.github.io/reference/string_view/basic_string_view.html
    *   > 文字配列の参照する先頭文字へのポインタと、文字数の2つをメンバ変数として持つ。
    *   とあるので今回のように非連続な文字列になる場合は view 使えないのかな。それなら vector に push して一番最後で string に変換？ (Python の append -> join と同じ)
        *   追記: そもそも `std::string` 自体 `vector<char>` 的なものとして実装されているので、Python のような処理は不要。
*   https://qiita.com/LdCqh1/items/92f286ceb0ab96dc3c09
*   https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/string
    *   > C++ 標準ライブラリは、任意の文字型 Char に対して、便利な文字列処理を提供するためのクラステンプレート std::basic_string<Char> を定義しています。それを char 型に対して特殊化（std::basic_string<char>）したものが std::string です。
        *   `Char` と `char` って C++ だと違うものな？(TODO)
        *   軽く検索してみたがよくわからん
    *   `union` (TODO) とかあるんだ。。
        *   `size_t` という型がある
            *   https://cpprefjp.github.io/reference/cstddef/size_t.html
        *   https://rinatz.github.io/cpp-book/ch07-12-unions/
            *   共用体というやつか。聞いたことある。
            *   > 構造体の大きさがメンバーのすべての型の大きさの総和にパディングなどを足したものであったのに対して、 共用体ではメンバーの型の大きさの最大値にパディングなどを足したものとなります。 結果としてメモリーを節約することができるので、複数の型のどれかを格納したいという場合にはよく用いられます。

```cpp
// Cited from https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/string#1.3-std%3A%3Astring-%E3%81%AE%E5%86%85%E9%83%A8%E6%A7%8B%E9%80%A0-(3)
struct string
{
	char* m_ptr; // 確保したメモリの先頭を指すポインタ
	size_t m_size; // 格納している文字列の長さ

	static constexpr size_t LocalCapacity = 15; // 動的確保不要で格納できる文字列の最大の長さ

	union
	{
		char m_local_buffer[LocalCapacity + 1]; // 文字列の長さが LocalCapacity 以下の場合、動的確保の代わりに使う配列
		size_t m_allocated_capacity; // 動的確保した配列に格納できる文字列の最大の長さ
	} m_storage;
};
```

*   contd.
    *   > 2.2 文字列リテラルは std::string 型ではない
        *   まじか。ややこしい。
    *   > 3.3 別の std::string から構築する
        *   C++ だとこれはコピーになるのか。値渡しをしているということだと思うけど、`std::string` は mutable なのかな。

```cpp
	std::string s = "abc";
	std::string t = s; // s の値をコピーする
```

*   contd.
    *   > std::string 型のデフォルトコンストラクタは、要素数が 0 である空の std::string を構築します。
        *   なるほど、`int` だと宣言だけした場合未定義動作になると思うけど、`std::string` は定義されているのか。
    *   > C++20 から、範囲ベースの for 文に初期化式を追加できるようになりました。
        *   `for (int i = 0; const auto& ch : s)`
        *   へーこんなのもできるんだ
    *   イテレータ、逆イテレータ
    *   `std::views::reverse`
        *   `std::string_view` とは異なる
        *   パイプを使うんだ。この文法知らん。アダプタ？(TODO)。まあシェルの模倣だろう。
            *   https://onihusube.hatenablog.com/entry/2022/04/24/010041
                *   実際どう実装されているのかはよくわからん。
                *   https://cpprefjp.github.io/reference/ranges/drop_view.html
                    *   drop が drop する個数と view を引数に取る関数で、view の方はパイプで渡される、という意味合いかと思ったけど合ってるのかな。違う気がする。
                    *   上記 (https://onihusube.hatenablog.com/entry/2022/04/24/010041) の後半で解説されている気もするが、ちょっと時間かかりそうなので一旦先へ進む (TODO)
    *   > 11. std::string への追加
        *   `char` の配列として実装されているなら末尾への追加は O(1) だろうと思っていたがやはりそうだった。ただ `push_back` と `+=` の違いについては特に言及がなかった (もちろん `push_back` は `char` を取り、`+=` は string を取るという違いはあるが)
            *   https://cpprefjp.github.io/reference/string/basic_string/op_plus_assign.html
                *   ここには `append(str)  と等価。` と記載がある。
                *   https://cpprefjp.github.io/reference/string/basic_string/append.html
        *   いずれにせよ、C++ は末尾に追加する分には Python みたいなことは気にしなくてよいらしい。`push_back` と `+=` の違い (char を末尾に追加する場合) はまだよくわからないが、とりあえず `push_back` を使っておこう。

### step3

*   `std::char` にしたら怒られた。
*   関数に分けるパターンを採用
