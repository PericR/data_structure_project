#pragma once
#include <string>

using namespace std;

class Student{
	string first_name;
	string last_name;
	int index;

public:
	Student();
	Student(string first_name, string last_name, int index);
	~Student();


	string get_full_name();
	int get_index();
	static void print_all_students(Student* student_array, int size);
	static Student create_test_student();
	static void create_test_students(Student* student_array, int size);
	static void calculate_gpa();
};

