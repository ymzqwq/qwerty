#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=60001;
const double EPS=1e-6;
int n,x[N],v[N];
double L=1e9,r;
 
void read(int &x){
    char ch=getchar();x=0;int w=1;
    for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
    x*=w;
}

double check(double xx){
	double ans=0;
	for(int i=1;i<=n;i++)
	 ans=max(ans,fabs(xx-x[i])/v[i]);
	return ans;
}
 
int main(){
    read(n);
    for(int i=1;i<=n;i++){
    	read(x[i]);
    	if (x[i]<L) L=x[i];
    	if (x[i]>r) r=x[i];
    }
    for(int i=1;i<=n;i++) read(v[i]);
    while(r-L>=EPS){
    	double mid1=(2*L+r)/3,mid2=(L+2*r)/3;
    	double ans1=check(mid1),ans2=check(mid2);
    	if (ans1>ans2) L=mid1;
    	 else r=mid2;
    }
    printf("%.5lf",check(L));
    /*double xx;
    while(cin>>xx) printf("%.5lf\n",check(xx));*/
    return 0;
}
