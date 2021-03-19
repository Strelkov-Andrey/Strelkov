#include "polynomials.h"

monomial::monomial()
{
	coeff = 0;
	degree = -1;
}

monomial::monomial(int _coeff, int indx, int indy, int indz)
{
	if ((indx > MaxDegree) || (indy > MaxDegree) || (indz > MaxDegree))
		throw logic_error ("Degree is too large");
	if ((indx < 0) || (indy < 0) || (indz < 0))
		throw logic_error("Degree is negative ");
	coeff = _coeff;
	degree = indx * 100 + indy * 10 + indz;

}

monomial::monomial(int _coeff,int _degree)
{
	coeff = _coeff;
	degree = _degree;
}

monomial& monomial::operator=(const monomial& m)
{
	if (this == &m)
		return *this;
	coeff = m.coeff;
	degree = m.degree;
	return *this;
}

bool monomial::operator==(const monomial& m) const
{
	if ((degree != m.degree) || (coeff != m.coeff))
		return false;
	else
		return true;
}

bool monomial::operator!=(const monomial& m) const
{
	if ((degree == m.degree) || (coeff == m.coeff))
		return false;
	else
		return true;
}

const monomial operator -(const monomial& m)
{
	monomial m1(-m.coeff, m.degree);
	return m1;
}
monomial operator +(const monomial& m1, const monomial& m2)
{
	if (m1.degree != m2.degree)
		throw logic_error("Degrees are different");
	else
	{
		monomial res;
		res.coeff = m1.coeff + m2.coeff;
		res.degree = m1.degree;
		return res;
	}


}

monomial operator -(const monomial& m1, const monomial& m2)
{
	if (m1.degree != m2.degree)
		throw logic_error("Degrees are different");
	else
	{
		monomial res;
		res.coeff = m1.coeff - m2.coeff;
		res.degree = m1.degree;
		return res;
	}

}

monomial operator *(const monomial& m1, const monomial& m2)
{
	monomial res;
	res.degree = 0;
	res.coeff = m1.coeff * m2.coeff;
	int m1degree = m1.degree, m2degree = m2.degree;
	int k = 1;
	int resd;
	int err = MaxDegree;
	for (int i = 0; i < var; i++)
	{
		resd = k * (m1degree % 10 + m2degree % 10);
		if (resd > err*k)
			throw logic_error("Degree is too large");
		res.degree += resd;
		k *= 10;
		m1degree /= 10;
		m2degree /= 10;
	}

	return res;
}

void polinomial::addmonom(const monomial& m)
{
	Pol.add(m);
}

polinomial polinomial::operator +(const polinomial& p)
{
	polinomial res;
	polinomial t = p;
	listIterator<monomial> tmp;
	it = t.Pol.begin();
	tmp = Pol.begin();
	while (it.nextMonom())
	{
		monomial m1 = it.getValue();
		while (tmp.nextMonom())
		{
			monomial m2 = tmp.getValue();
			if (m1.getDegree() == m2.getDegree())
			{
				res.addmonom(m1 + m2);
			}
			else
			{
				res.addmonom(m1);
				res.addmonom(m2);
			}
			++tmp;
		}
		++it;
	}
	return res;
}

polinomial polinomial::operator -(const polinomial& p)
{
	polinomial res;
	polinomial t = p;
	listIterator<monomial> tmp;
	it = t.Pol.begin();
	tmp = Pol.begin();
	while (it.nextMonom())
	{
		monomial m1 = it.getValue();
		while (tmp.nextMonom())
		{
			monomial m2 = tmp.getValue();
			if (m1.getDegree() == m2.getDegree())
			{
				res.addmonom(m2 - m1);
			}
			else
			{
				res.addmonom(-m1);
				res.addmonom(m2);
			}
			++tmp;
		}
		++it;
	}
	return res;
}

polinomial polinomial::operator *(const polinomial& p)
{
	polinomial res;
	polinomial t = p;
	listIterator<monomial> tmp;
	it = t.Pol.begin();

	while (it.nextMonom())
	{
		tmp = Pol.begin();
		monomial m1 = it.getValue();
		while (tmp.nextMonom())
		{
			monomial m2 = tmp.getValue();
			res.addmonom(m1 * m2);
			++tmp;
		}
		++it;
	}
	return res;
}