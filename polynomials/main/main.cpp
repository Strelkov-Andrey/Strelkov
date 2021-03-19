#include "polynomials.h"

int main() {
  
	monomial m1(10,2,0,3);
	monomial m2(10, 2, 4, 6);
	monomial res;
	//res = m1 + m2;
	//res = m1 - m2;
	res = m1 * m2;
	/*polinomial p1,p2;
	p1.addmonom(m1);
	//p.addmonom(m2);
	p2.addmonom(m2);
	p1 = p1 + p2;*/
	return 0;
}