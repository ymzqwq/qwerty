#include<bits/stdc++.h>
#define LL long long
#define lson node<<1
#define rson node<<1|1
using namespace std;
const int N=6;
const int M=N<<1;
int n,q,v[M],head[N],Next[M],cnt,pre[N],dfn[N],t[N<<3],lazy[N<<3];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void add(int x,int y){
	Next[++cnt]=head[x];
	head[x]=cnt;
	v[cnt]=y;
}

void dfs(int x,int f){
	pre[x]=++cnt;
	for(int i=head[x];i!=-1;i=Next[i])
	 if (v[i]!=f) dfs(v[i],x);
	dfn[x]=++cnt;
}

void push_down(int node){
	lazy[node]=0;
	lazy[lson]=lazy[rson]=1;
	t[lson]=t[rson]=0;
}

void fill(int node,int L,int r,int x,int y){
	if (L>=x&&r<=y){
		t[node]=0;
		lazy[node]=1;
		return;
	}
	int mid=(L+r)>>1;
	if (lazy[node]) push_down(node);
	if (x<=mid) fill(lson,L,mid,x,y);
	if (y>mid) fill(rson,mid+1,r,x,y);
	t[node]=t[lson]||t[rson];
}

void empty(int node,int L,int r,int x){
	if (L==r&&r==x){
		t[node]=1;
		return;
	}
	int mid=(L+r)>>1;
	if (lazy[node]) push_down(node);
	if (x<=mid) empty(lson,L,mid,x);
	 else empty(rson,mid+1,r,x);
	t[node]=t[lson]||t[rson];
}

int query(int node,int L,int r,int x,int y){
	if (!t[node]) return 0;
	if (L>=x&&r<=y) return 1;
	int ans=0;
	int mid=(L+r)>>1;
	if (lazy[node]) push_down(node);
	if (x<=mid) ans=ans||query(lson,L,mid,x,y);
	if (ans) return ans;
	if (r>mid) ans=ans||query(rson,mid+1,r,x,y);
	return ans;
}

int main(){
	read(n);
	memset(head,-1,sizeof head);
	for(int i=1;i<n;i++){
		int x,y;
		read(x);read(y);
		add(x,y);
		add(y,x);
	}
	
	cnt=0;dfs(1,0);
	
	read(q);
	for(int i=1;i<=n<<3;i++) t[i]=1;
	for(int i=1;i<=q;i++){
		int tp,x;
		read(tp);read(x);
		if (tp==1) fill(1,1,cnt,pre[x],dfn[x]);
		 else if (tp==2) empty(1,1,cnt,pre[x]),empty(1,1,cnt,dfn[x]);
		  else printf("%d\n",1^query(1,1,cnt,pre[x],dfn[x]));
	}
	return 0;
}


/*
4
1 2 
2 3
3 4
4
1 1
2 2
1 2
3 1
*/
