//#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
	int reverse(int x);
};

int Solution::reverse(int x) {
	int a[10] = {0};//分解x 至多10位
	int r=0;
	int j;
	int i;
	int flag = 0;
	int k = 9;//记录原数有多少位//因为32-bit int型  max:2147483647
	double MAX = pow(2,31) - 1;
	int temp = abs(x);

	if (x < 0)
	{
		MAX=MAX+1;// min:-2147483648
		flag = 1;
	}
	while (temp / pow(10, k)<1&&k>=0)
	{
		a[k] = 0;
		k--;//能知道x是几位数   10^k   k+1位   0~k
	}

	for (j = k; j >= 0; j--)
	{
		a[j+(9-k)] =int(temp / pow(10,j));
		temp = temp % int(pow(10,j));
	}
	if (a[0] < 3)
	{
		for (i = 0; i<10; i++)
		{
			if (double(r) <= MAX - a[i] * pow(10, (10 - i - 1)))//未溢出
			{
				r = r +int( a[i] * pow(10, (10 - i - 1))); 
			}
			else { r = 0; break; }
		}
		if (flag) r = 0 - r;//负数
	}
	else  r = 0;
	return r;
}

void main()
{
	int a = 0; //min:-2147483648
	int b = -2144847412;
	int c = -100000;
	int d = -1000000052;
	Solution RI;
	a = RI.reverse(a);
	b = RI.reverse(b);
	c = RI.reverse(c);
	d = RI.reverse(d);
	//cout << a << '\t' << b << '\t' << c << '\t' << d;
}

