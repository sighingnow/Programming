#include <iostream>
#include <cstdio>
#include <string>
/**
 * 解析：
 * 先考虑一维的情况，若第x个数被翻转奇数次，那么它的约数必定有奇数个，而只有平
 * 方数的约数是奇数个，那么也就是说对于一维的情况只有x为平方数时它才被翻转奇数
 * 次，对于二维的情况(x,y)点被翻转情况是x的约数*y的约数为该点翻转的次数，只有当
 * 这个数为奇数时，该点才被翻转奇数次，而奇数*奇数==奇数，也就是说x和y必须都是
 * 平方数才行，那么答案出来了，一个n行m列的矩阵在行上有sqrt(n)个平方数，在列上
 * 有sqrt(m)个平方数，组合出来的平方点对一共是sqrt(n)*sqrt(m).
 *
 * 只有坐标为(i, j)，i和j都是完全平方数的硬币是才会被翻面，其他的硬币都会维持正
 * 面。因为如果不是完全平方数的话有偶数个约数，会被翻转偶数次。而完全平方数有奇
 * 数个约数，比如4，有1,2,4三个约数，会被翻奇数次，反面的变为正面。初始反面的有
 * sqrt(n) * sqrt(m)个。
 */

/* 大数相乘 */
string operator * (string str1, string str2) { 
    string result = ""; 
    int len1 = str1.length(); 
    int len2 = str2.length(); 
    int num[1002] = {0}; // 此处用来临时保存两数相乘的结果 
    int i, j; 
  
    if (!len1 || !len2) return "0"; // 处理空指针 
  
    for (i = 0; i < len1; ++i) { 
        for (j = 0; j < len2; ++j) 
            num[len1-1-i + len2-1-j] += (str1[i] - '0') * (str2[j] - '0'); 
    } 
  
    for (i = 0; i < len1 + len2; ++i) { 
        num[i+1] += num[i] / 10; 
        num[i] %= 10; 
    } 
  
    for (i = len1 + len2 - 1; !num[i]; --i); 
    for ( ; i >= 0; --i) 
        result += num[i] + '0'; 
      
    if (result.length() == 0) result = "0"; 
    return result; 
} 
  
bool str_bigger(string str1, string str2, int zeros) { 
    int len1 = str1.length(); 
    int len2 = str2.length(); 
    int i, j; 
  
    if (len1 + zeros < len2) return false; 
    else if (len1 + zeros > len2) return true; 
  
    for (i = 0; i < len1; ++i) { 
        if (str1[i] > str2[i]) return true; 
        else if (str1[i] < str2[i]) return false; 
    } 
  
    return false; 
} 
  
/* 返回sqrt(n)的取整结果 */
string sqrt_large(string str) { 
    int len = str.length(); 
    int i, j, len1 = len >> 1; 
    string str1 = ""; 
  
    if (len & 1) ++len1; // 长度为奇数，例如121=11*11 
      
    for (i = 0; i < len1; ++i) { 
        str1 += '0'; 
        for (j = 0; j < 10; ++j) { 
            str1[i] = j + '0'; // attention 
            // 第三个参数为第一个串的尾零个数 
            if (str_bigger(str1 * str1, str, (len1-(i+1)) << 1)) { 
                --str1[i]; break; 
            } 
        } 
    } 
  
    return str1; 
} 
  
int main() { 
    string a, b; 
    while (cin >> a >> b) { 
        cout << sqrt_large(a) * sqrt_large(b) << endl; 
    } 
    return 0; 
}

