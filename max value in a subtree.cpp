#include<bits/stdc++.h>
using namespace std;
#define LIM 1003
vector<int>G[LIM];
int vis[LIM],sub[LIM];
int tim;
void dfs(int u)
{
    vis[u]=1;
    sub[u]=max(u,sub[u]);
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(vis[v]==-1)
        {
            dfs(v);
            sub[u] = max(sub[u],sub[v]);
        }
    }
    //fin[u]=++tim;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(G,0,sizeof G);
        memset(sub,0,sizeof sub);
        int n,m,u,v;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(vis,-1,sizeof vis);
        dfs(1);
        int q;
        cin>>q;
        while(q--)
        {
            int u;
            cin >> u;
            cout<< sub[u] << endl;
        }

    }
}
/*
3
15
1 2
1 3
1 4
2 6
2 10
3 20
3 50
4 60
4 90
10 5
10 100
50 200
50 300
90 250
90 600
*/

