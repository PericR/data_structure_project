// data_structure_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <functional>

#include "Student.h"
#include "SortingStudentArray.h"
#include "Graph.h"
#include "Testing.h"
#include "Menu.h"
#include "HashTable.h"

using namespace std;


int main()
{
											//used for creating random students and simulating random graph
	time_t t;								//
	srand((unsigned)time(&t));				// 

	print_starting_menu();

	int size;
	cin >> size;
	
	Student* student_array;					//creating data sample of students
	student_array = new Student[size];		//

	bool** graph;							//creating 2d matrix for graph values
	graph = new bool*[size];				//	
	for (int i = 0; i < size; i++) {		//
		graph[i] = new bool[size];			//
	}

	menu(student_array, size, graph);//this is main menu that controls project
	all_tests(student_array, graph, size);//this is for testing all functions in project-comment it out when not testing
	return 0;
}
