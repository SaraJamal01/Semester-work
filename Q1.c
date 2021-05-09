#include<stdio.h>
int digit(int,int);
int main()
{
	int n,k;
	printf("Enter digit:");
	scanf("%d",&n);
	digit(n,k);
	printf("\nEnter digit to to return from right:");
	scanf("%d",&k);
	printf("\nDigit from right is %d",digit(n,k));
	
}
int digit(int n, int k)
{
	int res;
	if(k>n)
	return 0;
	else 
	res=n/pow(10,k-1);
	res=res%10;
	return res;
	
	
}

