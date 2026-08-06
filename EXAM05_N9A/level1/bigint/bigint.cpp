#include "bigint.hpp"

// ---------- ADDITION ----------
bigint &bigint::operator+=(const bigint &other)
{
	std::string result;
	int i = n.size() - 1;
	int j = other.n.size() - 1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry)
	{
		int x = (i >= 0) ? n[i--] - '0' : 0;
		int y = (j >= 0) ? other.n[j--] - '0' : 0;
		int sum = x + y + carry;
		carry = sum / 10;
		result.push_back((sum % 10) + '0');
	}
	std::reverse(result.begin(), result.end());
	n = result;
	return (*this);
}
bigint bigint::operator+(const bigint &other) const
{
	bigint copy(*this);
	copy += other;
	return (copy);
}

// ---------- INCREMENT ----------
bigint &bigint::operator++()          // prefix
{
	*this += bigint(1);
	return (*this);
}
bigint bigint::operator++(int)        // postfix
{
	bigint old(*this);
	*this += bigint(1);
	return (old);
}

// ---------- DIGIT SHIFT ----------
bigint &bigint::operator<<=(const bigint &other)
{
    unsigned long amount = std::stoul(other.n);
    if (n != "0")
        n.append(amount, '0');
    return (*this);
}
bigint bigint::operator<<(const bigint &other) const
{
    bigint copy(*this);
    copy <<= other;
    return (copy);
}
bigint &bigint::operator>>=(const bigint &other)
{
	unsigned long amount = std::stoul(other.n);
	if (amount >= n.size())
		n = "0";
	else
		n.erase(n.size() - amount);
	return (*this);
}
bigint bigint::operator>>(const bigint &other) const
{
	bigint copy(*this);
	copy >>= other;
	return (copy);
}

// ---------- COMPARISON ----------
bool bigint::operator<(const bigint &other) const
{
	if (n.size() != other.n.size())
		return (n.size() < other.n.size());
	return (n < other.n);
}
bool bigint::operator>(const bigint &other)const
{
	return (other < *this);
}
bool bigint::operator<=(const bigint &other) const
{
	return !(*this > other);
}
bool bigint::operator>=(const bigint &other) const
{
	return !(*this < other);
}
bool bigint::operator==(const bigint &other) const
{
	return (n == other.n);
}
bool bigint::operator!=(const bigint &other) const
{
	return !(*this == other);
}
