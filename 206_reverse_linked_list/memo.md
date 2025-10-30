# 206. Reverse Linked List

https://leetcode.com/problems/reverse-linked-list/

## Comments

### step1

*   まあ典型的な問題なのでさらっと。
*   久々に再開したので `ListNode*` (ポインタ) を書くべきところを `ListNode` にしていた

### step2

*   `nullptr` との比較 (while の条件) は暗黙評価でよかった。
    *   前にも聞いたことあったけど Gemini に聞いてみた

> 3 の `!= nullptr` についての指摘ですが、たとえば Python などでは、暗黙に bool に変換するよりも `is None` / `is not None` など明示的に `None` と比較するほうがよいとされています (Google Python Style Guide など)。なぜ  C++ では暗黙に評価するほうがよいのですか。

これは非常に的を射た指摘です。この違いは、まさに Python と C++ の設計思想（Zen）の違いを象徴しています。

あなたが言う通り、Python の "Zen" (PEP 20) には「Explicit is better than implicit.（暗黙的より明示的が良い）」という有名な一文があります。is not None は、この哲学を完璧に体現しています。

ではなぜ C++ では while (node) のような暗黙的な評価が好まれるのか。理由は主に2つあります。

1. C 言語から受け継いだ「慣習（イディオム）」

C++ のこの文化は、その前身である C 言語から直接受け継がれています。

C 言語の「NULL」は「0」だった:

C 言語には bool 型がなく、0 を「偽」、それ以外（非ゼロ）を「真」として扱いました。NULL マクロは、一般的に 0（または (void*)0）として定義されていました。

「ポインタ != 0」がイディオムになった:

そのため、while (ptr != 0)（つまり while (ptr != NULL)）と書くよりも、単に while (ptr) と書く方が「ptr が 0 (NULL) でない間」という意味で簡潔かつ直接的でした。

C++ への継承:

C++ はこの慣習をそのまま引き継ぎました。C++11 で型安全な nullptr が導入されましたが、nullptr も bool に変換される際は false として評価されます。したがって、while (node) という書き方は、C/C++ プログラマにとって数十年にわたる「ポインタが null でないことを確認する」ための標準的なイディオム（慣用句）であり続けています。

2. Google Style Guide の「例外」

あなたの指摘は、実は Google のスタイルガイド内部の比較においても非常に興味深い点です。

Python (Explicit):

Google Python Style Guide は if x: ではなく if x is not None: を推奨します。これは「空のリスト []」と None を区別するなど、明示性を重んじるためです。

C++ (Implicit):

一方、Google C++ Style Guide は、ポインタに関しては Python とは逆の方針を推奨しています。

Null, 0, and ''

...

Use if (ptr) and if (!ptr) for nullptr checks.

(訳: nullptr のチェックには if (ptr) と if (!ptr) を使いなさい。)

Google という同じ組織が、言語ごとに異なる（一見、矛盾するような）ガイドラインを設けているのです。これは、while (node) が C++ のコミュニティにおいていかに「ネイティブな」表現であるかを強く裏付けています。C++ においては、while (node != nullptr) と書くほうが、むしろ冗長で「C++ らしくない」と見なされる傾向があります。

まとめ

Python: 「明示的 is 善」。is not None

C++: 「C からの伝統的なイディオムと簡潔性 is 善」。while (node)

私のレビューは、この C++ の強い慣習に基づいています。!= nullptr と書くことは、コードの正しさには何の影響もありませんが、C++ の「流儀」からは少し外れている、と見なされることが多いのです。

### step3

*   典型問題すぎるので省略
