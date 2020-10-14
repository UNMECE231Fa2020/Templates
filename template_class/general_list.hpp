#include <iostream>

template <typename X>
class List {
	private:
		struct _list {
			X value;
			struct _list *next;
		};
		typedef struct _list Slist;

		size_t _size;
		Slist *_front;
		Slist *_back;

		void reccopy(Slist *node) {
			if (node != nullptr) {
				reccopy(node->next);
				add_front(node->value);
			}
		}
	public:
		List() : _size{0}, _front{nullptr}, _back{nullptr} { }
		List(const List &l) : _size{0}, _front{nullptr}, _back{nullptr} {
			reccopy(l._front);
		}
		~List() {
			while (!empty()) {
				rm_front();
			}
		}

		size_t size() const {
			return _size;
		}

		/*
		int i = x[0];
		x[0] = 9;
		*/

		X &front() {
			return _front->value;
		}

		X &back() {
			return _back->value;
		}

		void add_front(X data) {
			Slist *newNode = new Slist;
			newNode->value = data;
			if (_front == nullptr) {
				newNode->next = nullptr;
				_back = newNode;
			}
			else {
				newNode->next = _front;
			}
			_front = newNode;
			_size += 1;
		}

		void add_back(X data) {
			Slist *newNode = new Slist;
			newNode->value = data;
			if (_back != nullptr) {
				_back->next = newNode;
			}
			if (_front == nullptr) {
				_front = newNode;
			}

			_back = newNode;
			_size += 1;
		}

		void rm_front() {
			Slist *node_to_delete = _front;
			_front = _front->next;

			if (_front != nullptr) {
				if (_front->next == nullptr) {
					_back = nullptr;
				}
			}

			delete node_to_delete;
			_size -= 1;
		}

		void rm_back() {
			Slist *node_to_delete = _front;
			if (_front->next != nullptr) {
				Slist *new_back = _front;
				while (new_back->next != _back) {
					new_back = new_back->next;
				}
				new_back->next = nullptr;
				_back = new_back;
			}
			else {
				_front = nullptr;
				_back = nullptr;
			}

			delete node_to_delete;
			_size -= 1;
		}

		bool empty() const {
			return ((_front == nullptr) && (_back == nullptr));
		}

		void print() {
			Slist *temp;
			for (temp = _front; temp != nullptr; temp = temp->next) {
				std::cout << temp->value << ' ';
			}
			std::cout << '\n';
		}
};
