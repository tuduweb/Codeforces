## Marketing Scheme

https://codeforces.com/contest/1437/problem/C

自己从一开始想到了是动态规划问题，但没法找到转移方程，故需要训练。

动态规划问题：
参考了CSDN：https://blog.csdn.net/liufengwei1/article/details/109324590

在参考文中，了解到的知识点是：

    由于有n个菜，而且他们最好的时间ti<=n,那么可想而知就算从n开始拿出盘子，最多到2*n的时间可以拿完

那么最多的时间即是2*n

 * i = 0,2n the most bad , pick j1 on time N(N minutes)
 * j = 0->n max n N object
 * n = [1,200]
 * 转移方程： dp[i][j] = max{ dp[i - 1][j], dp[i - 1][j - 1] + Abs(t[j] - i) }

### 思路
#### 关于本题，正确思路
![正确思路](../static/Screenshot%202020-10-29%20132800.jpg)

#### 错误思考过程
![错误思考](../static/Screenshot%202020-10-29%20132928.jpg)