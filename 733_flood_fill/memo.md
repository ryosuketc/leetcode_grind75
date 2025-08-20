# 733. Flood Fill

https://leetcode.com/problems/flood-fill/

## Comments

### step1

*   https://cpprefjp.github.io/reference/utility/make_pair.html
*   https://cpprefjp.github.io/lang/cpp17/structured_bindings.html
    *   `auto` でいける
*   細かい修正はありつつ、AC
*   選択肢として、再帰関数を使う、queue を使った iterative approach などが頭にあった。どれでも良かったが、stack を使う iterative にしてみた
*   in-place で変えていくので、`visited` は必須ではないもののこちらのほうが可読性が高いように思う
*   範囲チェックは stack に積む前にやってもよいのだが、4 方向に進むループをネストするのが嫌だったので、多少のオーバーヘッドは覚悟して一旦追加してからチェックすることにした。

```cpp
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            // 2. Check all 4 neighbors
            for (int i = 0; i < 4; ++i) {
                int next_r = r + dr[i];
                int next_c = c + dc[i];
                ...
            }
```

### step2

*   一応再帰でも書いてみた (`step2.Solution`)
*   再帰関数を定義するとき、C++ に inner function というのはあるんだろうか。`image` その他引数が多くて邪魔な印象もある。
    *   Gemini には、メンバ変数を使うことを提案された。
    *   ラムダ式で同じようなことができるらしいということも言われた
    *   一応 Gemini はこんなの出してきた。ラムダ式…なるほど…
    *   今回自分で書くのは見送り。キャプチャという概念があるのか。


```
*Gemini*

ラムダ式の主な特徴と使い方
構文: [キャプチャ](引数) { 本体 } という基本的な形をしています。

変数キャプチャ: [] の部分で、外側のスコープの変数をどのように扱うかを指定します。

[x] : 変数 x を値でコピーして利用する。

[&x] : 変数 x を参照で利用する（外側の x を変更できる）。

[=] : スコープ内のすべての変数を値でキャプチャする。

[&] : スコープ内のすべての変数を参照でキャプチャする。

主な用途: 特に、標準ライブラリ（STL）のアルゴリズム（std::sort, std::for_each, std::find_if など）に短い処理をその場で渡す際に非常に強力です。
```

```cpp
#include <vector>
#include <functional> // std::function を使うために必要

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color = image[sr][sc];

        // 開始色が目的の色と同じなら何もしない
        if (original_color == color) {
            return image;
        }

        int num_rows = image.size();
        int num_cols = image[0].size();
        
        // 1. 再帰呼び出し用のラムダ式を std::function として宣言
        std::function<void(int, int)> dfs;

        // 2. ラムダ式を定義し、自身をキャプチャさせる
        // [&] で dfs 自身と、image, color などの変数をキャプチャする
        dfs = [&](int r, int c) {
            // 範囲外か、色が異なる（訪問済み）場合は終了
            if (r < 0 || r >= num_rows || c < 0 || c >= num_cols || image[r][c] != original_color) {
                return;
            }
            
            // 色を塗り替える
            image[r][c] = color;
            
            // 再帰呼び出し
            dfs(r + 1, c);
            dfs(r - 1, c);
            dfs(r, c + 1);
            dfs(r, c - 1);
        };
        
        // 3. ラムダ式を実行開始
        dfs(sr, sc);
        
        return image;
    }
};
```

*   今回は in-place で変更しているが、コピーして返したい場合は？
    *   `vector<vector<int>> result_image = image;` でコピーになるっぽい？？
*   `std::pair` をより一般化したのが `tuple` か
    *   https://cpprefjp.github.io/reference/utility/pair.html
*   C++ は `std` namespace に色々定義されているのはいいとして、どのヘッダを include すればいいのかまだわからんやつが多い。データ構造系はその名前のヘッダであるのが多い気がする (`stack` とか)。`pair` は `utility`

### step3

*   今回は時間がないので省略
