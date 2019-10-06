#include<bits/stdc++.h>
using namespace std;
map<string,int>vis;
vector<string>v;
map<string,vector<string>>g;
void dfs(string s)
{
    vis[s]=1;
    for(int i=0;i<g[s].size();i++)
    {
        string sol=g[s][i];
        if(vis[sol]==-1)
            dfs(g[s][i]);
    }
    v.push_back(s);
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    string s,s1;
    set<string>name;
    g.clear();
    v.clear();
    for(int i=0;i<edge;i++)
    {
        cin>>s>>s1;
        name.insert(s);
        if(s1!="NULL")
        g[s].push_back(s1);
        else
            g[s].push_back("");
        vis[s]=-1;
        vis[s1]=-1;
    }
    for(auto it=name.begin();it!=name.end();it++)
    {
        cout<<(*it)<<": "<<endl;
        /*for(int j=0;j<g[(*it)].size();j++)
            cout<<g[(*it)][j]<<" ";
            cout<<endl;*/
        if(vis[(*it)]==-1)
          dfs((*it));
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
        cout<<endl;

}
/*
9
9
shoe pant
shoe shocks
shoe shirt
bag NULL
shocks pant
coat shirt
breakfast brush
belt pant
belt shirt
*/
