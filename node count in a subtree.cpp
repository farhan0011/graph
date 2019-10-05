#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>g;
map<int,int>dis;
map<int,int>fin;
map<int,int>sub;
int tim;
void dfs(int u)
{
    dis[u]=++tim;
    sub[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(dis[v]==-1)
        {
            dis[v]=1;
            dfs(v);
            sub[u]+=sub[v];
        }
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
            g[u].push_back(v);
            g[v].push_back(u);
            dis[u]=-1;
            dis[v]=-1;
            fin[u]=-1;
            fin[v]=-1;
        }
        int src;
        cin>>src;
        dfs(src);
        int node,q;
        cin>>q;
        while(q--)
        {
            cin>>node;
            //cout<<sub[node]<<endl;
            int ans=(fin[node]-dis[node])/2;
            cout<<1+ans<<endl;
        }

    }
}
