#include <iostream>
using namespace std;
#include <string>
void text01()
{
    string s1="Hello";
    string s2="World";
    string s3="abcad";
    s1+=s2;
    s1.append(s3);
    cout<<s1<<endl;
    int pos=s1.find("a");
    cout<<pos<<endl;
    s1.replace(10,4,"11");
    cout<<s1<<endl;
}
int main()
{
    text01();
    return 0;
}