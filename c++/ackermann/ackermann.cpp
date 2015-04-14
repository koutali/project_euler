#include <iostream>

using namespace std;

typedef unsigned long long ullong;

ullong AckermannRecursive(ullong m, ullong n)
{
	if(m == 0)
	{
		return n + 1;
	}
	else
	{
		if(n ==0)
		{
			return AckermannRecursive(m-1, 1);
		}
		else
		{
			ullong tempN = AckermannRecursive(m, n-1);
			return AckermannRecursive(m-1, tempN);
		}
	}
}

double ai(double m,double n)
{
	int stack[100000];
	stack[0] = m;
	stack[1] = n;

	int t = 1;

	do
	{
		double c = n + 1;
		if (stack[t - 1] == 0)
		{
			m = 0;
			t = t - 1;
			stack[t] = stack[t + 1] + 1;
		}
		else if (stack[t] == 0)
		{
			n = 0;
			stack[t] = 1;
			stack[t - 1] = stack[t - 1] - 1;
		}
		else
		{
			stack[t + 1] = stack[t] - 1;
			stack[t] = stack[t - 1];
			stack[t - 1] = stack[t - 1] - 1;
			t = t + 1;
		}
	}
	while(t != 0);
	return stack[0];
}

int main()
{
	cout << ai(6,6) << endl;
	return 0;
}