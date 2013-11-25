// Sean Szumlanski (Guest Lecturer)
// COP 3502
// August 23, 2013

// Suppose we have a sorted array of integers, and we want to know if any two of
// them add up to a particular value, which I shall call the 'target'. We'll
// write a function to do this. It will return 1 if the array contains two
// values that sum to 'target', 0 otherwise.

#include <stdio.h>

int CanHasTargetSum(int *array, int len, int target)
{
	int i, j;

	// This is a "brute force" approach
	
	for (i = 0; i < len; i++)
		for (j = i + 1; j < len; j++)
			if (array[i] + array[j] == target)
				return 1;
	
	// This is an (approximately) n^2 approach, and Arup will talk more about
	// the formal analysis involved with segments of code like this.
	
	return 0;
}

// Here's a faster solution to the same problem, based on the algorithm we
// discussed in class today.
int CanHasTargetSumFaster(int *array, int len, int target)
{
	int i = 0, j = len - 1, sum;
	
	// This does approx. n steps of work, which is way better than n^2!
	while (j > i)
	{
		sum = array[i] + array[j];
		
		// sum is too small! so, the smaller index is dragging us down
		if (sum < target)
			i++;
		// sum is too large! so, the larger index is bloating up the sum
		else if (sum > target)
			j--;
		// sum is juuuuuuuust right
		else
			return 1;
	}
	
	// If we didn't find two numbers that add up to 'target', return 0
	return 0;
}