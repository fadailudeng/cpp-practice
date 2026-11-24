#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

void test01()
{
    string s1;
    const char *str2="hello world";
    string s2(str2);
    cout<<s2<<endl;
    string s3(s2);
    cout<<s3<<endl;
    string s4(10,'a');
    cout<<s4<<endl;
}
int main()
{
    test01();
    return 0;
}