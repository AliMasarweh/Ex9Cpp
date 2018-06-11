#include "TestCase.hpp"

TestCase::TestCase(string name, ostream& cerr) : errorPrinter(cerr) {
	nameOfTest = name;
	total = passed = failed = 0;
}

//print well known to return void but returning the object will allow a further test cases.
TestCase& TestCase::print() {

	errorPrinter << nameOfTest << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl;
	errorPrinter << "---" << endl;
	return *this;
}
