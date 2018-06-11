#include "TestCase.hpp"

TestCase::TestCase(string name, ostream& cerr) : errorPrinter(cerr.rdbuf()) {
	nameOfTest = name;
	total = passed = failed = 0;
}

void TestCase::print() {

	errorPrinter << nameOfTest << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl;
	errorPrinter << "---" << endl;
}
