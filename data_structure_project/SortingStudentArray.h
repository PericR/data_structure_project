#pragma once
#include <iostream>
#include "Student.h"

using namespace std;

//this algorithm sort students by last name using selection sort, commented out code is used for testing algorithm
void sort_students_by_last_name(Student* unsorted_array, int size) {
	for (int i = 0; i < size - 1; i++) {
		int current_smallest_index = i;
		
		for (int j = i + 1; j < size; j++) {

			//cout << "Comparing " << unsorted_array[current_smallest_index].get_full_name() << " and " << unsorted_array[j].get_full_name() << endl;

			int comparation_result = unsorted_array[current_smallest_index].get_full_name().compare(unsorted_array[j].get_full_name());

			//cout << "Comparison results: " << comparation_result << endl;

			if (comparation_result == 1) {
				current_smallest_index = j;
			}
		}

		Student smallest = unsorted_array[current_smallest_index];
		unsorted_array[current_smallest_index] = unsorted_array[i];
		unsorted_array[i] = smallest;

		/*for (int i = 0; i < size; i++) {
			cout << unsorted_array[i].get_full_name();
		}*/
	}

	cout << "Student sorting complete\n\n";
}

//this algotithm sorts students counteralphabeticaly
void sort_students_by_last_name_counter_alphabeticaly(Student* unsorted_array, int size) {
	for (int i = 0; i < size - 1; i++) {
		int current_smallest_index = i;

		for (int j = i + 1; j < size; j++) {

			//cout << "Comparing " << unsorted_array[current_smallest_index].get_full_name() << " and " << unsorted_array[j].get_full_name() << endl;

			int comparation_result = unsorted_array[current_smallest_index].get_full_name().compare(unsorted_array[j].get_full_name());

			//cout << "Comparison results: " << comparation_result << endl;

			if (comparation_result == -1) {
				current_smallest_index = j;
			}
		}

		Student smallest = unsorted_array[current_smallest_index];
		unsorted_array[current_smallest_index] = unsorted_array[i];
		unsorted_array[i] = smallest;

		/*for (int i = 0; i < size; i++) {
			cout << unsorted_array[i].get_full_name();
		}*/
	}

	cout << "Student sorting complete\n\n";
}
