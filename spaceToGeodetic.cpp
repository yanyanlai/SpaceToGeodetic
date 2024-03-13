#include<iostream>
#include<cmath>
using namespace std;
#define π acos(-1.0)
int main()
{
	long double B, L, H, N, B1, m, B2, B3;
	long double X, Y, Z;
	double a = 6378137;
	double b = 6356752.3141;
	long double e = sqrt(1 - pow(b, 2) / pow(a, 2));
	cout << "请输入空间坐标(X,Y,Z)" << endl;
	cout << π << endl;
	cin >> X >> Y >> Z;
	if (X >= 0 && Y >= 0)
		L = atan(Y / X) * 180 / π;
	else if (X <= 0 && Y >= 0)
		L = atan(Y / (-X)) * 180 / π + 90;
	else if (X <= 0 && Y <= 0)
		L = atan(Y / X) * 180 / π + 180;
	else if (X >= 0 && Y <= 0)
		L = atan((-Y) / X) * 180 / π + 270;
	cout << "该点经度为" << L << endl;


	B1 = atan(Z / (sqrt(pow(X, 2) + pow(Y, 2))));
	B2 = 0;
	B = 0;
	N = 0;
	cout << "请输入差值允许的范围:" << endl;
	cin >> m;
	while (B1 - B2 >= m)
	{
		B2 = B1;
		N = a / (sqrt(1 - pow(e, 2) * pow(sin(B2), 2)));
		B3 = atan((Z + N * pow(e, 2) * sin(B2)) / (sqrt(pow(X, 2) + pow(Y, 2))));
		B1 = B3;
		B = B3 * 180 / π;;
		cout << B << endl;
	}
	cout << "该点的纬度是" << B << endl;
	H = ((sqrt(pow(X, 2) + pow(Y, 2))) / cos(B)) - N;
	cout << "大地高是" << H << endl;
	cout << "该点大地坐标为" << B << L << H;
	return 0;
}