#include<bits/stdc++.h>
using namespace std;
#define LIM 100005
#define MAX 10000007
vector<int>G[LIM];
int vis[LIM];
bool colour(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=0;
    int c=1;
    bool ans=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
            for(int i=0;i<G[u].size();i++)
            {
                int v=G[u][i];
                if(vis[v]==-1)
                    {
                        vis[v]=c;
                        q.push(v);
                    }
                else if(vis[v]==vis[u])
                    ans=false;
            }
            if(c==0)
                c=1;
            else
                c=0;

    }
    return ans;
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
            G[v].push_back(u);
        }
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==-1)
            {
                if(colour(i))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            }
        }
    }
}
