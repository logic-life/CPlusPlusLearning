# KMP

**解决字符串匹配问题，KMP 算法（Knuth-Morris-Pratt 算法）是一个著名的字符串匹配算法，效率很高。**

以下为暴力匹配算法：

```
int search(String pat, String txt) {
    int M = pat.size();
    int N = txt.size();
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++) {
            if (pat[j] != txt[i+j])
                break;
        }
        // pat 全都匹配了
        if (j == M) return i;
    }
    // txt 中不存在 pat 子串
    return -1;
}
```

![](https://pic4.zhimg.com/v2-817073ca77f6c75d234392f207a3c81b_b.gif)

**KMP 算法永不回退 `txt` 的指针 `i`，不走回头路（不会重复扫描 `txt`），而是借助 `dp` 数组中储存的信息把 `pat` 移到正确的位置继续匹配** ，时间复杂度只需 O(N)，用空间换时间，所以我认为它是一种动态规划算法。

确定dp数组只和pat串有关，只要给出pat串，就可以根据它计算出dp(next)数组；然后利用这个dp数组都可以在O(n)的时间复杂度完成字符串匹配。

Kmp算法详解：

[kmp](D:\C-learning\data structure\string\kmp\kmp.cpp)

[KMP 算法详解 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/83334559)
