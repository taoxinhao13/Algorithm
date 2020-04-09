#### 问题描述
输入向量$A^n$,为任意浮点数,求最大的子串中的乘积
#### 优化子结构
&ensp;&ensp;&ensp;&ensp;记$R^n$,$Max^n$,$Min^n$都为n维向量,分别表示前i个数(不一定包含$A_i$)所能构成的最大的乘积,前i个数的最大乘积和最小乘积(包括$A_i$)</br>
&ensp;&ensp;&ensp;&ensp;则目标为$R_n$的转移方程为:
$$R_{i}=
\begin{cases}
A_i& \text{i=1}\\
max(R_{i-1},Max_{i})& \text{1<i<=n}
\end{cases}
$$
&ensp;&ensp;&ensp;&ensp;而Max向量与Min向量,如果其中第k个元素不是仅由$A_i$自己构成,则$A_{i-1}$必定在序列里,因此转移方程为:
$$Max_{i}=
\begin{cases}
A_i& \text{i=1}\\
max(Max_{i-1}*A_i,Min_{i-1}*A_i,A_i)& \text{1<i<=n}
\end{cases}
$$
$$Min_{i}=
\begin{cases}
A_i& \text{i=1}\\
min(Max_{i-1}*A_i,Min_{i-1}*A_i,A_i)& \text{1<i<=n}
\end{cases}
$$
&ensp;&ensp;&ensp;&ensp;优化子结构显然，否则矛盾