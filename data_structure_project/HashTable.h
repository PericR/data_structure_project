#pragma once
#include <functional>
#include <string>
#include "Student.h"

using namespace std;

class HashTable{
	Student* students[10010];//it holds 10 places more in case of more that one hash index with value of 9999

public:
	HashTable();
	~HashTable();

	
	void add_new_student(Student* student);

	void remove_student_from_hash_table(string student_full_name, int student_index);

	void remove_all_students();

	void add_student_array_to_hash_table(Student* student_array, int size);

	void get_student(string student_full_name, int student_index);

	void test_print_whole_table();

private:
	int generate_hash_index_for_student(Student* student);

	int generate_hash_index_for_student(string student_full_name, int student_index);

};
