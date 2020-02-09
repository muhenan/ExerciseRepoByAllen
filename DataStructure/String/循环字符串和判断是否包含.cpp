#include<iostream>
#include<string>
#include<cstring>
using namespace std;


// 这里直接拿了自己数据结构期末复习用的题目


/*
C 中的 strstr strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串
getline(cin,str)
substr(begin,count) 左闭
length
c_str
*/
int main(){
    string all;
    getline(cin,all);
    //根据空格，分割 s1 s2 
    int index_space;
    for(index_space = 1; index_space < all.length(); index_space++) if(all[index_space] == ' ') break;
    cout << index_space << endl;
    string s1 = all.substr(0,index_space);
    string s2 = all.substr(index_space+1,all.length()-index_space-1);
    cout << s1<< endl;
    cout << s2<< endl;
    //先看一下本来包含不包含
    int count = s1.length();
    if(strstr(s1.c_str(),s2.c_str()) != NULL) {
            cout << "True";
            return 0;
        }
    //本来的不包含就开始循环 s1
    while (count--)
    {
        string temp1 = s1.substr(0,1);
        string temp2 = s1.substr(1,s1.length()-1);
        s1 = temp2.append(temp1);
        cout << s1 << endl;
        if(strstr(s1.c_str(),s2.c_str()) != NULL) {
            cout << "True";
            return 0;
        }
    }
    cout<< "False";
    return 0;
}



// 非常好，完全正确！！！！！！