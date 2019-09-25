#include<bits/stdc++.h>
using namespace std;
#define LIM 100005
#define MAX 10000007
vector<int>G[LIM];
int dis[LIM],fin[LIM],vis[LIM],tim=0;
void dfs(int u)
{
    vis[u]=1;
    dis[u]=++tim;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(vis[v]==0)
            dfs(v);
    }
    fin[u]=++tim;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,u,v;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            G[u].push_back(v);
        }
        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
        memset(fin,0,sizeof fin);
        dfs(1);
        for(int i=1;i<=n;i++)
        cout<<dis[i]<<" "<<fin[i]<<endl;
    }
}
