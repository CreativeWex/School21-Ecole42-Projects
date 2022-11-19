#include "Fixed.hpp"
#include "Point.hpp"

// w1 = vector proportion of the first side of triangle
// w1 = (Ax * (Cy - Ay)) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay))
//		---------------------------------------------------------------
//				(By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay)
Fixed	*get_w1( Point const a, Point const b, Point const c, Point const p)
{
	Fixed Ax = a.getX();
	Fixed Ay = a.getY();
	Fixed Bx = b.getX();
	Fixed By = b.getY();
	Fixed Cx = c.getX();
	Fixed Cy = c.getY();
	Fixed Px = p.getX();
	Fixed Py = p.getY();

	Fixed	num = (Ax * (Cy - Ay)) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay);
	Fixed	denum = (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);
	Fixed	f = num / denum;
	Fixed *w1 = new Fixed(f);

	return (w1);
}

// w2 = vector proportion of the second side of triangle
// w2 = Py - Ay - w1 * (By - Ay)
//		------------------------
//				Cy - Ay
Fixed	*get_w2( Fixed w1, Point const a, Point const b, Point const c, Point const p)
{
	Fixed Ay = a.getY();
	Fixed By = b.getY();
	Fixed Cy = c.getY();
	Fixed Py = p.getY();

	Fixed	num = Py - Ay - w1 * (By - Ay);
	Fixed	denum = Cy - Ay;
	Fixed *w2 = new Fixed(num / denum);

	return (w2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed *w1 = get_w1(a, b, c, point);
	Fixed *w2 = get_w2(*w1, a, b, c, point);
	bool	ret = true;

	if (*w1 > 0 && *w2 > 0 && (*w1 + *w2) < 1)
		ret = true;
	else
		ret = false;
	delete w1;
	delete w2;
	return (ret);
}
