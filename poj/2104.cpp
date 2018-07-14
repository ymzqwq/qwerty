#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
const int N=200011;
int n,m,a[N],cnt,x,y,k,num[N],mp[N];
struct node{
	int v;
	node* ch[2];
	
	node(){
		v=0;
		ch[0]=ch[1]=NULL;
	}
};
node* rt[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void mks(node* &o){
	if (o->ch[0]==NULL) o->ch[0]=new node();
	if (o->ch[1]==NULL) o->ch[1]=new node();
}

void insert(node* &pre,node* &o,int L,int r,int v){
	o->v=pre->v+1;
	if (L==r) return;
	mks(pre);mks(o);
	int mid=(L+r)/2;
	int d=v>mid;
	o->ch[d^1]=pre->ch[d^1];
	if (d) insert(pre->ch[d],o->ch[d],mid+1,r,v);
	 else insert(pre->ch[d],o->ch[d],L,mid,v);
}

int sol(node* &pre,node* &o,int L,int r,int k){
	if (L==r) return L;
	mks(pre);mks(o);
	int vL=o->ch[0]->v - pre->ch[0]->v;
	int mid=(L+r)/2;
	if (k<=vL) return sol(pre->ch[0],o->ch[0],L,mid,k);
	 else return sol(pre->ch[1],o->ch[1],mid+1,r,k-vL);
}

inline int cmp(const int &q,const int &w) { return a[q]<a[w]; }

int main(){
	read(n);read(m);
	for(int i=1;i<=n;++i) read(a[i]),num[i]=i;
	sort(num+1,num+1+n,cmp);
	for(int i=1;i<=n;++i) mp[num[i]]=i;
	
	for(int i=0;i<=n;++i) rt[i]=new node();
	for(int i=1;i<=n;++i)
	 insert(rt[i-1],rt[i],1,n,mp[i]);
	
	while(m--){
		read(x);read(y);read(k);
		printf("%d\n",a[num[sol(rt[x-1],rt[y],1,n,k)]]);
	}
	return 0;
}
