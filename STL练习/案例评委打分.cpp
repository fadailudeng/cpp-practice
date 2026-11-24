#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
class Person{
    public:
    Person(string name,float score)
    {
        this->name=name;
        this->score=score;
    }
    string name;
    float score;
};
void creatplayer(vector<Person>&v)
{
        string name1="ABCDE";
        for(int i=0;i<5;i++){
            string name2="选手";
            name2+=name1[i];
            int score=0;
            Person p(name2,score);
            v.push_back(p);
        }
}
void printPlayer(vector<Person>&v)
{
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"选手:"<<(*it).name<<"成绩:"<<(*it).score<<endl;
    }
}
void Insertscore(vector<Person>&v)
{
    float s;
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        deque<int>d;
        for(int i=0;i<10;i++)
        {
                int score=rand()%41+60;
                d.push_back(score);
        }
        sort(d.begin(),d.end());
        d.pop_back();
        d.pop_front();
        s=0;
        for(int j=0;j<d.size();j++)
        {
            s+=d[j];
        }
        (*it).score=(s/d.size());
    }
}
int main()
{
    vector<Person>v;
    creatplayer(v);
    Insertscore(v);
    printPlayer(v);
    return 0;
}