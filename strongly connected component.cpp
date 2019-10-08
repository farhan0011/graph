#include<bits/stdc++.h>
using namespace std;
map<int,int>vis;
map<int,int>invis;
map<int,int>comp;
map<int,vector<int>>g;
map<int,vector<int>>ing;
stack<int>st;
void dfs(int s)
{
    vis[s]=1;
    for(int i=0;i<g[s].size();i++)
    {
        int p=g[s][i];
        if(vis[p]==-1)
            dfs(p);
    }
    st.push(s);
}
void dfs2(int s,int cnt)
{
    invis[s]=1;
    comp[s]=cnt;
    //cout<<comp[s]<<" "<<cnt<<endl;
    for(int i=0;i<ing[s].size();i++)
    {
        int p=ing[s][i];
        if(invis[p]==-1)
            dfs2(p,cnt);
    }
}
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,m;
    cin>>n>>m;
    int u,v;
    g.clear();
    ing.clear();
    vis.clear();
    comp.clear();
    while(!st.empty())
        st.pop();
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        ing[v].push_back(u);
        vis[u]=-1;
        vis[v]=-1;
        invis[u]=-1;
        invis[v]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==-1)
            dfs(i);
    }
    int cnt=0;
    while(!st.empty())
    {
       int x=st.top();
       st.pop();
       if(invis[x]==-1)
       {
           //cout<<"XVXG"<<endl;
           cnt++;
           dfs2(x,cnt);
       }
    }
    //cout<<cnt<<endl;
    for(auto it=comp.begin();it!=comp.end();it++)
        //cout<<"IIY"<<endl;
        cout<<it->first<<" "<<it->second<<endl;
    }
}
/*
5 7
1 2
1 4
2 4
3 2
3 4
4 5
5 3
7 8
1 7
2 1
2 3
3 4
4 2
5 1
6 5
7 6
*/
