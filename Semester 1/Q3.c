#include<stdio.h>
char sq(int);
int main()
{
	int n;
	printf("Enter side:");
	scanf("%d",&n);
	sq(n);
	return 0;
		
}
char sq (int side)
{
	int i,j;
	for(i=0;i<side;i++)
	{
		for(j=0;j<side;j++)
		printf("*");
printf("\n");
	}
	return;
}
