#pragma once
#ifndef TESTCASE_HPP_
#define TESTCASE_HPP_

#include <sstream>
#include <iostream>
using namespace std;


class TestCase {

private:
	int total, passed, failed;
	string nameOfTest;
	ostream errorPrinter;



public:

	TestCase(string name, ostream& cerr);
	void print();

	template <typename T> TestCase& check_equal(T object1, T object2) {

		total++;

		if (object1 == object2) {
			passed++;
		}
		else {
			errorPrinter << nameOfTest << ": Failure in test #" << total << ": " << object1 << " should equal " << object2 << "!" << endl;
			failed++;
		}

		return *this;
	}

	template <typename T> TestCase& check_different(T object1, T object2) {

		total++;

		if (object1 != object2) {
			passed++;
		}
		else {
			errorPrinter << nameOfTest << ": Failure in test #" << total << ": " << object1 << " should not equal " << object2 << "!" << endl;
			failed++;
		}

		return *this;
	}

	template<typename Fun, typename T> TestCase& check_function(Fun func, const T object1, const int object2) {

		total++;
		int res = (*func)(object1);

		if (res == object2) {
			passed++;
		}
		else {
			errorPrinter << nameOfTest << ": Failure in test #" << total << ": Function should return " << object2 << " but returned " << res << "!" << endl;
			failed++;
		}

		return *this;
	}


	template <typename T> TestCase& check_output(T object1, string str) {

		total++;
		ostringstream ss;
		ss << object1;

		if (ss.str() == str) {
			passed++;
		}
		else {
			errorPrinter << nameOfTest << ": Failure in test #" << total << ": string value should be " << str << " but is " << ss.str() << "!" << endl;
			failed++;
		}

		return *this;
	}
};
#endif
