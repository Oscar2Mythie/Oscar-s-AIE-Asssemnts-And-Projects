/* https://aie.instructure.com/courses/1702/assignments/20231
*
* Created by Oscar CRowley on the 18 / 02 / 2026
* This is for the Assessment Task Part B - Demonstrate fundamental programming skills
* Last Update was on the 19 / 02 / 2026
* 
* 
*/

#include <iostream>; // needed for cout and cin
#include <assert.h>; // needed for assert methods
using namespace std;

/*
* 
* Global values to be used though out the Scrpit
* 
*/

int Staring_Arrray[]{ 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 }; // Initialise Staring_Arrray for furtute functions to sort
size_t Arrray_Size = (sizeof(Staring_Arrray) / sizeof(Staring_Arrray[0])); // Get the size of the Staring_Arrray

/*
6) Linear Search

You will write a function that performs a linear search through an integer array by passing the target value, and the array, as function arguments. 
The function will return the index where the target is found, otherwise it will return -1.

Commit this to version control.
Add an int main() function. Initialise this array

67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29

Add four asserts to check your function works.
3 should return 2
7 should return 11
67 should return 0
88 should return -1
Ensure all asserts() pass when you build and run.
Test and commit this to version control.
Write a loop that asks the user for a value and then calls your function to search for that value in the following array:

67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29

If your function finds the value, tell the user at which index it found it, otherwise tell them the value was not in the array.
Test and commit this to version control.
*/

/*
* 
	This int linear_Search function takes in 3 paramters. 
	One for the Staring Array it's going to Search though .
	One for Value it would be trying to match.
	one for the size of the Array, To inform how many elements it has to search though. 
* 
*/

int linear_Search(int Arrray_Linear_Search[], int search_Target, size_t Arrray_Linear_Search_Size)
{
	cout << "Searching for " << search_Target << endl;
	
	for (int Loop_Count = 0; Loop_Count < Arrray_Linear_Search_Size; Loop_Count++) // Loops till the end of the Array. Starting from index 0
	{

		// Should the element of Arrray_Linear_Search[Loop_Count] match search_Target, return Loop Count value which is actting as the index number 
		if (search_Target == Arrray_Linear_Search[Loop_Count])
		{
			cout << "found " << search_Target << " at element " << Loop_Count << " of The Arrray_Linear_Search Array" << endl;
			return Loop_Count;
		}
		else if(Loop_Count == Arrray_Linear_Search_Size - 1) // if the search_Target can not match anythig in the array, Return -1
		{
			
			cout << "could not find " << search_Target <<  " within The Arrray_Linear_Search Array" << endl;
			return -1;
		}
	}
	
}

/*7) Bubble Sort

Using the tutorials you will write a function that performs an ‘in-place’ bubble sort by passing an array of integers to it. Sort in ascending order (smallest to largest). You do not need to return any values from the function.
You may NOT use any built-in sorting algorithms.
Commit this to version control.
Add an int main(). Initialize this array and use your function to sort it.

67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29

Write code that loops through PAIRS of values in the sorted array and asserts() that the first value of the pair is always less than the second value of the pair. This will confirm your bubble sort works.
Ensure all asserts() pass when you build and run.
Test and commit this to version control.
*/

/*
* 
* This Bubble_Sort function Sorts the starting Array into Assending order. from Smallest number in index 0 to largets number in the last index 20. 
* This Function yakes two valurbales...  A int which will be the Starting Array and the size_t which will be the size of the Array.
* 
*/

void Bubble_Sort(int Arrray_Bubble_Sort[], size_t Arrray_Bubble_Sort_Size)
{
	int Bubble_Sort_Number_Hold = 0; // This is a temperary varlble to be used when Sorting the numbers around the Array. 

	cout << " \n --- Starting Bubble_Sort --- " << endl; // Informs the User that this function is starting

	pair<int, int> Buuble_short_Check(0, 0); // Used to check that the Logic is Sorting from smallest to biggets

	for (int Loop_Count = 0 ; Loop_Count < Arrray_Bubble_Sort_Size; Loop_Count++) // This is the main loop, it checks index 0 before going though the rest of the array
	{
		// this loops gets the value of a index then comparite it to the next index. Keeps going till it compares all elements. 
		for (int inner_Loop_Count = 0; inner_Loop_Count  < (Arrray_Bubble_Sort_Size - Loop_Count - 1); inner_Loop_Count++) 
		{
			// if Arrray_Bubble_Sort[inner_Loop_Count] is less then Arrray_Bubble_Sort[inner_Loop_Count+1] switch the numbers around So the they are in asending order 
			if (Arrray_Bubble_Sort[inner_Loop_Count] > Arrray_Bubble_Sort[inner_Loop_Count+1]) 
			{
			
				Bubble_Sort_Number_Hold = Arrray_Bubble_Sort[inner_Loop_Count]; // Holds the vlaue in the tempary place holder 

				Arrray_Bubble_Sort[inner_Loop_Count] = Arrray_Bubble_Sort[inner_Loop_Count + 1]; // Sets the value to be the same as the element one index higher then itself

				Arrray_Bubble_Sort[inner_Loop_Count + 1] = Bubble_Sort_Number_Hold;  // Sets the element's value to the tempary place holder

				// makes sure the numbers are in the right order. If not Stop program
				Buuble_short_Check.first = Arrray_Bubble_Sort[inner_Loop_Count];
				Buuble_short_Check.second = Arrray_Bubble_Sort[inner_Loop_Count + 1];
				assert(Buuble_short_Check.first <= Buuble_short_Check.second);
			}
		}
	} 

	for (int Loop_Count = 0; Loop_Count < Arrray_Bubble_Sort_Size; Loop_Count++) // Loops till the end of the Array. Starting from index 0, prints all elements it contains
	{
		
		cout << Arrray_Bubble_Sort[Loop_Count] << endl;
	}

	cout << " \n --- Ending Bubble_Sort --- " << endl;
}

/*

8) Binary Search

USE THE SAME BUBBLE SORT PROJECT (#7) FOR THIS TASK ONCE THE SORT IS WORKING
You will implement a function that searches a sorted array for a given value. Pass the target value and the array to your function and return the index where the value was found if it exists in the array. If it is not in the array return -1.
You must implement binary search for this exercise. Do NOT implement linear search. Do NOT use any built-in library functions.
Call your function from int main() after the bubble sort asserts() using the sorted array.
Add the following asserts() to your main function to check your binary search works.
(Your sorted array should look like this 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 43, 53, 61, 67, 71, 83, 89, 97)
11 = 4
23 = 8
97 = 19
88 = -1

Ensure all asserts() pass when you build and run.
Commit this to version control.
Write a loop that asks the user for a value and then calls your function to search for that value in the sorted array.
If your function finds the value, tell the user at which index it found it, otherwise tell them the value was not in the array.
Test and commit this to version control.

*/

/*
* 
* binary_Search function takes an int value. Then Starting at the middle index number rounded down, it tests if the int value is either bigger or smaller
* from that resulst, it searches linerly one half of the array going down the index values or going up the index values.
* Should the int value be the same as the mid starting point, it returns the mid starting point value
* if NUmber is not in the Array, it in forms that the int value is not in the Array
*/

int binary_Search(int Arrray_binary_Search[], int search_Target, size_t Arrray_binary_Search_Size) 
{
	int Starting_mid_point = (Arrray_binary_Search_Size / 2); // finds the mid index value

	cout << " \n --- Starting binary_Search --- " << endl; // in forms the user that it is starting the binary_Search function

	if (search_Target > Arrray_binary_Search[Starting_mid_point]) // is the search_Target more then Starting_mid_point
	{
		for (int Loop_Count = Starting_mid_point; Loop_Count < Arrray_binary_Search_Size; Loop_Count++) // searchs the array with higher index values starting from the mid starting point
		{
			if (search_Target == Arrray_binary_Search[Loop_Count]) // if search_Target matches an elemnt value, return the Loop_Count value as the index number
			{
				cout << "\nFound " << search_Target << " At index : " << Loop_Count;
				cout << " \n --- Ending binary_Search --- " << endl;
				return Loop_Count;
			}
			else if (Loop_Count == (Arrray_binary_Search_Size - 1)) // Stops the Search if it Loop Count is higher then the Array size 
			{
			cout << "could not find " << search_Target << " within The Arrray_Linear_Search Array" << endl;
			cout << " \n --- Ending binary_Search --- " << endl;
			return -1;
			}

		}
	}
	else if (search_Target < Arrray_binary_Search[Starting_mid_point])// is the search_Target more then Starting_mid_point 	
	{
		for (int Loop_Count = Starting_mid_point; Loop_Count > 0; Loop_Count--)
		{
			if (search_Target == Arrray_binary_Search[Loop_Count])
			{
				cout << "\nFound " << search_Target << " At index : " << Loop_Count;
				cout << " \n --- Ending binary_Search --- " << endl;
				return Loop_Count;
			}
			else if (Loop_Count == 1)
			{
				cout << "could not find " << search_Target << " within The Arrray_Linear_Search Array" << endl;
				cout << " \n --- Ending binary_Search --- " << endl;
				return -1;
			}
		}
	}
	else if (search_Target == Arrray_binary_Search[Starting_mid_point])
	{
		cout << "\nFound " << search_Target << " At index : " << Starting_mid_point;
		cout << " \n --- Ending binary_Search --- " << endl;
		return Starting_mid_point;
	}
}

/*
 
9) Pointers

You will write a function to swap the value of two integers. You will do this by passing pointers to those integers into the function and performing the swap through pointer manipulation. Your function will not return any values.
Do NOT use std::swap.
Commit this to version control.
Add an int main(). Initialise two integers to different values. Use your function to swap them in place. Add an assert( )to confirm the values have been swapped.
Ensure all asserts() pass when you build and run.
Test and commit this to version control.

*/


/*
* 
* the function of int_Pointers_Swap is to take two values that are pointers to a merory address which holds a int value.
* With those Address it is able to swap them around 
* 
*/

void int_Pointers_Swap(int *Pointer_Nobles_coin, int *Pointer_Treasury)
{
	cout << " \n --- Starting int_Pointers_Swap --- " << endl;

	int Holding_Nobles_coin = *Pointer_Nobles_coin;
	int Holding_Treasury = *Pointer_Treasury;

	cout << "\n The values of Treasury: " << Holding_Treasury << ": and the values of Noble Coin: " << Holding_Nobles_coin << " which is at Memory address of" << endl;
	cout << "Treasury Address: " << Pointer_Treasury << endl;
	cout << "Noble Coin: " << Pointer_Nobles_coin << endl;

	*Pointer_Treasury = Holding_Nobles_coin;
	*Pointer_Nobles_coin = Holding_Treasury;

	cout << "\n The values of Treasury: " << *Pointer_Treasury << ": and the values of Noble Coin: " << *Pointer_Nobles_coin << " which is at Memory address of" << endl;
	cout << "Treasury Address: " << Pointer_Treasury << endl;
	cout << "Noble Coin: " << Pointer_Nobles_coin << endl;

	cout << " \n --- Ending int_Pointers_Swap --- " << endl;

}

/*

10) Mob Battle

Make a struct that represents a Mob, it should have an attack skill, a damage rating, a name and health. Write a function that determines the outcome of a battle by passing two Mobs by reference.
In the battle function make each Mob perform an attack on the other by using their attack skills to determine the outcome somehow. How is up to you, but some form of simulated dice roll using randomness is suggested (think tabletop RPGs).
Based on the attack outcome, apply any damage according to the damage value and adjust the health of the target Mob.
Output a relevant string to the console using the Mob’s names e.g. “The Orc hit the Unicorn for 24 damage!”
Commit this to version control.
Add an int main(). Initialize two separate Mob variables. Give them different stats and names.
Make a loop to continuously call the battle function on the mobs until one or both have their health reduced below zero.
Track the current ‘round’ and display it on the console before displaying the result of that round.
Once the battle is over, (A or B run out of health), determine the outcome of the battle (either A won, B won, or both are dead and it’s a draw) and display the result to the console, and exit the loop and program.
Test and commit this to version control.

*/

/*
* 
* 
* 
*/

struct Eninty_Mob
{
	// this pair of health will be keeping track of the eninty's health
	pair<int,int> Health {100, 100}; // Health.first will be the Max health and Health.second will be it's Currect health

	// The value that controls how hard it is to damage this eninty 
	int Armour_class = 10; 

	// To_hit_modifer will influence how often this enity hits it's target 
	int To_hit_modifer = 0; 

	// Damage_dice
	enum Damage_dice 
	{
		die4,
		die6,
		die8,
		die10,
		die12,
		die20,
		die100
	}; 
	string Name = "";

};

int main() 
{
	// __________ 6) Linear Search __________ //

	// These asserts calls in linear_Search function and tests each element till it either finds a match or rounds out of elements of the aray

	assert(linear_Search(Staring_Arrray,3, Arrray_Size) == 2);
	assert(linear_Search(Staring_Arrray, 7, Arrray_Size) == 11);
	assert(linear_Search(Staring_Arrray, 67, Arrray_Size) == 0);
	assert(linear_Search(Staring_Arrray, 88, Arrray_Size) == -1);
	

	cout << "\n\n Array is ready! Please input a whole number to search. \n Number Input: ";
	int User_linear_search_target = 0;
	cin >> User_linear_search_target;

	linear_Search(Staring_Arrray, User_linear_search_target, Arrray_Size);

	// __________ 6) Linear Search __________ //

	// __________ 7) Bubble Sort __________ //

	Bubble_Sort(Staring_Arrray, Arrray_Size);

	// __________ 7) Bubble Sort __________ //

	// __________ 8)  Binary Search __________ //

	assert(binary_Search(Staring_Arrray, 11, Arrray_Size) == 4);
	assert(binary_Search(Staring_Arrray, 23, Arrray_Size) == 8);
	assert(binary_Search(Staring_Arrray, 97, Arrray_Size) == 19);
	assert(binary_Search(Staring_Arrray, 88, Arrray_Size) == -1);
	assert(binary_Search(Staring_Arrray, 1, Arrray_Size) == -1);

	cout << "\n\n Sorted Array is ready! Please input a whole number to search. \n Number Input: ";
	int User_binary_Search_target = 0;
	cin >> User_binary_Search_target;
	binary_Search(Staring_Arrray, User_binary_Search_target, Arrray_Size);

	// __________ 8)  Binary Search __________ //

	// __________ 9)  Pointers __________ //

	int Nobles_coin = 1550;
	int Treasury = 2550;
	
	int* Pointer_Nobles_coin = &Nobles_coin;
	int* Pointer_Treasury = &Treasury;

	int_Pointers_Swap(Pointer_Nobles_coin, Pointer_Treasury);

	// __________ 9)  Pointers __________ //

	// __________ 10) Mob Battle __________ //



	// __________ 10) Mob Battle __________ //



}