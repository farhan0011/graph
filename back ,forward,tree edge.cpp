///Directed Graph
#include<bits/stdc++.h>
using namespace std;
#define LIM 100005
#define MAX 10000007
vector<int>G[LIM];
int dis[LIM];
void dfs(int u)
{
    dis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(dis[v]==0)
        {
            dfs(v);
            cout<<"tree edge from:"<<u<<" to "<<v<<endl;
        }
        else if(dis[v]==1)
            cout<<"back edge from:"<<u<<" to "<<v<<endl;
        else
            cout<<"forward edge from:"<<u<<" to "<<v<<endl;
    }
    dis[u]=2;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,u,v;
        cin>>n>>m;
        for(int j=0;j<m;j++)
        {
            cin>>u>>v;
            G[u].push_back(v);
            //G[v].push_back(u);
        }
    }
    memset(dis,0,sizeof(dis));
    dfs(1);
}
