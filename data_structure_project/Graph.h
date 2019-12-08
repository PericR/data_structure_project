#pragma once


#include "Student.h"

//this function prints graph matrix
void print_graph_matrix(bool** graph, int size) {
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			cout << graph[row][col] << " ";
		}
		cout << endl;
	}
}

//this function simulates random graph reprezenting friendship between students
void create_undirected_graph_matrix(bool** graph, int size) {
	for (int row = 0; row < size; row++) {
		for (int col = row; col < size; col++) {
			bool is_friends = rand() % 3;

			if (is_friends || row == col) {//row==col makes sure that diagonal stay filled with zeros
				graph[row][col] = 0;
				graph[col][row] = 0;
			}
			else {
				graph[row][col] = 1;
				graph[col][row] = 1;
			}
		}
	}

	print_graph_matrix(graph, size);
}

//depth first search algorithm that uses recursion for finding targets
void dfs_search_connections(bool** graph, Student* student_array, int student_index, int size, int depth) {
	depth++;

	for (int col = 0; col < size; col++) {

		if (depth == 3) {//bottom of recursion
			return;
		}

		if (graph[student_index][col] == 1) {
			dfs_search_connections(graph, student_array, col, size, depth);
			cout << student_array[col].get_full_name() << endl;
		}
	}
}

//breath first search algorithm that prints all friends of one student
void bfs_print_connections(bool** graph, Student* student_array, int student_index, int size) {
	for (int col = 0; col < size; col++) {
		if (graph[student_index][col] == 1) {
			cout << student_array[col].get_full_name() << endl;
		}
	}
}
