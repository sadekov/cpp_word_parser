#include <iostream>
#include <string>

#include "word_parser.hpp"

using namespace std;

int main() {
	WordParser parser;

	parser.setString("The quick     brown  fox jumps    \
					  over lazy dog ");
	parser.printWordList();
	cout << "------------------------" << endl;

	cout << "Enter String" << endl;
	string buf;
	getline(cin, buf);
	int res = 0;
	res = parser.setString(buf);
	parser.printWordList();
	cout << "------------------------" << endl;

	return 0;
}
