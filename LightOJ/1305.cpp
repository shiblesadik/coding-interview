#include <bits/stdc++.h>
using namespace std;

int t;
long long int ax, ay, bx, by, cx, cy, dx, dy, area, abx, aby, bcx, bcy;

int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld %lld %lld %lld %lld", &ax, &ay, &bx, &by, &cx, &cy);
		abx = bx - ax;
		aby = by - ay;
		bcx = cx - bx;
		bcy = cy - by;
		dy = bcy + ay;
		dx = bcx + ax;
		area = abs(bx - ax) * abs(dx - ax);
		printf("%lld %lld %lld\n", dx, dy, area);
	}
	return 0;
}