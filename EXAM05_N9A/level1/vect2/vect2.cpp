#include "vect2.hpp"

vect2::vect2(int x, int y) : x(x), y(y)
{
}

vect2::vect2(const vect2 &other)
{
	x = other.x;
	y = other.y;
}

vect2 &vect2::operator=(const vect2 &other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return (*this);
}

int &vect2::operator[](int index)
{
	if (index == 0)
		return (x);
	return (y);
}
int vect2::operator[](int index) const
{
	if (index == 0)
		return (x);
	return (y);
}

vect2 vect2::operator+(const vect2 &other) const
{
	return (vect2(x + other.x, y + other.y));
}
vect2 vect2::operator-(const vect2 &other) const
{
	return (vect2(x - other.x, y - other.y));
}
vect2 vect2::operator-() const
{
	return (vect2(-x, -y));
}

vect2 vect2::operator*(int scale) const
{
	return (vect2(x * scale, y * scale));
}
vect2 operator*(int scale, const vect2 &other)
{
	return (vect2(scale * other.x, scale * other.y));
}

vect2 &vect2::operator+=(const vect2 &other)
{
	*this = *this + other;
	return (*this);
}
vect2 &vect2::operator-=(const vect2 &other)
{
	*this = *this - other;
	return (*this);
}
vect2 &vect2::operator*=(int scale)
{
	*this = *this * scale;
	return (*this);
}

vect2 &vect2::operator++()
{
	++x;
	++y;
	return (*this);
}
vect2 vect2::operator++(int)
{
	vect2 copy(*this);
	++(*this);
	return (copy);
}
vect2 &vect2::operator--()
{
	--x;
	--y;
	return (*this);
}
vect2 vect2::operator--(int)
{
	vect2 copy(*this);
	--(*this);
	return (copy);
}

bool vect2::operator==(const vect2 &other) const
{
	return (x == other.x && y == other.y);
}
bool vect2::operator!=(const vect2 &other) const
{
	return !(*this == other);
}
 