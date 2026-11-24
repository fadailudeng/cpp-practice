#include <iostream>
using namespace std;
#include <string>
void text01()
{
    string s1="啥啊这是";
    string s2="啥也不是";
    string s3="abcad";
    s1+=s2;
    s1.assign(s3);
    cout<<s1<<endl;
}
int main()
{
    text01();
    return 0;
}