#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <algorithm>

class bigint
{
	private:
		std::string n;
	public:
		bigint(unsigned long nbr = 0) : n(std::to_string(nbr)) {}
		bigint(const bigint &other) : n(other.n) {}
		bigint& operator=(const bigint& other) { n = other.n; return *this; }
		~bigint() {}
		
		std::string getN() const { return n; }

		bigint& operator+=(const bigint &other);
		bigint  operator+(const bigint &other) const;
		bigint& operator++();
		bigint  operator++(int);

		bigint& operator<<=(const bigint &other);
		bigint  operator<<(const bigint &other) const;
		bigint& operator>>=(const bigint &other);
		bigint  operator>>(const bigint &other) const;

		bool operator<(const bigint &other) const;
		bool operator>(const bigint &other) const;
		bool operator<=(const bigint &other) const;
		bool operator>=(const bigint &other) const;
		bool operator==(const bigint &other) const;
		bool operator!=(const bigint &other) const;
};

std::ostream &operator<<(std::ostream &os, const bigint &nb)
{
	os << nb.getN();
	return (os);
}

#endif