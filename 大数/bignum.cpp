#include"bignum.h"
#include<algorithm>
string BigNum::add(string num1, string num2){
    string res;
    size_t len1 = num1.size(), len2 = num2.size();
    int left1 = 0, left2 = 0;
    res.reserve(len1 + len2 + 1);
    int num = 0, tmp = 0;
    int pos1 = len1 - 1, pos2 = len2 - 1;
    bool flag = false;
    if(num1[0] == '-'){
        left1 = 1;
        if(num2[0] == '-'){
            left2 = 1;
            flag = true;
        }
        else{
            return sub(num2, string(num1.begin() + 1, num1.end()));
        }
    }
    else{
        if(num1[0] == '+') left1 = 1;
        if(num2[0] == '-'){
            return sub(num1, string(num2.begin() + 1, num2.end()));
        }
        else if(num2[0] == '+'){
            left2 = 1;
        }
    }

    for(;pos1 >= left1 && pos2 >= left2; --pos1, --pos2){
        num = num1[pos1] + num2[pos2] + tmp - 96;
        res += (num % 10 + '0');
        tmp = num / 10;
    }
    for(; pos1 >= left1; --pos1){
        num = num1[pos1] + tmp - 48;
        res += (num % 10 + '0');
        tmp = num / 10;
    }
    for(; pos2 >= left2; --pos2){
        num = num2[pos2] + tmp - 48;
        res += (num % 10 + '0');
        tmp = num / 10;
    }
    if(tmp){
        res += (tmp + 48);
    }
    if(flag){
        res += '-';
    }
    reverse(res.begin(), res.end());
    return res;
}
string BigNum::sub(string num1, string num2){
    string res;
    if(num1[0] == '-'){
        if(num2[0]!='-'){//负 - 负  == 负 + 正 
            return add(string(num1.begin(),num1.end()), string(num2.begin() + 1, num2.end()));
        }
        else{//负 - 正
            res = add(string(num1.begin() + 1,num1.end()), string(num2.begin(), num2.end()));
            res.insert(res.begin(), '-');
            return res;
        }
    }
    else{//正 -
        if(num2[0] == '-'){//正 - 负
            return add(num1, string(num2.begin()+1, num2.end())); 
        }
    }
    bool flag = false;
    int left1 = 0, left2 = 0;
    if(num1[0] == '+') left1 = 1;
    if(num2[0] == '+') left2 = 1;
    int right1 = num1.size() - 1, right2 = num2.size() - 1, n;
    if(right1 - left2 < right2 - left2){
        num1.swap(num2);
        std::swap(left1, left2);
        std::swap(right1, right2);
        flag = true;
    }
    else if(right1 - left2 == right2 - left2){
        if(num1<num2){
            num1.swap(num2);
            std::swap(left1, left2);
            std::swap(right1, right2);
            flag = true;
        }
    }

    for(; right2>=0; --right1, --right2){
        n = num1[right1] - num2[right2];
        if(n<0){
            n += 10;
            for(int tmp = right1--; right1>=left1; --right1){
                if(num1[right1]!='0'){
                   --num1[right1];
                   right1 = tmp;
                   break;
                }
                num1[right1] = '9';
            }
        }
        num1[right1] = n + '0';
    }
    if(flag) res.push_back('-');
    for(n = left1; n < (int)num1.size() && num1[n] == '0'; ++n);
    for(;n<(int)num1.size();++n){
        res.push_back(num1[n]);
    }
    return res;
}
string BigNum::mul(string num1, string num2){
    int right1 = num1.size() - 1, right2 = num2.size() - 1;
    int tmplen = right1 + right2 + 3;
    string tmp(tmplen, '0'), res;
    res.reserve(tmp.size());
    int left1 = 0, left2 = 0;
    bool flag = false;
    if(num1[0] == '-'){
        flag = !flag;
        left1 = 1;
    }
    else if(num1[0] == '+'){
        left1 = 1;
    }
    if(num2[0] == '-'){
        flag = !flag;
        left2 = 1;
    }
    else if(num2[0] == '+'){
        left2 = 1;
    }

    int n, t;
    for(int i = tmp.size() - 1; right1 >= left1; --i, --right1){
        for(int cur = i, j = right2; j >= left2; --j, --cur){
            n = (num1[right1] - '0')*(num2[j] - '0');//相乘结果
            t = tmp[cur] + n % 10 - '0';//于原位置相加, 可能会进位, 先保存
            tmp[cur] = t % 10 + '0';//低位保存
            tmp[cur - 1] += (t / 10 + n / 10);//高位加上乘法的进位和加法的进位
        }
    }
    if(flag) res.push_back('-');
    for(n = 0; n < tmplen && tmp[n]=='0'; ++n);
    for(; n < tmplen; ++n){
        res.push_back(tmp[n]);
    }
    return res;
}
