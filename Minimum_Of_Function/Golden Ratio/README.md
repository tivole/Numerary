# Golden Ratio Method

Golden Ratio Method


## Algorithm

```cpp
double golden_ratio_min(double a, double b, double (*f)(double)) {
    
    double x1, x2, fx1, fx2;
    
    x1 = b - (b - a) / phi; 
	x2 = a + (b - a) / phi;
    fx1 = f(x1);
    fx2 = f(x2);

    while (fabs(b - a) > eps) {
        if (fx1 >= fx2) {
            a = x1;
            x1 = x2;
            fx1 = fx2;
            x2 = a + (b - a) / phi;
            fx2 = f(x2);
        } else {
            b = x2;
            x2 = x1;
            fx2 = fx1;
            x1 = b - (b - a) / phi; 
            fx1 = f(x1);
        }
	}

    return (a + b) / 2.0;
}
```