#include <iostream>

int main()
{
	int minima = 0;
	int arr[] = {2,7,1,0,-3, 40};
	for (int i = 0; i < 4; ++i)
	{
		if (arr[i] < arr[i + 1])
		{
			minima = arr[i];
		}
		else
		{
			minima = arr[i +1];
		}
	}

	return EXIT_SUCCESS;
}