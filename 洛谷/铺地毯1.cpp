#include <iostream>
using namespace std;
int main()
{
    int n,x,y,t=0;
    int x1,y1;
    int p[10005][4];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>p[i][j];
        }
    }
    cin>>x>>y;
    for(int i=0;i<n;i++)
    {
        x1=p[i][0]+p[i][2];
        y1=p[i][1]+p[i][3];
        if(x>=p[i][0]&&x<=x1&&y>=p[i][1]&&y<=y1)
        {
            t=i+1;
        }
    }
   cout<<t<<endl;
    return 0;
}