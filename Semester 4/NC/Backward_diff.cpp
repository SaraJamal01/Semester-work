#include<iostream>
#include <bits/stdc++.h>
using namespace std;
float calculate(float P, int n)                   //calculate P(P-i)
{ 
	float temp = P; 
	for (int i = 1; i < n; i++) 
		temp = temp * (P + i); 
	return temp; 
} 
int factorial(int n)                                  //calculate factorial
{ 
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
} 
int main(){                  //main
	int n;                 
	float x[10], y[20][20], value;
	float  h, P;
	
	
	cout<<"Enter the number of data points:\t";
	cin>>n;
	cout<<"Enter the values of x and y:\n";                          //input 
	for(int i=0 ;i<n ;i++){
			cout<<"x("<<i<<") = ";
			cin>>x[i];
			cout<<"y("<<i<<") = ";
			cin>>y[i][0];
		
	}
	
	cout<<"\nEnter the value of x at which you want to interpolate: ";
	cin>>value;
	 //Calculations
	 h = x[1] - x[0] ;       //height
	 P = (value-x[n-1])/h; 
	cout<< setprecision(6)<< fixed;
	 for(int i=1;i<n;i++)                                  //backward difference loop
	{
		for(int j=n-1;j>i-1;j--)
			y[j][i]=y[j][i-1]-y[j-1][i-1];
}
	
	cout<<" ------------------------------------------"<<"\n";	         //print backward difference table
	cout<<" NEWTON'S BACKWARD DIFFERENCE TABLE"<<endl;
 	cout<<" ------------------------------------------"<<"\n\n";
	for(int i = 0; i < n; i++)
 	{
  		cout <<" "<<x[i];
  		for(int j = 0; j <= i ; j++)
 		{
			cout << "\t" << y[i][j];
  		}
  	cout << endl;
	}
   float sum = y[n-1][0];                                                    //finding the value of X
   for (int i = 1; i < n; i++) 
		sum = sum + (calculate(P, i)*y[n-i][i])/factorial(i); 
	  
	 cout << "\n Value for newton backward at " << value << " is "<< sum<<endl;                                                                
	
	
	
	
}
