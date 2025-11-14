# 543. Diameter of Binary Tree

https://leetcode.com/problems/diameter-of-binary-tree/

## Comments

### step1

*   とりあえずあまり時間がない日だったので、2 分考えて自信がなかった (diameter の更新は別途して、再帰関数の返り値は left, right のいずれかどちらかの path だけの長さを返せばいいだろう、くらいは考えた) LeetCode の回答の方針で書いてみたが -1 を返していたり、+2 していたりで謎の実装。step2 で修正する。

### step2

*   `Solution1`step1 の書き直し。LongestPath という名前ならまあ -1 ではなくて 0 が返ってほしい
*   https://github.com/Kitaken0107/GrindEasy/pull/17/files
    *   参照透過性の話
    *   step1 の実装だと、`LongestPath` が単体で呼ばれると `diameter` がリセットされないので困る。一応 `private` にしており、外部からは呼ばれない想定だが、あまりよくないかな？
    *   Python で書いていると確かにやってしまいそうな実装のような気はする。
        *   上記の、"再帰関数の返り値は left, right のいずれかどちらかの path だけの長さを返せばいいだろう" くらいの思考をたどると、ペアを返すという発想にはなりにくい気がする。
        *   みんながアクセスできる場所に diameter を保存しておこう -> じゃあインスタンスメンバかな、みたいな
        *   ただ一方で、diameter を `Solution` クラスのインスタンスメンバに持つ、というのはだいぶ違和感があり、そっちの方向から気づくかもしれない。
    *   https://discord.com/channels/1084280443945353267/1206101582861697046/1230424716645240892
*   `Solution2`: C++ なので参照で書いてみる。

Python で書くならこんな感じにしそう (C++ の参照のコード `step2.Solution2`そのまま)。関数内関数とかいいんじゃないですか。普段あまり使わないけど、今回は使ってもいい気がする。ペアで返すのも悪くはないと思う。

```py
class SolutionPy:
    def diameterOfBinaryTree(self, root):
        def traverse(node):
            if node is None:
                return 0
            nonlocal diameter
            left = traverse(node.left)
            right = traverse(node.right)
            diameter = max(diameter, left + right)
            return max(left, right) + 1

        diameter = 0
        traverse(root)
        return diameter
```

### step3

*   今日はちょっと時間がなさそうなので省略
