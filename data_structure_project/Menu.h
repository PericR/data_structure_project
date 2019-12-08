#pragma once
#include <iostream>
#include "HashTable.h"
#include "Graph.h"
#include "Student.h"

using namespace std;

//start of the menu
void print_starting_menu() {
	cout << "Please enter size of data set to generate sample of students: ";	
}

int print_selection_menu() {
	int choice = -1;

	do {
		cout << "\nPlease select what to do: " << endl;
		cout << "Press 0 to exit" << endl;
		cout << "Press 1 to simulate graph for sample data" << endl;
		cout << "Press 2 to sort array of students" << endl;
		cout << "Press 3 to create hash table" << endl;
		cout << "Press 4 to calculate GPA" << endl;

		cin >> choice;
	} while (choice < 0 || choice > 4);
	
	return choice;
}

void print_menu_for_graph(bool** graph, Student* student_array, int size) {
	int choice = -1;

	do {
		cout << "\nPlease select what to do: " << endl;
		cout << "Press 0 to exit" << endl;
		cout << "Press 1 to generate matrix graph" << endl;
		cout << "Press 2 to print connections of one student and connections of that student connections using dfs" << endl;
		cout << "Press 3 to print connections of one student using dfs" << endl;
		
		cin >> choice;

		if (choice == 0) {
			cout << "Thanks for playing" << endl;
		}
		else if (choice == 1) {
			create_undirected_graph_matrix(graph, size);
			cout << "Created graph.";
		}
		else if (choice == 2) {
			cout << "Select student index:";
			int student_index;
			cin >> student_index;

			dfs_search_connections(graph, student_array, student_index, size, 0);
			
			cout << "All connections printed" << endl;
		}
		else if (choice == 3) {
			cout << "Select student index:";
			int student_index;
			cin >> student_index;

			bfs_print_connections(graph, student_array, student_index, size);
			cout << "All connections printed" << endl;
		}
		else {
			cout << "Wrong input";
		}

	} while (choice != 0);
}

void print_menu_for_sorting(Student* student_array, int size) {
	int choice = -1;

	do {
		cout << "\nPress 0 to exit" << endl;
		cout << "Press 1 to sort array of students using selection sort alphabeticaly" << endl;
		cout << "Press 2 to sort array of students using selection sort counter alphabeticaly" << endl;

		cin >> choice;
		if (choice == 0) {
			cout << "Thanks for playing" << endl;
		}
		else if (choice == 1) {
			sort_students_by_last_name(student_array, size);
			Student::print_all_students(student_array, size);
		}
		else if (choice == 2) {
			sort_students_by_last_name_counter_alphabeticaly(student_array, size);
			Student::print_all_students(student_array, size);
		}
		else {
			cout << "Wrong input";
		}

	} while (choice != 0);
}

void print_menu_index_student() {
	cout << "\nPress 0 to exit" << endl;
	cout << "Please select index for student: ";
}

string print_menu_ask_for_student_name() {
	string first_name;
	string last_name;

	cout << "\nEnter first name of student: ";
	cin >> first_name;
	cout << "Enter last name of student: ";
	cin >> last_name;

	return last_name + " " + first_name;
}

int print_menu_ask_student_index() {
	int index = -1;

	cout << "enter student index: ";
	cin >> index;

	return index;
}

void print_menu_hash_table(Student* student_array, int size) {
	HashTable table = HashTable();
	int choice = -1;

	do {
		cout << "\n\nPress 0 to exit" << endl;
		cout << "Press 1 to add students to hash table" << endl;
		cout << "Press 2 to delete all students from hash table" << endl;
		cout << "Press 3 to delete entry from table" << endl;
		cout << "Press 4 to search for student in table" << endl;
		
		cin >> choice;
		if(choice == 0){
			cout << "Thanks for playing" << endl;
		}
		else if (choice == 1) {
			table.add_student_array_to_hash_table(student_array, size);			
			cout << "Student array added to hash table.";
		}
		else if (choice == 2) {
			table.remove_all_students();
			table.test_print_whole_table();
			cout << "All students removed from table";
		}
		else if (choice == 3) {
			string student_name = print_menu_ask_for_student_name();
			int student_index = print_menu_ask_student_index();

			table.remove_student_from_hash_table(student_name, student_index);
		}
		else if (choice == 4) {
			string student_name = print_menu_ask_for_student_name();
			int student_index = print_menu_ask_student_index();

			table.get_student(student_name, student_index);
		}
		else {
			cout << "Wrong input";
		}
	} while (choice != 0);
}

void menu(Student* student_array, int size, bool** graph) {
	 
	 Student::create_test_students(student_array, size);	 

	 int choice = print_selection_menu();

	 if (choice == 0) {
		 cout << "Thanks for playing!\n" << endl;
	 }
	 else if(choice == 1) {
		 print_menu_for_graph(graph, student_array, size);
	 }
	 else if (choice == 2) {
		 print_menu_for_sorting(student_array, size);
	 }
	 else if (choice == 3) {
		 print_menu_hash_table(student_array, size);
	 }
	 else if (choice == 4) {
		 Student::calculate_gpa();
	 }
	 else {
		 cout << "Something went wrong!\n" << endl;
	 }
}