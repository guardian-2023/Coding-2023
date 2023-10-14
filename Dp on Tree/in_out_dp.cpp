// Problem - https://codeforces.com/contest/1881/problem/F
  
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define int long long int
#define ff first
#define ss second
int power(int n,int q){
    int ans=1;
    n%=mod;
    while(q>0){
        if(q&1)
        ans=(ans*n)%mod;
        n=(n*n)%mod;
        q>>=1;
    }
    return ans%mod;
}
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int M=200005;
int in[M]={0},out[M]={0},b[M]={0};
vector<int> g[M];
int n,k;
int dfs1(int u, int par){
    in[u]=b[u];
    for(auto v:g[u]){
        if(v==par)continue;
        dfs1(v,u);
        if(in[v]>0)in[u]=max(in[u],1+in[v]);
    }
}
int dfs2(int u, int par){
    int mxi1=-1,mxi2=-1, mx1=-1,mx2=-1;
    for(auto v:g[u]){
        if(v==par)continue;
        if(in[v]>=mx1){
            mxi2=mxi1; mx2=mx1;
            mxi1=v; mx1=in[v];
        }
        else if(in[v]>mx2){
            mxi2=v;mx2=in[v];
        }
    }
    for(auto v:g[u]){
        if(v==par)continue;
        if(b[u])out[u]=max(out[u],(int)1);
        if(out[u])out[v]=max(out[v],1+out[u]);
        if(v!=mxi1){
            if(in[mxi1])out[v]=max(out[v],2+in[mxi1]);
        }
        else {
            if(in[mxi2])out[v]=max(out[v],2+in[mxi2]);
        }
        dfs2(v,u);
    }
}
main()
{
	int t=10;
	fast();t=1;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    for(int i=1;i<=k;i++){
	        int xx;
	        cin>>xx;b[xx]=1;
	    }
	    for(int i=1;i<=n-1;i++){
	        int x,y;
	        cin>>x>>y;
	        g[x].pb(y);
	        g[y].pb(x);
	    }
	    dfs1(1,0);
	    dfs2(1,0);
	    int ans=1e6;
        for(int i=1;i<=n;i++){
            ans=min(ans,max(in[i],out[i]));
            in[i]=out[i]=0;
            b[i]=0;
            g[i].clear();
        }
        cout<<ans-1<<endl;
	}
}
