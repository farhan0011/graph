#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
map<int,vector<int>>G,W;
map<int,int>dis;
struct info
{
    int u,k;
    info(){}
    info(int uu,int kk)
    {
        u=uu;
        k=kk;
    }
    bool operator < (const info &b)const
    {
        if(k>b.k)
            return true;
        else
            return false;
    }
};
void dj(int s)
{
    priority_queue<info>pq;
    pq.push(info(s,0));
    dis[s]=0;
    while(!pq.empty())
    {
        info U=pq.top();
        pq.pop();
        int u=U.u;
        int k=U.k;
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            int w=W[u][i];
            if(dis[u]+w<dis[v])
            {
                //cout<<"IOUT"<<endl;
                dis[v]=dis[u]+w;
                pq.push(info(v,w));
            }
        }
    }
}
int main()
{
    int n,m,u,v,w;
    cin>>n>>m;
    G.clear();
    W.clear();
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        G[u].push_back(v);
        G[v].push_back(u);
        W[u].push_back(w);
        W[v].push_back(w);

    }
    for(int i=1;i<=n;i++)
        dis[i]=MAX;
    int s;
    cin>>s;
    dj(s);
    for(auto it=dis.begin();it!=dis.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
}
/*
5 5
1 2 1
1 3 10
2 5 100
3 4 10
4 5 10
1
*/
