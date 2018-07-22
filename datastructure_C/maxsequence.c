//O(N^2)
int maxsequence(int arr[], int len)
{
	int max = arr[0];
	for (int i = 0; i < len; i++)
	{
		int sum = 0;
		for (int j = i; j < len; j++)
		{
			sum += arr[j];
			if (sum > max)
				max = sum;
		}
	}

	return max;
}

//O(NlogN)
int maxsequence(int a[], int l, int u)
{
	if (l > u) return 0;
	if (l = u) return a[n];
	int m = (l + u) / 2;

	//left
	int lmax = a[m], lsum = 0;
	for (int i = m; i >= l; i--)
	{
		lsum += a[i];
		if (lsum > lmax)
			lmax = lsum;
	}

	//right
	int rmax = a[m + 1], rsum = 0;
	for (int i = m + 1; i <= u; i++)
	{
		rsum += a[i];
		if (rsum > rmax)
			rmax = rsum;
	}

	return max3(lmax + rmax, maxsequence2(a, l, m), maxsequence2(a, m + 1, u));	
}

//max of 3 number
int max3(int i, int j, int k)
{
	if (i >= j && i >= k)
		return i;
	return max3(j, k, i);
}

//O(N)
int maxsequence(int a[], int len)
{
	int maxsum, maxhere;

	for (int i = 1; i < len; i++)
	{
		if (maxhere <= 0)
			maxhere	= a[i];
		else
			maxhere += a[i];
		if (maxhere > maxsum)
			maxsum = maxhere;
	}

	return maxsum;
}