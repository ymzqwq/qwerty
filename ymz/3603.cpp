#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5001;
int n,w;
struct data{
	int x,y;
}a[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int cmp(const data &q,const data &w){
	if (q.x==w.x) return q.y<w.y;
	return q.x<w.x;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i].x),read(a[i].y);
	sort(a+1,a+1+n,cmp);
	w=a[1].y;
	for(int i=2;i<=n;i++)
	 if (a[i].y>=w) w=a[i].y;
	  else w=a[i].x;
	cout<<w;
	return 0;
}
