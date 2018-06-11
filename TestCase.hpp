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
	TestCase& print();

	//every method of testing returns a the object itself , allowing the user to test a several cases in one statement

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

	template<typename Fun, typename Arg, typename Res> TestCase& check_function(Fun func, const Arg object1, const Res object2) {

		total++;
		Res res = (*func)(object1);

		if (res == object2) {
			passed++;
		}
		else {
			errorPrinter << nameOfTest << ": Failure in test #" << total << ": Function should return " << object2 << " but returned " << res << "!" << endl;
			failed++;
		}

		return *this;
	}


	template <typename T> TestCase& check_output(T object1, string expectedStr) {

		total++;
		ostringstream ss;
		ss << object1;

		if (ss.str() == expectedStr) {
			passed++;
		}
		else {
			errorPrinter << nameOfTest << ": Failure in test #" << total << ": string value should be " << expectedStr << " but is " << ss.str() << "!" << endl;
			failed++;
		}

		return *this;
	}
};
#endif
