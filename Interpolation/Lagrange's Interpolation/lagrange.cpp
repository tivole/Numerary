// (c) Tivole

#include <iostream>
#include <cmath>

using namespace std;

struct Data 
{ 
    int x, y; 
}; 
  

double interpolate(Data f[], int xi, int n) 
{ 
    double result = 0; // Initialize result 
  
    for (int i=0; i<n; i++) 
    { 
        // Compute individual terms of above formula 
        double term = f[i].y; 
        for (int j=0;j<n;j++) 
        { 
            if (j!=i) 
                term = term*(xi - f[j].x)/double(f[i].x - f[j].x); 
        } 
  
        // Add current term to result 
        result += term; 
    } 
  
    return result; 
} 
  
// driver function to check the program 
int main() 
{ 
    // creating an array of 4 known data points 
    Data f[] = {{0,2}, {1,3}, {2,12}, {5,147}}; 
  
    // Using the interpolate function to obtain a data point 
    // corresponding to x=3 
    cout << "Value of f(3) is : " << interpolate(f, 3, 5); 
  
    return 0; 
} 