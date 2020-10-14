#include <iostream>
#include "general_list.hpp"

int main() {
	List<int> IntList;
	IntList.add_front(5);
	IntList.add_back(9);
	IntList.add_front(2);
	IntList.print();

	List<float> FloatList;
	FloatList.add_back(42);
	FloatList.add_front(36);
	FloatList.print();

	List<std::string> StringList;
	StringList.add_back("and thanks");
	StringList.add_front("So long");
	StringList.add_back("to all the fish");
	StringList.print();

	//std::list<int>

	return 0;
}
