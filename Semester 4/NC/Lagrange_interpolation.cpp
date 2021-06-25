#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){                  //main
	int n;                 
	float x[10], y[20], L[10], value;
	float  h,p=0;
	cout<< setprecision(6)<< fixed;
	
	cout<<"Enter the number of data points:\t";
	cin>>n;
	cout<<"Enter the values of x and y:\n";                          //input 
	for(int i=0 ;i<n ;i++){
			cout<<"x("<<i<<") = ";
			cin>>x[i];
			cout<<"y("<<i<<") = ";
			cin>>y[i];
		
	}
	
	cout<<"\nEnter the value of x at which you want to interpolate: ";
	cin>>value;

	for (int i=0; i<n; i++) 
    { 
        L[i] = 1;
            for(int j = 0; j<n;j++)
            {

                if(j!=i)
                {
                    L[i] *= (value-x[j])/(x[i]-x[j]);
                }
            }
        }
    
	for(int i = 0;i<n;i++)
    {
        p += y[i]*L[i];
    }
    cout << "\n\nLAGRANGE INTERPOLATION" << endl;
    cout<<" ======================"<<endl;
    cout <<endl<<"The Value of P"<< n-1 << "(" <<value<< "):   "<< p ;
	    
        cout << endl << endl;

     


}

















