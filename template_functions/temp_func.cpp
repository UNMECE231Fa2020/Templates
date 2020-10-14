#include <iostream>
#include <string>
#include <vector>

template <typename Q>
void print_vector(const std::vector<Q> &v) {
	for (const auto &x : v) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

template <typename T>
void swap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

int main() {
	int a = 1, b = 2;
	std::cout << a << ' ' << b << '\n';
	swap(a, b);
	std::cout << a << ' ' << b << "\n\n";

	float n = 1.4, m = 8.2;
	std::cout << n << ' ' << m << '\n';
	swap(n, m);
	std::cout << n << ' ' << m << "\n\n";

	std::string s = " up?", r = "What's";
	std::cout << s << r << '\n';
	swap(s, r);
	std::cout << s << ' ' << r << "\n\n";

	std::vector<double> q = {3.14529, 42.3669, 11.02896};
	std::vector<char> c = {'s', 'u', 'p', ' ', 'd', 'u', 'd', 'e'};
	print_vector(q);
	print_vector(c);

	return 0;
}
