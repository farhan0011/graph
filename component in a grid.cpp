#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
map<pi,int>dis;
map<pi,int>vis;
int dr[]={+1,-1, 0, 0};
int dc[]={ 0, 0,+1,-1};
void bfs(pi s,int n,int m,map<pi,char>g)
{
    queue<pi>q;
    q.push(s);
    vis[s]=0;
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
            if(vr>=1&&vr<=n&&vc>=1&&vc<=m&&vis[pi(vr,vc)]==-1&&g[pi(vr,vc)]=='.')
            {
                vis[pi(vr,vc)]=0;
                q.push(pi(vr,vc));
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        map<pi,char>g;
        char c;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                g[pi(i,j)]=c;
                vis[pi(i,j)]=-1;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[pi(i,j)]==-1&&g[pi(i,j)]=='.')
                {
                    cnt++;
                    cout<<"("<<i<<","<<j<<") ";
                    bfs(pi(i,j),n,m,g);
                }
            }
            cout<<endl;
        }
        cout<<cnt<<endl;
    }
}
/*
2
8 8
..*..*..
..*.***.
..*..*..
.*....**
*..***..
..*..**.
.*...*..
.****...
*/
