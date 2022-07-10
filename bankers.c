#include <stdio.h>
#include <stdlib.h>

int main()
{
	static int alloc[10][10], max[10][10], need[10][10], flag = 0, available[20], finish[10], work[10], sequence[10], m, n, count, i, j, k, num;
	printf("Enter the total no of processes");
	scanf("%d", &n);
	printf("Enter the total no of resource types:");
	scanf("%d", &m);

	printf("Enter the allocation matrix:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("Process%d:", i + 1);
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &alloc[i][j]);
		}
	}

	printf("Enter the maximum matrix:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("Process%d:", i + 1);
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &max[i][j]);
		}
	}

	printf("Enter the available instances:");
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &available[i]);
	}

	printf("Allocation\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%d\t", alloc[i][j]);
		}
		printf("\n");
	}

	printf("Maximum matrix:\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%d\t", max[i][j]);
		}
		printf("\n");
	}

	printf("available instances:\n");
	for (int i = 0; i < m; ++i)
	{
		printf("%d\t", available[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}

	printf("\nNeed matrix\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%d\t", need[i][j]);
		}
		printf("\n");
	}

	for (int j = 0; j < m; ++j)
	{
		finish[i] = 0;
	}

	k = 0;
	while (k < n)
	{
		flag = 0;
		for (int i = 0; i < n; ++i) // traverse the entire need matrix 5x3
		{
			if (finish[i] == 0)
			{
				for (int j = 0; j < m; ++j) // traverse the single row 0-2
				{
					if (need[i][j] > work[j])
					{
						break;
					}
				}

				if (j == m)
				{
					for (int j = 0; j < n; ++j)
					{
						work[i] = work[i] + alloc[i][j];
						finish[i] = 1;
						sequence[k++] = i;
						flag = 1;
					}
				}
			}
		}

		if (flag == 0)
		{
			printf("The System is in unsafe state!!!\n");
			exit(0);
		}
	}

	printf("The system is in safe state!!!\nSafe Sequence:");
	for (int i = 0; i < n - 1; i++)
	{
		printf("p%d->", sequence[i]);
	}
	printf("p%d\n", sequence[n - 1]);

	return 0;
}