#### 问题描述
&ensp;&ensp;&ensp;&ensp;双调欧几里得旅行商问题
#### 优化子结构 
&ensp;&ensp;&ensp;&ensp;记这一系列的点为$a_1$,$a_2$,......,$a_n$;</br>
&ensp;&ensp;&ensp;&ensp;记Dis(i,j)为从a_i出发,走到a_1再回到a_j的路径的最小值,满足j<=i且经过了所有a_k(k<=j)的点。dis(i,j)为点a_i到点a_j的几何距离。可见Dis(n,n)即为我们所求.</br>
&ensp;&ensp;&ensp;&ensp;考虑以下三种情况:</br>
>1. j=i,此时的路线必有从a_i到a_{i-1}的连线，因此Dis(i,i) = Dis(i,i-1) + dis(i,i-1)。</br>
>2. j=i-k(k>1),此时路线也必有a_i到a_{i-1}的连线，同理Dis(i,j) = Dis(i-1,j) + dis(i,i-1)。</br>
>3. j=i-1,，此时情况不同，若a_{i}首先连接到点a_k,则有Dis(i,j) = Dis(j,k) + dis(i,k)。而对k的选择有多种可能，选择最小的即可。</br>

&ensp;&ensp;&ensp;&ensp;以上三种情况显然有优化子结构，即右式的Dis为最优解，否则反证法，原式不是最优解。

