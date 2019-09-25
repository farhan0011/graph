#include<bits/stdc++.h>
using namespace std;
#define LIM 1003
#define pi pair<int,int>
#define MAX 10000007
int dis[LIM][LIM];
int grid[LIM][LIM];
int dr[]={-1,+1,0,0};
int dc[]={0,0,-1,+1};
void bfs(int N,int M)
{
    dis[0][0]=0;
    queue<pi>q;
    q.push(pi(0,0));
    while(!q.empty())
    {
        pi u=q.front;
        q.pop();
        int ur=u.first;
        int uc=u.second;
        for(int i=0;i<4;i++)
        {
            vr=ur+dr[i];
            vc=uc+dc[i];
            if(vr<0||vr>=N||vc<0||vc>=M)
                continue;
            if(dis[ur][uc]+1<dis[vr][vc])
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
    for(int i=1;i<=t;i++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                dis[i][j]=MAX;
        }
        bfs(8,8);
    }
}
