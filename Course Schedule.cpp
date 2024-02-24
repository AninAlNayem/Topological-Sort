#include<bits/stdc++.h>
using namespace std;
 
const int mx=1e5+10;
vector<int>G[mx];
vector<int>order;
queue<int>Q;
int indig[mx],cnt;
 
void toposort(){
   cnt=0;
   while(!Q.empty()){
     int u=Q.front();
     Q.pop();
     order.push_back(u);cnt++;
     for(int i=0;i<G[u].size();i++){
        int node=G[u][i];
        indig[node]--;
        if(!indig[node])
            Q.push(node);
     }
   }
}
 
 
int main(){
 
   int node,edge;
   cin>>node>>edge;
   for(int i=0;i<edge;i++){
      int u,v;
      cin>>u>>v;
      G[u].push_back(v);
      indig[v]++;
   }
 
   for(int i=1;i<=node;i++){
     if(!indig[i])
        Q.push(i);
   }
 
   toposort();
 
   if(cnt!=node){
      cout<<"IMPOSSIBLE"<<"\n";
   }
   else{
      for(int i=0;i<order.size();i++)
        cout<<order[i]<<" ";
 
   } cout<<"\n";
 
return 0;
}
