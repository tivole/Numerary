#include <iostream>
#include <math.h>
using namespace std;
 
const double goldenRatio = (1 + sqrt(5)) / 2; // "Золотое" число
 
// Рассматриваемая нами функция
double function(double x) {
	return log(1 + x * x - cos(x)) - pow(M_E, sin(M_PI * x));
}
 
int main() {
	double a, b; // Концы отрезка
	double accuracy; // Точность, с которой мы находим локальный максимум
	double x1, x2; // Точки, делящие текущий отрезок в отношении золотого сечения
	cin >> a >> b >> accuracy;
	while (fabs(b - a) > accuracy) {
		   x1 = b - (b - a) / goldenRatio; 
	       x2 = a + (b - a) / goldenRatio;
	       if (function(x1) => function(x2)) // Условие для поиска
	           a = x1; 
	       else 
	           b = x2;
	} // Выполняем, пока не достигнем заданной точности
	cout << "(" << (a + b) / 2 << ", " << function((a + b) / 2) << ")"; 
	return 0;
}