#include <list>
#include <iostream>
#include <ctime>

using namespace std;

//list<char> inS = { 'w','b','t','n','a','a','q','d','e','f','r','l','u','y','z','q','a' };
list<char> inS;

list<char>::iterator it, it2, it3, it_next, it_start;

unsigned i, s, c;

bool adjacent = true;

void print_out() {

	cout << "print list: ";

	for (auto &ita : inS) cout << ita;									// symbol & can be removed without any loss
	cout << ", size of = " << inS.size() << endl;
}

unsigned check_out(list<char>::iterator it_check_out) {					// checking closest symbols, just a flag

	if (*it_check_out == *(next(it_check_out, 1))-1) return 1;

}

unsigned check_len(list<char>::iterator it_check_len) {					// measuring of a row

	c = 0;

	it = it_check_len;													// flag turning here
	it2 = it;
	it_next = next(it2, 1);

	adjacent = true;

	while (adjacent) {

		if (*it2 == *(it_next)-1) {
			++c;
			//cout << "\nit=" << *it << " it2=" << *it2 << " it_next=" << *it_next << endl;

			//cout << "NEXT\n";

			it2 = next(it2, 1);
			if (it_next != inS.end()) {
				it_next = next(it_next, 1);
			}

		}
		else {

			//cout << "\nit=" << *it << " it2=" << *it2 << " it_next=" << *it_next << endl;
			//cout << "out\n";

			adjacent = false;

			//cout << "return " << c << endl;

			return c;
		}

		if (it_next == inS.end()) return c;

	}

}

unsigned check(list<char>::iterator it_check, unsigned (*func)(list<char>::iterator)) {

	return func(it_check);
}

int main() {

	srand(time(0));

	for (i = 0; i < ((rand() % 10) + 40); ++i) inS.push_back(rand() % 26 + 0x61);
	
	//for (i = 0; i < 26; ++i) inS.push_back(0x61 + i);						// whole alphabet
	
	s = inS.size();

	print_out();

	it_start = inS.begin();							// start here

	for (i = 0; i < s; ++i) {						// cycle of it_start
		
		if (check(it_start,check_out)){				// check if letters are neighbors
			
			while (!check(it_start, check_len));			// counting a row
			inS.erase(it, next(it, c + 1));					// erase a row

			print_out();

			s = inS.size();									// resize
			//s -= c;										// heap somewhy
			it_start = inS.begin();

			i = 0;
		}
		else it_start = next(it_start, 1);
		//cout << "." << i;

	}


}