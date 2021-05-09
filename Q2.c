#include<stdio.h>
int main()
{
	int vowels=0, i;
	char str [250];
	printf("Enter a sentence:");
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
	
	if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
	vowels++;
}
printf("\nNumber of vowels is %d",vowels);
}
