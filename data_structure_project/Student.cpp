#include "Student.h"
#include <iostream>

Student::Student(){}

Student::Student(string first_name, string last_name, int index)
	:first_name(first_name), last_name(last_name), index(index){}

Student::~Student(){
	//cout << "Student " << first_name + " " + last_name << " deleted" << endl;
}

string Student::get_full_name() {
	string full_name = last_name + " " + first_name;
	return full_name;
}

int Student::get_index() {
	return index;
}

//this function prints all students in student array
void Student::print_all_students(Student* student_array, int size) {
	for (int i = 0; i < size; i++) {
		cout << student_array[i].get_full_name() << " with index: " << student_array[i].get_index() << endl;
	}

	cout << "\n";
}

Student Student::create_test_student() {
	string first_names[10] = { "Alan", "Dave", "Mike", "Robert", "Stuart", "Chandler", "Monika", "Pheobe", "Nicol", "Maria" };
	string last_names[10] = { "Fleming", "Copper", "Wolowitz", "Goldensmith", "Francis", "Smith", "Johnson", "Jones", "Brown", "Davis" };
	int index = 0;
	
	int random_first_name = rand() % 10;
	int random_last_name = rand() % 10;
	int random_index = rand() % 10;

	Student st = Student(first_names[random_first_name], last_names[random_last_name], index);
	return st;
}

//this function creates random array of students for testing purposes
void Student::create_test_students(Student* student_array, int size) {
	string first_names[10] = { "Alan", "Dave", "Mike", "Robert", "Stuart", "Chandler", "Monika", "Pheobe", "Nicol", "Maria" };
	string last_names[10] = { "Fleming", "Copper", "Wolowitz", "Goldensmith", "Francis", "Smith", "Johnson", "Jones", "Brown", "Davis" };
	int index = 0;

	cout << "Creating array of test students\n" << endl;

	for (int i = 0; i < size; i++) {
		int random_first_name = rand() % 10;
		int random_last_name = rand() % 10;

		student_array[i] = Student(first_names[random_first_name], last_names[random_last_name], index);
		index++;
	}

	print_all_students(student_array, size);

	cout << "Created array of test students\n\n";
}

//this function calculates gpa
void Student::calculate_gpa() {
	double sum = 0;
	double counter = 0;
	int current_grade = 0;

	cout << "Please enter grades to calculate your GPA" << endl;
	cout << "Enter next grade or enter 0 when done: ";
	cin >> current_grade;
	sum += current_grade;
	
	while(current_grade != 0) {
		cout << "Enter next grade or enter 0 when done: ";
		cin >> current_grade;
		sum += current_grade;
		counter++;		
	}

	if (sum == 0) {
		cout << "No grade was entered!" << endl;
	}
	else if (sum > 0) {
		cout << "GPA: " << sum / counter << endl;
	}
	else {
		cout << "Something went teribly wrong" << endl;
	}
}

