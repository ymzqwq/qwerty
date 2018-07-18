#include<bits/stdc++.h>
#define LL long long
#define y1 _y1_
using namespace std;
const int N=32;
int x1,y1,z1,x2,y2,z2,x,y,z;
double a,b,c,cosA,cosB,ans;

inline int sqr(int x) { return x*x; }

int main(){
	cin>>x1>>y1>>z1>>x2>>y2>>z2>>x>>y>>z;
	a=sqrt(sqr(x-x2)+sqr(y-y2)+sqr(z-z2));
	b=sqrt(sqr(x-x1)+sqr(y-y1)+sqr(z-z1));
	c=sqrt(sqr(x1-x2)+sqr(y1-y2)+sqr(z1-z2));
	cosA=(sqr(b)+sqr(c)-sqr(a))/(2*b*c);
	cosB=(sqr(a)+sqr(c)-sqr(b))/(2*a*c);
	ans=min(a,b);
	if (cosA>=0&&cosB>=0){
		double p=(a+b+c)/2;
		double s=sqrt(p*(p-a)*(p-b)*(p-c));
		ans=min(ans,2*s/c);
	}
	printf("%.5lf",ans);
	return 0;
}
