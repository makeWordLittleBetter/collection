#include <stdio.h>

void quickSort(int *a, int start, int end)
{
	int keyValue, left, right;
    
	if(start >= end)  return;
    
    left = start;
    right = end;
	keyValue	= a[right];

	while(left < right)
	{
		while((a[left] <= keyValue) && (left < right))
		{
			++left;
		}
		a[right] = a[left];

		while((a[right] >= keyValue) && (left < right))
		{
			--right;
		}
		a[left] = a[right];
	}

	//left == right
    a[left] = keyValue;
    
	quickSort(a, start, left-1);
	quickSort(a, left+1, end);
}

int compare(int *src1, int *src2, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		if(src1[i] != src2[i])	return -1;
	}

	return 1;
}

void sort_print(int result, char *name)
{
	if(1 == result)	printf("%s pass!\n", name);
	else 		    printf("%s failed!\n", name);
}


void test()
{
	int test1[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int test2[10] = {0, 1, 3, 2, 9, 7, 4, 8, 6, 5 };
	int test12_ref[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int test3[5]  	= {0, 4, 3, 1, 2 };
	int test3_ref[5] = {0, 1, 2, 3, 4};

	int test4[1]  = {0};
	int test4_ref[1] = {0};

	int test5[5]  = {5, 5, 5, 4, 4};
	int test5_ref[5] = {4, 4, 5, 5, 5};

	int result;

	quickSort(test1, 0, 9);
	result = compare(test1, test12_ref, 10);
	sort_print(result, "test1");

	quickSort(test2, 0, 9);
	result = compare(test2, test12_ref, 10);
	sort_print(result, "test2");

	quickSort(test3, 0, 4);
	result = compare(test3, test3_ref, 5);
	sort_print(result, "test3");

	quickSort(test4, 0, 0);
	result = compare(test4, test4_ref, 1);
	sort_print(result, "test4");

	quickSort(test5, 0, 4);
	result = compare(test5, test5_ref, 5);
	sort_print(result, "test5");
}



