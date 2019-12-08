#include <iostream>
#include <string>
#include<functional>

#include "HashTable.h"


HashTable::HashTable(){
	for (int i = 0; i < 10000; i++) {
		students[i] = NULL;//to make sure that we can check for empty place
	}
}

HashTable::~HashTable(){}

//providing student object, this function returns hash index as integer
int HashTable::generate_hash_index_for_student(Student* student) {
	hash<string> hash_formula;

	string hash_value = student->get_full_name() + " " + to_string(student->get_index());
	int hash_index = hash_formula(hash_value) % 10000;

	return hash_index;
}

//providing student full_name and index, this function returns hash index as integer
int HashTable::generate_hash_index_for_student(string student_full_name, int student_index) {
	hash<string> hash_formula;

	string hash_value = student_full_name + " " + to_string(student_index);
	int hash_index = hash_formula(hash_value) % 10000;

	return hash_index;
}

//this function adds new student to hash table
void HashTable::add_new_student(Student* student) {
	int hash_index = generate_hash_index_for_student(student);

	while (students[hash_index] != NULL) {//if current place already occupied, check for next place in line
		hash_index++;
	}

	students[hash_index] = student;
}

//this function is used to remove student from hash table based on full name and index. Full name is in format "last_name first_name"
void HashTable::remove_student_from_hash_table(string student_full_name, int student_index) {
	int hash_index = generate_hash_index_for_student(student_full_name, student_index);
	bool not_found = true;
	
	while (not_found) {

		if (students[hash_index] == NULL) {
			not_found = false;
			cout << "Wrong entry, student with that name and index is not in table!" << endl;

		} else if (students[hash_index]->get_index() == student_index) {
			not_found = false;
			students[hash_index] = NULL;
			cout << "Student successfully removed from table!" << endl;
		}
		else{
			hash_index++;
		}
	}

}

//remove all students from hash table
void HashTable::remove_all_students() {
	for (int i = 0; i < 10010; i++) {
		students[i] = NULL;
	}

	cout << "All students removed." << endl;
}

//this function adds large set of students (in array form) to hash table
void HashTable::add_student_array_to_hash_table(Student* student_array, int size) {
	for (int i = 0; i < size; i++) {
		add_new_student(&student_array[i]);
	}
}

//this funtion calculates student position in hash table and prints its position
void HashTable::get_student(string student_full_name, int student_index) {
	int hash_index = generate_hash_index_for_student(student_full_name, student_index);
	bool not_found = true;

	if (students[hash_index] == NULL) {
		not_found = false;
		cout << "Wrong entry, student with that name and index is not in table!" << endl;

	}
	else if (students[hash_index]->get_index() == student_index) {
		not_found = false;
		cout << "Student " << students[hash_index]->get_full_name() << " successfully found!" << endl;
		cout << "It's index is: " << students[hash_index]->get_index() << " in hash table is: " << hash_index << endl;
	}
	else {
		hash_index++;
	}

}

//test function that prints whole hash table
void HashTable::test_print_whole_table() {
	for (int i = 0; i < 1010; i++) {
		if (students[i] != NULL) {
			cout << students[i]->get_full_name() << " at index: " << i << endl;
		}
		else {
			//cout << "empty at index: " << i << endl;
		}
	}
}

