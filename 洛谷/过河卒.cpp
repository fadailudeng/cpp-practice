#include <iostream>
using namespace std;
int main()
{
    int x,y,n,m;
    cin>>n>>m>>x>>y;
    int i,j,dp[25][25]={0};
    int dx[8]={2,2,-2,-2,1,1,-1,-1},dy[8]={1,-1,1,-1,2,-2,2,-2};
    dp[x][y]=-1;
    for(i=0;i<8;i++)
    {
        if(x+dx[i]>=0&&x+dx[i]<=m&&y+dy[i]>=0&&y+dy[i]<=n)
        dp[x+dx[i]][y+dy[i]]=-1;
    }
    dp[0][0]=1;
    for(i=1;i<=n;i++)
    {
        if(dp[i][0]==-1)
        {
            dp[i][0]=0;
            break;
        }
        dp[i][0]=1;
    }
    for(i=1;i<=m;i++)
    {
        if(dp[0][i]==-1)
        {
            dp[0][i]=0;
            break;
        }
        dp[0][i]=1;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(dp[i][j]==-1)
            {
                dp[i][j]=0;
                continue;
            }
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    // 棋盘开到25足够
    long long dp[25][25] = {0};
    // 马的8个方向
    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    bool vis[25][25] = {false};
    int n, m, x, y;
    // 输入：终点n,m  马x,y
    cin >> n >> m >> x >> y;
    // 标记马不能走的点
    vis[x][y] = true;
    for (int i = 0; i < 8; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m)
            vis[nx][ny] = true;
    }
    // 起点
    dp[0][0] = 1;
    // 初始化第一列
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i][0]) break;
        dp[i][0] = 1;
    }
    // 初始化第一行
    for (int j = 1; j <= m; ++j)
    {
        if (vis[0][j]) break;
        dp[0][j] = 1;
    }
    // DP
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (vis[i][j])
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}