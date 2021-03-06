﻿## 传统的加密技术

在古代中国较 "流行" 使用淀粉水在纸上写字，遇碘水中使字呈现蓝色显现出来, 利用化学反应中的络合反应.

以及应用最为广泛的 对称加密, 什么是**对称加密**, 打个比方, 我想给我一个在远方的朋友送一个价值连城的宝贝, 我把这个宝贝放在保险箱中, 我设置了一个密码, 我自己知道, 我再偷偷告诉朋友, 在保险箱运送过程中, 宝贝是安全的, 没有人能打开它, 当朋友收到保险箱后就可以按照密码打开. **即用一种方法加密, 用同一种方法解密, 即为对称加密**. 像我们在谍战剧中看到的情报人员发出加密的电报, 在另一方收到后需要根据 "密码本" 来破译, 这就是典型的对称加密, 影视中有多少人为了保护这个 "密码本" 而失去生命, 情报的加密与破译也可能是决定一场战争走向的重要因素. 

**对称加密的安全性,  首先取决于加密方法的保密性, 其次才取决于加密方法的破译难度**

> 也就是说, 发送方加密的信息, 接收方要能解密, 就要知道加密方法. 这个加密方法的传输就成了很大的问题,比如我国抗日战争以及解放战争中情报员运送的 "密码本"的过程, 就是传输解密方法的过程. 这个过程就会产生巨大的安全隐患. 其次就是加密方法的问题, 如今计算机技术发展迅速, 一般的加密方法在大量计算下可能都会被破译, 所以,在当今网络通信安全需求如此巨大的时代, 单凭对称加密已经远不能满足人们的需求了.

_______________________________________
## 非对称加密

> 非对称加密算法需要两个密钥：公开密钥 (publickey:简称公钥) 和 私有密钥 (privatekey:简称私钥). 公钥与私钥是一一对应的,  如果用公钥对数据进行加密, 只有用对应的私钥才能解密.  因为加密和解密使用的是两个不同的密钥,所以这种算法叫作非对称加密算法.

非对称加密算法实现机密信息交换的基本过程是 : 甲方生成一对密钥与公钥, 并将公钥公开, 需要向甲方发送信息的其他角色(乙方, 丙方等) 使用甲方公开的公钥对机密信息进行加密后再发送给甲方. 甲方再用自己私钥对加密后的信息进行解密.

甲方想要回复乙方时正好相反, 使用乙方公开的公钥对数据进行加密，同理，乙方使用自己的私钥来进行解密.

非对称加密的特点 : 算法强度复杂, 安全性依赖于算法与密钥但是由于其算法复杂，而使得加密解密速度没有对称加密解密的速度快. **非对称加密的保密性比较好，它消除了对称加密中用户交换密钥的需要 .**
________________

# RSA加密算法

>RSA是1977年由罗纳德·李维斯特（Ron Rivest）, 阿迪·萨莫尔（Adi Shamir）和 伦纳德·阿德曼（Leonard Adleman）一起提出的. 当时他们三人都在麻省理工学院工作. RSA就是他们三人姓氏开头字母拼在一起组成的.

**算法可靠性(安全性) :** 对 [极大整数](http://www.baidu.com/link?url=ig4r4QRkwVVlgpaaHGNFtsyFkF20rtjpCyn9vOmWrjWBdtBnBJZIxNJr1HY1djW_Qg7e9EslWBcHPwze_TalB22FUQoO7NR54RSQUGuxfZ142ULlfcRxZY8AS2zKpo1h)做因数分解(公认的数学难题) 的难度决定了RSA算法的可靠性.

为什么说RSA算法的可靠性是基于极大整数的因数分解难度, 我们就得先了解RSA算法原理.

## RSA算法原理

>在RSA加密算法中, 会产生三个关键数据, **私钥(D), 公钥(E) 和 公共模数(N).** 在加密信息传输流程中, 发送方需要有(E, N)来进行数据加密, 接收方需要有(D, N)来进行数据解密.

　**RSA加密公式 :**  　　　　　　　　　　                      **RSA解密公式 :**       

![img](https://img-blog.csdnimg.cn/20200327162254605.png)                              ![img](https://img-blog.csdnimg.cn/20200327162710875.png)

解释 : 加密公式是密文等于明文的E次方模上一个N.  解密公式同理

那么问题来了, 怎么得到一组D, E, N 呢?

最容易获得是N值, 随机选择两个不相等的质数p 和 q, N = p*q  (**p和q这两个质数越大, 就越难破解**)

接下来是D和E的值, 在这之前, 我们先来了解一些概念

> **质数相关概念 :** 
>
> - 两个质数一定是互质数
>  - 如果两个数之中, 较大的那个数是质数, 则两者构成互质关系, 比如97和 [1, 96] 的96个数全是互质关系
>  - 互质的两个数最大公约数为1
>
> 
>
>  **欧拉函数 :**
>  - **概念** : 欧拉函数的值是小于x的正整数中与x互质的数目
>   - **通式** :   ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200415233613287.png)
>   - 欧拉函数是积性函数, 若m, n互质, 则有φ(mn) = φ(m)φ(n) 
>   - 由互质数的概念可知, n为质数时, φ(n) = n - 1, 若m, n都为质数时, φ(mn) = (m - 1)(n - 1) 
>
>   **欧拉定理 :**
>  - **概念** : 如果两个正整数a和n互质，则n的欧拉函数 φ(n) 可以让下面的等式成立
>  - "≡" 是数论中表示同余的符号, 表示等式两边求余的结果相同, 上面公式的意思是a的φ(n)次方除以 n 的余数等于 1除以n的余数, 1除以n的余数是1, 也就是说a的φ(n)次方除以 n 的余数等于1. 等价于下面的公式
> - ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200415234025568.png)
>
> **模反元素(逆元)**
>
> - **概念 :** 根据欧拉定理, 如果两个正整数a 和 n互质, 那么一定可以找到整数b, 使得ab - 1可以被 n 整除, 或者说 ab除以n的余数是1, ab mod n = 1,  此时, b就叫做a的 "模反元素", 或者成为模的逆元.

### RSA的E, D, N产生过程

 - List item
 - 随机选择选择两个不相等的质数p和q
 - 计算p和q的乘积 : n = pq. 得到公共模数 N = n
 - 计算n欧拉函数的值,  φ(n).
 - 随机产生一个整数e, e的范围是1 < e  φ(n), 并且e与 φ(n) 互质.
 - 计算e对于 φ(n)的模反元素d, 使得 de ≡ 1 mod φ(n), 即 (de) mod φ(n) = 1
 - 公钥(e, n), 私钥(d, n)

**来举个栗子 :**

 - 选择p = 3, q = 11 
 - n = pq = 33 由于p和q都为质数, φ(n) = (p -1)(q -1) = 20
 - 随机选择 e = 3 (1 < e < 20, 并且 e与20互质)
 - (de) mod φ(n) = (3d) mod 20 = 1, 可得其中一个解 d = 7
 - 公钥(3, 33), 私钥(7, 33)
 - 加密 : 对明文数字 4 加密, 根据加密公式, 密文 = (4^3) mod 33 = 64 mod 33 = 31
 - 解密 : 根据解密公式 , 明文 = (31^7) mod 33 = 27512614111 mod 33 = 4
_________________
## RSA加密的安全性

> RSA密钥产生过程中共生成6个值p(极大质数), q(极大质数q!=p), n(公共模数), φ(n)(欧拉函数值), e(私钥),d(公钥). 除过n, e之外, 其它值都是不公开的, p和q一般会销毁, d不能泄漏.

RSA安全性的高低就取决于通过n和e推导出d的难易程度, 由密钥产生的第五步可以知道 :

 - (ed) mod φ(n) = 1. 只有直到e 和 φ(n), 才能算出d
 - φ(n) = (p - 1)(q - 1). 也就是直到p和q才能算出φ(n)
 - n=pq. 只有将 n 因数分解, 才能算出p和q, 到此, RSA算法的可靠性就由极大整数的因数分解难度决定

> 破解RSA到目前没有任何有效方法, 只能用穷举法, 在计算机中进行大量的运算, 随着计算机技术的不断发展,RSA中因数分解的问题可能会解决, 但就像下面例子中的破解一样, 破解一个512bit的大数就需要五个月, 已经失去了时效性,因此只要密钥长度足够长, RSA机密的信息实际是不能被破解的.
> 
> 1. 针对RSA最流行的攻击一般是基于大数因数分解. 1999年，RSA-155 (512 bits)被成功分解, 花了五个月时间（约8000 MIPS年）和224 CPU hours在一台有3.2G中央内存的Cray C916计算机上完成.
> 
> 2. 2009年12月12日, 编号为RSA-768（768 bits, 232 digits）数也被成功分解. 这一事件威胁了现通行的1024-bit密钥的安全性, 普遍认为用户应尽快升级到2048-bit或以上.
> 
> 3. 量子计算里的秀尔算法能使穷举的效率大大的提高. 由于RSA算法是基于大数分解（无法抵抗穷举攻击），因此在未来量子计算能对RSA算法构成较大的威胁.一个拥有N量子比特的量子计算机，每次可进行2^N次运算，理论上讲，密钥为1024位长的RSA算法，用一台512量子比特位的量子计算机在1秒内即可破解.
_________

## RSA算法实现中的问题以及解决办法

> RSA算法实现中的问题都是围绕大数运算而产生的, 由于我们的计算机CPU位数的限制, 大数的运算就产生了困难, 具体问题如下 : 
> 
> - 问题1 : 模反元素的求解
> - 问题2 : 大数的幂运算 
> - 问题3 : 大数的加/减/乘/除/模运算 
> - 问题4 : 大数产生随机数 问题5 :
> - 大数产生素(质)数 

____

### 问题1 : 模反元素的求解

> 第五步 : (de) mod φ(n) = 1 式子中求d的值
> 
> 使用暴力搜索, 求模反元素d的时间复杂度为O(n)，这对于大数来说, 效率方面是无法忍受的.所以需要更快速的算法.

在第四步 : 随机产生一个整数e, e的范围是1 < e  φ(n), 并且e与 φ(n) 互质.  利用互质的两个数最大公约数为1, 利用算法判断互质

**欧几里得算法(辗转相除法) : gcd(a, b) = gcd(b, a mod b)**

这是一个我们在初高中就学过的计算两个数的最大公约数的方法, 代码实现有递归和非递归
```cpp
#include<iostream>

int gcd1(int a, int b) {
	return b ? gcd1(b, a % b) : a;
}
int gcd2(int a, int b) {
	int tmp;
	while (b) {
		tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}
int main() {
	std::cout << gcd1(10, 11) << std::endl;
	std::cout << gcd2(10, 11) << std::endl;
	return 0;
}
```

但在第五步(de) mod φ(n) = 1 中求 d, 如果用暴力法(穷举法)的话太慢, 所以引入下面方法

**欧几里得定理 :** 如果 a 和 b 的最大公约数是gcd时, 那么就一定有 ax + by = gcd (x,y,gcd 属于整数, 可正可负)

例如 : 15 和 10的最大公约数为5, 则有15 + (-1)*10 = 5 ;   98 和 24 的最大公约数为2, 则有98 + (-4)*24 = 2 

**扩展的欧几里得算法 :** 用于求解形如 ax +by = c (a,b,c 属于整数, 可正可负)  的方程

现在再回过头来看 (de) mod φ(n) = 1, 转化为 (de - 1) mod φ(n) = 0, 即de -1 是 φ(n) 的倍数, 即有 kφ(n) = de - 1  ==>  kφ(n) + ed =  1 (k < 0)  此时方程就形如 ax + by = c了. 所以求 d 的值我们用扩展的欧几里得算法, 具体如下:

```cpp
void exgcd(int a, int b, int* x, int* y) {
	if (b == 0) {
		*x = 1;
		*y = 0;
		return;
	}
	exgcd(b, a % b, x, y);
	int tmp = *x;
	*x = *y;
	*y = tmp - a / b * (*y);
}
```
______
### 问题2 : 大数的幂运算 

> 具体问题
> 
> 1. 在计算机计算大数的指数的过程中, 计算的数字不断增大, 非常的占用我们的计算资源
> 2. 我们计算的中间过程数字大的恐怖, 我们现有的计算机是没有办法记录这么长的数据的, 会导致溢出. 

**解决办法 :快速幂取模运算**

首先了解一下**同余定理**, 公式如下

```cpp
(a + b) % c = ((a % c) + (b % c)) % c
(a - b) % c = ((a % c) - (b % c)) % c
(a * b) % c = ((a % c) * (b % c)) % c
(a / b) % c = ((a % c) / (b % c)) % c
a^b % c = (a * a * a *...* a) % c
        = ((a % c) * (a % c) * (a % c) *...* (a % c)) % c
        = (a % c)^b % c 
```


**模幂运算**

对于 a^b % c, 其中b的展开式如下 : 

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200415235351689.png)

公式中的b0, b1...bn对应的是b的二进制第1位, 第2位....第n位, 二进制的值只有两种可能, 0或1, 所以我们的a^b运算就可以拆解成

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200415235359173.png)

那么我们去除掉其中bi 为0的二进制位(即a^0 = 1), 保留bi = 1之后得到下面式子

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200415235420332.png)  ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200415235425962.png)                    
我们再用上面的同余定理, a^b % c 就可以转换为下面式子

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200415235458713.png)

如果我们令

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200415235511371.png)

其中 : 

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020041523551980.png)             

我们发现A(n - 1) 和 An 之间 %c 之前的数是平方关系, 继续变形

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020041523554032.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200415235546741.png)         

根据同余定理中 (a * b) % c = ((a % c) * (b % c)) % c进行变形

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020041523561255.png)

这样模幂运算的最终推导式就推导出来了, 极大地简化了大数的模幂运算, 再回到计算最终结果的式子上

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200415235620188.png)

可以得到, 计算在最终结果需要直到Ai 到An 的值, 而又有 An = (A(n - 1) * A(n - 1)) % c, 也就是说最终我们在进行模幂运算时, 我们运算的复杂度已经和指数b的大小没有直接关系了, 有直接关系的是b的二进制bit位数

______

### 问题3 : 大数的加/减/乘/除/模运算

> 在RSA算法中的数字极大, 是我们现有计算机无法直接计算的, 所以需要我们手动实现大数的加减乘除.

先自己手动实现一个带符号的加减乘除模运算

代码戳链接 : GitHub链接（￣︶￣）↗ [https://github.com/yyaihh/File-encryption-tools/tree/master/](https://github.com/yyaihh/File-encryption-tools/tree/master/)

码云链接（￣︶￣）↗　[https://gitee.com/yyaihh/file-encryption-tools/tree/master/%E5%A4%A7%E6%95%B0](https://gitee.com/yyaihh/file-encryption-tools/tree/master/%E5%A4%A7%E6%95%B0)

由于自己实现的一般没有大佬封装的库中的效率高, 所以我们在项目中直接用C++现有的库, boost库中的大数运算库cppp_int

这里我用的是boost_1_58_0版本的大数库,下载链接 [https://nchc.dl.sourceforge.net/project/boost/boost/1.58.0/boost_1_58_0.7z](https://nchc.dl.sourceforge.net/project/boost/boost/1.58.0/boost_1_58_0.7z)

使用需添加头文件#include<boost/multiprecision/cpp_int.hpp>, 本次开发编译器是VS2017, boost库下载解压好之后, 在VS中还需要将解压好的boost库路径添加到附加目录, 步骤如下

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200416000108199.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxMDcxMDY4,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200416000121702.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxMDcxMDY4,size_16,color_FFFFFF,t_70)
 boost中的cpp_int库的介绍文档
 [https://www.boost.org/doc/libs/1_58_0/libs/multiprecision/doc/html/boost_multiprecision/tut/ints/cpp_int.html
](https://www.boost.org/doc/libs/1_58_0/libs/multiprecision/doc/html/boost_multiprecision/tut/ints/cpp_int.html)
下面简单介绍一下cpp_int库的用法

```cpp
cpp_int        任意位的大数

int128_t;     有符号固定128位大数
int256_t;     有符号固定256位大数
int512_t;     有符号固定512位大数
int1024_t;    有符号固定1024位大数

uint128_t;     无符号固定128位大数
uint256_t;     无符号固定256位大数
uint512_t;     无符号固定512位大数
uint1024_t;    无符号固定1024位大数
```

它们的使用, 也就是加减乘除模等运算与内置类型是一样的, 因为boost库中重载了+ - * / % & | 左移, 右移,前置++/--, 后置++/--, +=, -=, *=, /= 等运算符, 甚至连sqrt(), max(), min(), abs()等数学计算中常用函数也都重载了, 所以我们原来怎么用内置类型, 就怎么用cpp_int中的大数类型.

但值得注意的是, cpp_int库中的大数初始化需要了解一下, 如下 :

```cpp
#include<iostream>
#include<string>
#include<boost/multiprecision/cpp_int.hpp>

namespace bm = boost::multiprecision;
void test() {
	char n1[] = "1234567345643123333333333333333456777777777777777777543234565434565432";
	const char* n2 = "6234563425656643425675434235654321345671324567543245734256765345677586";
	const char* n3 = "6234563425656643425675434235654321345671324567543245734256765345677586";
	string s = n1;
	s += n2;
	s += n3;
	bm::int1024_t bn1(n1);
	bm::int1024_t bn2(s);
	bm::cpp_int bn3 = bn1 * bn2;
	std::cout << bn1 << std::endl << std::endl;
	std::cout << bn2 << std::endl << std::endl;
	std::cout << bn3 << std::endl << std::endl;
}
int main() {
	test();
	return 0;
}
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200416000225386.png)
_____
### 问题4 : 大数产生随机数

> 我们平时用的随机数函数是 srand()设置随机数种子, 一般传入time(0), 用 rand()获取随机数, 随机数 = rand %num; 随机数范围是 [0, num). 在不同平台的不同编译器下rand()函数所能获取的随机数的范围不同,但由于目前CPU位数的限制, 顶多也就是个64位的数字, 所以我们还需要能产生大随机数的方法.

解决方法 : 还是在boost库的random库中 有着大数随机数的获取方法.
需要包含头文件#include<boost/multiprecision/random.hpp>

```cpp
#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/multiprecision/random.hpp>
namespace br = boost::random;
namespace bm = boost::multiprecision;

oid test() {
	bm::int1024_t n;
	br::mt19937 gen((size_t)time(0));//随机数发生器
        //mt19937:一种随机数产生器
	br::uniform_int_distribution<bm::int1024_t> dist(bm::int1024_t(0), bm::int1024_t(1) << 128);
        //设置范围[0, 1<<128)
	for (int i = 0; i < 10; ++i) {
		std::cout << dist(gen) << std::endl;
	}
}
int main() {
	test();
	return 0;
}
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200416000324125.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxMDcxMDY4,size_16,color_FFFFFF,t_70)
_____

### 问题5 : 大数产生素(质)数

> 大数的素性检测有专门的算法, 比如fermat检测, Miller-Rabin等算法.在boost库中的实现了Miller-Rabin素性检测算法

需要添加头文件#include <boost/multiprecision/miller_rabin.hpp>

说明文档 : [https://www.boost.org/doc/libs/1_58_0/libs/multiprecision/doc/html/boost_multiprecision/tut/primetest.html](https://www.boost.org/doc/libs/1_58_0/libs/multiprecision/doc/html/boost_multiprecision/tut/primetest.html)

```cpp
#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/multiprecision/random.hpp>
#include<boost/multiprecision/miller_rabin.hpp>
namespace br = boost::random;
namespace bm = boost::multiprecision;

bm::int1024_t GetPrime() {
	bm::int1024_t res;
	br::mt19937 gen((size_t)time(0));
	br::uniform_int_distribution<bm::int1024_t> dist(bm::int1024_t(0), (bm::int1024_t(1) << 128));
	while (!isPrime(res = dist(gen)));
	return res;
}
bool isPrime(bm::int1024_t& num) {
	br::mt11213b gen((size_t)time(0));//要和产生随机数的发生器不一样
	if (miller_rabin_test(num, 25, gen)) {
		if (miller_rabin_test((num - 1) / 2, 25, gen)) {
			return true;
		}
	}
	return false;
}
int main() {
	std::cout << GetPrime();
	return 0;
}
```

template <class Backend, expression_template_option ExpressionTemplates, class Engine>
bool miller_rabin_test(const number<Backend, ExpressionTemplates>& num, unsigned trials, Engine& gen)

这个函数用于素性检测, 若返回 false, 则说明检测的数一定不是一个素数, 若返回true, 则说明有很大可能是素数, 返回true时不是素数的可能性是0.25^trials, 是一个非常小的可能性. 如果第一次返回结果为真, 我们再检测一次(n - 1) / 2是否为素数, 如果两次素性检测都返回true, 那么num是素数的可能性无限接近于1, 我们则认为num就是素数. trials值推荐是25.

## 结束

