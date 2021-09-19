#include <list>
#include <iostream>

using namespace std;

list<char> inS = { 'w','b','t','n','a','a','q','d','e','f','r','l','u','y','z','q','a' };

list<char>::iterator it, it2, it3, it_next, it_start;

unsigned i, s, c;

bool adjacent = true;

void print_out() {

	cout << "print list: ";

	for (auto &ita : inS) cout << ita;
	cout << ", size of = " << inS.size() << endl;
}

unsigned check_out(list<char>::iterator it_check_out) {

	if (*it_check_out == *(next(it_check_out, 1))-1) return 1;

}

unsigned check_len(list<char>::iterator it_check_len) {

	c = 0;

	it = it_check_len;

	it2 = it;
	it_next = next(it2, 1);

	adjacent = true;

	while (adjacent) {

		if (*it2 == *(it_next)-1) {
			++c;
			cout << "\nit=" << *it << " it2=" << *it2 << " it_next=" << *it_next << endl;

			cout << "NEXT\n";

			it2 = next(it2, 1);
			it_next = next(it_next, 1);

			adjacent = true;

		}
		else {

			cout << "\nit=" << *it << " it2=" << *it2 << " it_next=" << *it_next << endl;
			cout << "out\n";

			adjacent = false;

			cout << "return " << c << endl;

			return c;
		}
	}

}

unsigned check(list<char>::iterator it_check, unsigned (*foo)()) {

	return 0;

}

int main() {

	s = inS.size();

	print_out();

	it_start = inS.begin();

	for (i = 0; i < s; ++i) {						// cycle of it_start
		
		if (check_out(it_start)) {
			while (!check_len(it_start));					// checking row
			inS.erase(it, next(it, c + 1));

			print_out();

			s = inS.size();
			it_start = inS.begin();
			i = 0;
		}
		else it_start = next(it_start, 1);
		cout << "." << i;

	}


}