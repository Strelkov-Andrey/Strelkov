#include "convertor.h"

int main() {
  
	roman r("C");
	arabic t;
	Convertor c;
	t = c.toArabic(r);
	cout << t << endl;
  return 0;
}