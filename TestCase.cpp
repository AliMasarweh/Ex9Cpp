#include "TestCase.hpp"

TestCase::TestCase(const string newName, ostream& cerr) : name(newName),errorPrinter(cerr),passed(0),failed(0),total(0) {
	
}

template <typename T> void TestCase::check_equal(T object1, T object2) {
	this->total++;
	if (object1 != object2) {
		this->failed++;
		this->errorPrinter << name + ": Failure in test #" + to_string(this->total) + ": " << object1 << " should equal " << object2 << "!" << endl;
	}
	else
		this->passed++;
}

template <typename T> void TestCase::check_different(T object1, T object2) {
	this->total++;
	if (object1 == object2) {
		this->failed++;
		this->errorPrinter << name + ": Failure in test #" + to_string(this->total) + ": " << object1 << " should not equal " << object2 << "!" << endl;
	}
	else
		this->passed++;
}

template <typename T> void TestCase::check_output(T object1, string string) {
	this->total++;
	stringstream buffer;
	buffer << object1;
	if (buffer.str() != string) {
		this->failed++;
		this->errorPrinter << name + ": Failure in test #" + to_string(this->total) + ": string value should be " << string << " but is " << object1 << "!" << endl;
	}
	else
		this->passed++;
}

template <typename T,typename V> void TestCase::check_function(V(*function)(T), T object1, V object2) {
	this->total++;
	T temp = *function(object2);
	if (object1 != temp) {
		this->failed++;
		this->errorPrinter << name + ": Failure in test #" + to_string(this->total) + ": Function should return " << temp << " but returned 7!" << endl;
	}
	else
		this->passed++;
}

void TestCase::print() {
	cout << name + ": " + to_string(this->failed) + " failed, " + to_string(this->passed) + " passed, " + to_string(this->total) + " total." << endl;
}