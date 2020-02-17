#include<bits/stdc++.h>
using namespace std;
#define LIM 100005
#define INF 10000007
vector<int>G[LIM];
vector<int>W[LIM];
int dis[LIM];
struct info
{
    int x,y;
    info(){}
    info(int xx,int yy)
    {
        x = xx;
        y = yy;
    }
    bool operator < (const info & b) const
    {
        return y>b.y;
    }
};
void dij(int n)
{
    for(int i=1;i<=n;i++)
        dis[i] = INF;
    priority_queue<info>pq;
    pq.push(info(1,0));
    dis[1]=0;
    while(!pq.empty())
    {
        //cout<<"lkj"<<endl;
        info U = pq.top();
        pq.pop();
        int u = U.x;
        int k = U.y;
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            int w = W[u][i];
            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                //cout<<u<<" to "<<v<<"  = "<<w<<endl;
                pq.push(info(v,w));
            }
        }
    }
}
int main()
{
    for(int i=0;i<LIM;i++)
    {
        G[i].clear();
        W[i].clear();
    }
    int n,m,u,v,w;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        G[u].push_back(v);
        W[u].push_back(w);
        G[v].push_back(u);
        W[v].push_back(w);
    }
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=0;j<G[i].size();j++)
//            cout<<i<<" to "<<G[i][j]<<" cost = "<<W[i][j]<<endl;
//    }
    dij(n);
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<endl;
}
/*
4 4
1 2 2
1 3 1
2 4 1
3 4 2
*/
