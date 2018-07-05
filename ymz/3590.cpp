#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int n;
struct data{
	int x,y;
}a[N];

int cmp(const data q,const data w){
	if (q.x==w.x) return q.y<w.y;
	return q.x<w.x;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) printf("%d %d\n",a[i].x,a[i].y);
	return 0;
}
