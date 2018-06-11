#include "TestCase.hpp"

TestCase::TestCase(string name, ostream& c) : errorPrinter(c.rdbuf()) {
	nameOfTest = name;
	total = passed = failed = 0;
}

void TestCase::print() {

	cout << nameOfTest << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl;
	cout << "---" << endl;
}
