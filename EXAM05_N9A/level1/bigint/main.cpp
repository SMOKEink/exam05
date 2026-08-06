#include <iostream>
#include "bigint.hpp"

int main() {
	const bigint a(42);
	bigint b(21), c, d(1337), e(d);

	std::cout << "a = " << a << std::endl; // a = 42
	std::cout << "b = " << b << std::endl; // b = 21
	std::cout << "c = " << c << std::endl; // c = 0 (Supposant que le constructeur par défaut initialise à 0)
	std::cout << "d = " << d << std::endl; // d = 1337
	std::cout << "e = " << e << std::endl; // e = 1337

	std::cout << "a + b = " << a + b << std::endl; // a + b = 63

	std::cout << "(c += a) = " << (c += a) << std::endl; // c = 42, donc (c += a) = 42

	std::cout << "b = " << b << std::endl; // b = 21
	std::cout << "++b = " << ++b << std::endl; // ++b = 22
	std::cout << "b++ = " << b++ << std::endl; // b++ = 22 (après cette ligne b = 23)

	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl; // (b << 10) + 42 = (23 << 10) + 42 = 230000000042

	std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl; // d <<= 4 = 13370000

	// Explicit cast of '2' to const bigint
	std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl; // d >>= 2 = 133700

	std::cout << "a = " << a << std::endl; // a = 42
	std::cout << "d = " << d << std::endl; // d = 133700

	std::cout << "(d < a) = " << (d < a) << std::endl; // (d < a) = 0
	std::cout << "(d > a) = " << (d > a) << std::endl; // (d > a) = 1
	std::cout << "(d == d) = " << (d == d) << std::endl; // (d == d) = 1
	std::cout << "(d != a) = " << (d != a) << std::endl; // (d != a) = 1
	std::cout << "(d <= a) = " << (d <= a) << std::endl; // (d <= a) = 0
	std::cout << "(d >= a) = " << (d >= a) << std::endl; // (d >= a) = 1

	return 0;
}
