/*
Sieve of Eratosthenes implemented using a linked list
Created by: Charles Cobourn
Created on: 5/20/19
*/

//Defining terms
#define _CRT_SECURE_NO_WARNINGS
#define _Wno_unused_result 

//Adding in libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

//Linked list node structure
struct node
{

	int data;
	struct node *next;

};

class linked_list
{

private:
	node* head, * tail, * iterator;
	int size;

public:
	linked_list()
	{

		head = NULL;
		tail = NULL;
		iterator = NULL;
		size = 0;

	}

	//Method to add nodes
	void add_node(int input)
	{

		//Creating temp node
		node* temp = new node;
		temp->data = input;
		temp->next = NULL;

		//Differentiating first and successive cases
		if (head == NULL)
		{

			//Setting both tmp to both head and tail
			head = temp;
			tail = temp;
			iterator = head;
			
			//Adding to size
			size++;

		}
		else
		{

			//Setting tmp to tail and moving tail
			tail->next = temp;
			tail = tail->next;

			//Adding to size
			size++;

		}

	}

	//Method to print list
	void print()
	{

		//Creating temp current node
		node* curr = new node;
		curr = head;

		while (curr != NULL)
		{

			//Printing and changing the node
			printf("%d ", curr->data);
			curr = curr->next;

		}

	}

	//Method to delete node
	void delete_node(int value)
	{

		//Setting two temp pointers
		node* temp = new node;
		node* curr = new node;

		//If statement for various cases
		if (value == head->data)
		{

			//Deleting head
			head = head->next;

			//Decreasing size
			size--;

		}
		else
		{

			//Setting current node
			curr = head->next;
			temp = head;

			//Iterating through list
			while (curr != NULL)
			{

				//Checking if value is correct
				if (value == curr->data)
				{

					//Connecting previous node to succeeding node
					temp->next = curr->next;

					//Setting curr equal to null to break out of the loop
					curr = NULL;

					//Decreasing size
					size--;

				}
				else
				{

					//Changing temp and curr if not the right node
					temp = temp->next;
					curr = curr->next;

				}

			}

		}

	}

	//Method to get size
	int get_size()
	{

		return size;

	}

	//Iterator method
	int iterate()
	{
	
		//Get data from current node
		int data = iterator->data;

		//Changing iterator node
		if (iterator->next != NULL)
		{

			iterator = iterator->next;
			
		}

		//Return data
		return data;
	
	}

	//Method to return iterator data
	int iterator_data()
	{
	
		return iterator->data;
	
	}

};

//Main method
void main()
{

	//While loop variable
	bool run = true;

	//Overall while loop
	while (run)
	{

		//Asking user to enter number greater than 1
		printf("Enter a number greater than 1: ");

		//Reading in answer
		int input = 0;
		(void)scanf("%d", &input);
		fflush(stdin);

		//Checking that number is greater than 1
		while (input <= 1)
		{

			//Telling user that number isn't right and asking to reenter it
			printf("That number isn't greater than 1");
			printf("\nPlease enter a number greater than 1: ");
			(void)scanf("%d", &input);
			fflush(stdin);

		}

		//Creating list
		linked_list ll;

		//Creating list
		for (int i = 2; i <= input; i++)
		{

			ll.add_node(i);

		}

		//Outer loop to iterate through list
		while (ll.iterator_data() * 2 < input)
		{

			//Deleting data
			for (int i = ll.iterator_data() * 2; i <= input; i = i + ll.iterator_data())
			{
	
				ll.delete_node(i);
		
			}

			//Iterating
			ll.iterate();
			
		}

		//Telling user the answer		
		printf("\nThere are %d prime numbers in the range from 2 to %d.\nThe numbers are: ", ll.get_size(), input);
		ll.print();

		//Asking user if they want to rerun the program
		char user = 'A';
		printf("\n\nWould you like to rerun the program? (Y/N): ");
		(void)scanf(" %c", &user);
		fflush(stdin);
		
		//Changing run based off of user input
		if (user == 'Y')
		{
			
			run = true;

		}
		else
		{
			
			run = false;

		}

	}

}