#include<bits/stdc++.h>
using namespace std;
#define LIM 100005
#define MAX 10000007
vector<int>G[LIM];
int dis[LIM];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    while(!q.empty())
          {
             int t=q.front();
                q.pop();
              for(int i=0;i<G[t].size();i++)
              {
                  int v=G[t][i];
                  if(dis[v]==0)
                  {
                      dis[v]=1;
                      q.push(v);
                  }
              }
          }
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
            //G[v].push_back(u);
        }
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==0)
            {
                bfs(i);
                c++;
            }
        }
        cout<<c<<endl;
    }
}

