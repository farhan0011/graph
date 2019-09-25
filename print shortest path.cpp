#include<bits/stdc++.h>
using namespace std;
#define LIM 100005
#define MAX 10000007
vector<int>G[LIM];
int par[LIM],vis[LIM];
bool bfs(int s)
{
    bool ans=true;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if(vis[v]==0)
                {
                    vis[v]=1;
                    q.push(v);
                }
            else if(vis[v]==1&&par[u]!=v)
                ans=false;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int u,v,c=0;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
            if(par[v]==0)
            {
                c++;
                par[v]=u;
            }
        }

        for(int i=1;i<=n;i++)
            cout<<par[i]<<" ";
        cout<<endl;
        vector<int>path;
        v=9;
        path.push_back(v);
        while(v!=0)
        {
            v=par[v];
            path.push_back(v);
        }
        reverse(path.rbegin(),path.rend());
        for(int i=0;i<path.size();i++)
            cout<<path[i]<<" ";
        cout<<endl;
        /*memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                if(bfs(i))
                cout<<"No cycle"<<endl;
                else
                cout<<"it has a cycle"<<endl;
            }
        }*/
    }
}
/*
2
9 10
1 2
1 3
1 4
3 5
3 6
4 7
4 9
5 8
6 8
6 9
*/
