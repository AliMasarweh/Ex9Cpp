#pragma once
#ifndef TESTCASE_HPP_
#define TESTCASE_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
using namespace std;

class TestCase {
private:
	string name;
	ostream& errorPrinter;
	int passed , failed, total;

public:
	TestCase(const string, ostream&);
	template <typename T> void check_equal(T, T);
	template <typename T> void check_different(T, T);
	template <typename T> void check_output(T, string);
	template <typename T, typename V> void TestCase::check_function(V(*function)(T), T object1, V object2);
	void print();
};
#endif