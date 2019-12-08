#pragma once

#include "Student.h"
#include "Graph.h"
#include "HashTable.h"
#include "Menu.h"
#include "SortingStudentArray.h"

using namespace std;

//test function for creating student and printing student data
void test_student_creation() {
	cout << "Testing student creation" << endl;
	Student s = Student("Mike", "Flames", 23);
	cout << "Student " << s.get_full_name()<< " created with index " << s.get_index() << endl;

	Student st = Student::create_test_student();
	cout << "Student test" << st.get_full_name() << " created with index " << st.get_index() << endl;
	Student::calculate_gpa();
	cout << "Student Testing completed\n\n" << endl;
}

//test function for creating student array and printing everything in it
void test_student_array_creation(Student* student_array, int size) {
	cout << "Testing student array creation" << endl;
	Student::create_test_students(student_array, size);
	Student::print_all_students(student_array, size);
	cout << "Testing student creation completed\n\n" << endl;
}


//this function test evrything that is connected to hash table
void test_hash_table(Student* student_array, int size) {
	cout << "Testing hash table" << endl;
	
	HashTable table = HashTable();
	table.add_student_array_to_hash_table(student_array, size);
	table.test_print_whole_table();
	table.get_student(student_array[0].get_full_name(), student_array[0].get_index());
	table.remove_student_from_hash_table(student_array[0].get_full_name(), student_array[0].get_index());
	table.remove_all_students();
	table.test_print_whole_table();

	cout << "Testing hash table completed\n\n" << endl;
}


//Test function for graph and its functionality
void test_graph_creation(Student* student_array ,bool** graph, int size) {

	cout << "Testing graph start" << endl;

	create_undirected_graph_matrix(graph, size);

	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			cout << graph[row][col] << " ";
		}
		cout << endl;
	}

	cout << "Testing dfs start" << endl;
	dfs_search_connections(graph, student_array, 2, size, 0);
	cout << "Testing dfs end\n\n" << endl;

	cout << "Testing bfs start" << endl;
	bfs_print_connections(graph, student_array, 2, size);
	cout << "Testing bfs end\n\n" << endl;

	cout << "Testing graph end\n\n" << endl;
}

//test function for sorting algorithm
void test_sorting_algorithm(Student* student_array, int size) {
	cout << "Testing sorting algorithm start" << endl;

	Student::print_all_students(student_array, size);
	sort_students_by_last_name(student_array, size);
	sort_students_by_last_name_counter_alphabeticaly(student_array, size);
	cout << "\nSorted: \n\n" << endl;
	Student::print_all_students(student_array, size);

	cout << "Testing sorting algorithm end\n\n" << endl;
}

//test all menu functions
void test_menu(bool** graph, Student* student_array, int size) {
	cout << "Testing menu started" << endl;
	
	print_starting_menu();
	print_selection_menu();
	print_menu_for_graph(graph, student_array, size);
	print_menu_for_sorting(student_array, size);
	print_menu_index_student();
	print_menu_ask_for_student_name();
	print_menu_ask_student_index();
	print_menu_hash_table(student_array, size);

	cout << "Testing menu completed\n\n" << endl;
}

void all_tests(Student* student_array, bool** graph, int size) {
	cout << "All tests started" << endl;
	
	test_student_creation();
	test_student_array_creation(student_array, size);
	test_hash_table(student_array, size);
	test_graph_creation(student_array, graph, size);
	test_sorting_algorithm(student_array, size);
	test_menu(graph, student_array, size);

	cout << "All tests completed\n\n" << endl;
}