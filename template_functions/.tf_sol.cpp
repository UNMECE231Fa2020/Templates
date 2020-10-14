#include <iostream>
#include <string>
#include <vector>

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void swap(float &x, float &y) {
	float temp = x;
	x = y;
	y = temp;
}

void swap(double &x, double &y) {
	double temp = x;
	x = y;
	y = temp;
}

void swap(std::string &x, std::string &y) {
	std::string temp = x;
	x = y;
	y = temp;
}

template<typename T>
void swap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

template<class V>
void print_vector(const std::vector<V> &v) {
	for (const auto &x : v) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

template<typename Iter, typename Val>
Val accumulate(Iter first, Iter last, Val res) {
	for (auto p = first; p != last, p++) {
		res += *p;
	}
	return res;
}
