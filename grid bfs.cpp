#include<bits/stdc++.h>
using namespace std;
#define LIM 1003
#define pi pair<int,int>
#define MAX 10000007
int dis[LIM][LIM];
int grid[LIM][LIM];
int dr[]={-1,+1,0,0};
int dc[]={0,0,-1,+1};
void bfs(int n,int m)
{
    dis[1][1]=0;
    queue<pi>q;
    q.push(pi(1,1));
    while(!q.empty())
    {
        pi u=q.front();
        int ur=u.first;
        int uc=u.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int vr=ur+dr[i];
            int vc=uc+dc[i];
            if(dis[vr][vc]==-1&&vr>=1&&vr<=n&&vc>=1&&vc<=m)
            {
                dis[vr][vc]=dis[ur][uc]+1;
                q.push(pi(vr,vc));
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    int n,m;
    for(int k=1;k<=t;k++)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                dis[i][j]=-1;
        }
        bfs(n,m);
        cout<<dis[n][m]<<endl;
    }
}
