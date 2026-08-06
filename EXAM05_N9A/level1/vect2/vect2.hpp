#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2(int x = 0, int y = 0);
		vect2(const vect2& other);
		vect2& operator=(const vect2& other);

		int& operator[](int index);
		int operator[](int index) const;

		vect2 operator+(const vect2& other) const;
		vect2 operator-(const vect2& other) const;
		vect2 operator-() const;
		vect2 operator*(int scale) const;

		friend vect2 operator*(int scale, const vect2& v);

		vect2& operator+=(const vect2 &other);
		vect2& operator-=(const vect2 &other);
		vect2& operator*=(int scale);

		vect2& operator++();
		vect2 operator++(int);

		vect2& operator--();
		vect2 operator--(int);

		bool operator==(const vect2& other) const;
		bool operator!=(const vect2& other) const;
};

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
	os << "{" << v[0] << ", " << v[1] << "}";
	return (os);
}

#endif