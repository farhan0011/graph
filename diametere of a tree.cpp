#include<bits/stdc++.h>
using namespace std;
map<int,int>dis;
map<int,vector<int>>g;
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(dis[v]==-1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }

}
int main()
{
    int n,m,u,v;
    cin>>n>>m;
    g.clear();
    dis.clear();
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        dis[u]=-1;
        dis[v]=-1;
    }
    bfs(1);
    int p=0,s=1;
    for(auto it=dis.begin();it!=dis.end();it++)
    {
        if(p<(it->second))
            {
                p=(it->second);
                s=it->first;
            }
    }
    cout<<s<<endl;
    for(int i=1;i<=n;i++)
        dis[i]=-1;
    bfs(s);
    p=0;
    for(auto it=dis.begin();it!=dis.end();it++)
    {
        if(p<(it->second))
            p=(it->second);
    }
    cout<<p<<endl;
}
/*
7 6
1 2
1 3
1 4
2 5
2 6
6 7
*/
