#include<bits/stdc++.h>
using namespace std;
#define LIM 100005
#define MAX 10000007
vector<int>G[LIM];
int vis[LIM];
void dfs(int u)
{
    dis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(dis[v]!=1)
            dfs(v);
    }
}
int main()
{
    int ;
    cin>>t;
    while(t--)
    {
        int n,m,u,v;
        cin>>n>>m;
        for(int i=0;i<m;i++)
            {
                cin>>u>>v;
                G[u].push_back(v);
                G[v].push_back(u);
            }
            memset(vis,0,sizeof(vis));
            dfs(1);

    }
}
