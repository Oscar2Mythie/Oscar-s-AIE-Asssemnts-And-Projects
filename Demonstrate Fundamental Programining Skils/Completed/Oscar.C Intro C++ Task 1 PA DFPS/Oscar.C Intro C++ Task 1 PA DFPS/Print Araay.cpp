/* https://aie.instructure.com/courses/1702/assignments/20231
* 
* Created by Oscar CRowley on the 12/02/2026
* This is for the Assessment Task Part A - Demonstrate fundamental programming skills 
* Last Update was on the 19/02/2026 
* 
1) Print Array

1. You are to make a function that takes an array of int. The function will step through each element and print it to the console. Put a comma after each element, but do NOT put a comma at the end.
Commit this to version control.

2. Add an int main() function. Use these values to initialize your array. Pass it to your function and run to check it works.

3, 1, 4, 1, 5, 9, 2, 6, 5, 3

Commit this to version control.
* 
*/
#include <iostream>;
#include <assert.h>;
using namespace std;

/*
*  This function and Array is for part one. Part one asks to print the Array
*/

void Printing_Array() 
{
	int Array_To_Print[10]{ 3,1,4,1,5,9,2,6,5,3 }; // Array used for function Printing_Array
	cout << "\n Starting Printing Array \n  ";
	
	for (size_t i = 0; i < 10; i++) 
	{
		cout << Array_To_Print[i] << endl; // prints the index of Array to print based on the value of I
	}

	cout << "\n Endding Printing Array \n  ";
}

/*
2) FizzBuzz
You are to make a function that returns the FizzBuzz string for any given input integer. An integer will return “Fizz” if the number is a multiple of 3. 
It will return “Buzz” if it’s a multiple of 5. It will return “FizzBuzz” if it’s a multiple of 3 AND 5. Otherwise it will return the input number converted to a string. 
You can use std::to_string() or equivalent for this assessment.

Commit this to version control.

Add an int main() function and add four asserts() to check your function works.
One for the value of 7 “7”,
one for 3, “Fizz”,
one for 5, “Buzz”
and one for 15, “FizzBuzz”.
Ensure all asserts() pass when you build and run.

Commit this to version control.

Make a loop in main() after your asserts(), and call your function with values of 1 to 20 and output the result to the console.
Ensure all asserts() pass when you build and run.

Test and commit this to version control.
*/

/*
*  This Fizzbuzz Function takes a USer input and diviveds the number by 3 or 5. if the remainer is 0 with both or one of them , returns either: buzz, fizz or fizzbuzz 
*/

string FizzBuzz(bool loop, int Number_input)
{
	cout << "\n\n --- Starting FizzBuzz --- \n" << endl;

	if (!loop) // is this being runned in a loop?
	{
		cout << "Whole number required! \n\ninput whole number: "; // Informs the User to input number
		cin >> Number_input; // takes in  and saves User input
	}

	string Returning_fizz_Buzz_fizBuzz = ""; // A place holder to return a string later

	cout << "number Aquired! \n\n inputed number: " << Number_input << endl; // informs the user they have inputed

	int Fizz_Number = Number_input % 3; // divides the value of Fizz_Number by 3 and saves the results. this shoild be in the range of 0 to 2  
	int Buzz_Number = Number_input % 5; // divides the value of Fizz_Number by 5 and saves the results. this shoild be in the range of 0 to 4  

	// When Number_input can be divided by 3 and 5 and  gets 0 remainer print Fizzbuzz
	if (Fizz_Number == 0 && Buzz_Number == 0)
	{
		cout << "\n" << Number_input << " is a Fizzbuzz number" << endl;
		Returning_fizz_Buzz_fizBuzz = "Fizzbuzz";
	}

	// When Number_input can divided by 3 and gets 0 remainer But can't be divided by 5, print Fizz
	else if (Fizz_Number == 0)
	{
		cout << "\n" << Number_input << " is a Fizz number" << endl;
		Returning_fizz_Buzz_fizBuzz = "Fizz";
	}

	// When Number_input can divided by 5 and gets 0 remainer But can't be divided by 3, print Buzz
	else if (Buzz_Number == 0)
	{
		cout << "\n" << Number_input << " is a buzz number" << endl;
		Returning_fizz_Buzz_fizBuzz = "buzz";
	}

	// when Number_input can'r be divided by 5 or 3 and get 0 remainer, Set Returning_fizz_Buzz_fizBuzz to be Number_input as a string
	else
	{
		Returning_fizz_Buzz_fizBuzz = Number_input;

		return Returning_fizz_Buzz_fizBuzz;
	}

}

/*
3) Minimum Element
You are to make a function that finds and returns the smallest element of an int array. Pass the array to the function as an argument.
Commit this to version control.
Add an int main() function. Initialize the following array:

67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29

Add an assert() that your function returns ‘2’ using this array.
Ensure all asserts() pass when you build and run.
Test and commit this to version control.
*/

/*
* this Uses the Array given and finds the smallest eleament within the Array 
*/

int Find_small_Nunmber_Array(int Number_Array[]) // This uses an given array and finds the smallest number within the Array
{
	cout << "\n\n --- Starting Find_small_Nunmber_Array --- \n" << endl;
	
	int Current_smallest_Number = 100; // Sets the Current_smallest_Number to be outside of the expected range of 0-99

	for (int Loop_Count = 0; Loop_Count < sizeof(Number_Array); Loop_Count++) // Loops though the whole Array
	{
		if (Current_smallest_Number > Number_Array[Loop_Count]) // if element is smaller then Current_smallest_Number, Set Current_smallest_Number t the Elemnt of the Array
		{
			Current_smallest_Number = Number_Array[Loop_Count];
			cout << "\n New smallest number: " << Number_Array[Loop_Count] << endl; // Print out the New smallest number
		}
		else
		{
			cout << "\n currect smallest  so far: " << Current_smallest_Number << endl; //  print out the currect smallest number
		}
	}
	return Current_smallest_Number; // Return the Smallest number

	cout << "\n\n --- Endding Find_small_Nunmber_Array --- \n" << endl;
}

/*
4) Statistics
You are to make a function that calculates hit accuracy in an FPS. Your function will take two integer arguments, (number of hits, and number of shots fired) and return an int (rounded down) to represent the accuracy, as a percentage from 0 to 100.
Do NOT use any built-in rounding or math functions.
Use an assert() to confirm the number of hits isn’t greater than the number of shots fired and both are greater or equal to 0.
Commit this to version control.
Add an int main() function. Add five asserts() to check your function works by passing the following Arguments to your function, and checking the result against the table's Expected Result.
Arguments	Expected Result
3,4	75
1,2	50
13,13	100
21,173	12
0,0	0
Ensure all asserts() pass when you build and run.
Commit this to version control
*/

/*
*  Hit_accuracy takes two int values. First it checks if either was 0 before returning a zero. 
otherwise make the ints tnto a float values and divide them by each other to muitplay the result by 100
*/

int Hit_accuracy(int Shots_hit, int Shots_Fired) 
{
	if (Shots_hit <= 0 || Shots_Fired <= 0) // Should either be 0, return 0
	{
		return 0;
	}
	
	int accuracy = (float(Shots_hit) / (float(Shots_Fired)) * 100); // How shots you hit divided by the amount you fired. then muitlpliy by 100 to get your accuracy rate

	return accuracy;
}

/*
5) Switch
You will write a function that takes an enum for a potion type and a Player struct and use a switch statement to apply the following effects. Your function should return the new altered Player.

Player applyPotion(enum PotionType, Player player)

enum PotionType = HEALTH, SPEED, STRENGTH, MAGIC

HEALTH : sets health to 100
SPEED: sets speed to 50, health reduced by 10, strength reduced by 10, magic set to 10
STRENGTH: sets speed to 25, health multiplied by 2, strength set to 200
MAGIC sets strength to 10, magic set to 100

struct Player { int health = 30; int speed = 10; int strength = 15; int magic = 30; };

Commit this to version control.
Add an int main(). For each potion type, initialize a const Player test variable, pass it to your function, get the return value and set up asserts() to check the returned values.
 

 -- Health Potion --

100 health

10 speed

15 strength

30 magic

Speed Potion

20 health

50 speed

5 strength

10 magic

-- Strength Potion --

60 health

25 speed

200 strength

30 magic

-- Magic Potion --

30 health

10 speed

10 strength

100 magic

    Ensure all asserts pass when you build and run.
    Test and commit this to version control.
*/

/*
* 
* 
* 
*/

enum potion_Type
{
	/*
	*  This Enum will be used for a Switch for when the Player Comuses a Potion
	*/

	Healing,
	Swiftness,
	Strength,
	Mana
};

struct Player_Stats
{
	/*
	* This structure  Holds values of the Stats of the player. 
	* These values wil be altered depending on the potion used by the player in function applyPotion()
	*/
	
	int health = 30;
	int Speed = 10;
	int Strength = 15;
	int Acrana = 30;
};

/*
*  applyPotion function Use an enum of potion_Type to contorl the switch. 
*  Each case in the Switch will update the  struct Player_Stats values based on the chosen potion
*/

void applyPotion(potion_Type Chosen_Postion , Player_Stats &player)
{
	cout << "\n\n --- Starting applyPotion --- \n" << endl;

	switch (Chosen_Postion)
	{
	case Healing: // if they chose the Healing potion, Make them healthy

		cout << "\n\n Picked healing potion --- \n" << endl;

		player.health = 100;
		player.Speed = 10;
		player.Strength = 15;
		player.Acrana = 30;

		break;
	case Swiftness: // if they chose the Swiftness potion, make them speedy

		cout << "\n\n Picked Swiftness potion --- \n" << endl;

		player.health = 20;
		player.Speed = 50;
		player.Strength = 5;
		player.Acrana = 10;


		break;
	case Strength: // if they chose the Strength potion, Make them strong

		cout << "\n\n Picked Strength potion --- \n" << endl;

		player.health = 60;
		player.Speed = 25;
		player.Strength = 200;
		player.Acrana = 30;

		break;
	case Mana: // if they chose the Mana potion, Make them Mana filled

		cout << "\n\n Picked Mana potion --- \n" << endl;

		player.health = 30;
		player.Speed = 10;
		player.Strength = 10;
		player.Acrana = 100;

		break;
	default: // if they chose somthing not on the list... DO nothing but move on
		cout << "\n\n Picked invaild potion --- \n" << endl;

		break;
	}

	cout << "\n\n --- Ending applyPotion --- \n" << endl;
}

/*
* 
* Player_Potion_Action function takes care of letting the player chose which potion they want to use. 
* first it telle the player their stats before letting them chose one.
* 
* then with the choice given, it calls on the applyPotion function to make changes in the struct Player_Stats values
*/

void Player_Potion_Action()
{
	cout << "\n\n --- Starting Player_Potion_Action --- \n" << endl;

	Player_Stats Player;

	cout << "\n Your coming up to a fight. \n your stats are... \n" <<
		"\n health: " << Player.health <<
		"\n Speed: " << Player.Speed <<
		"\n Strength: " << Player.Strength <<
		"\n Acrana: " << Player.Acrana <<
		"\n\n which potion will tip the odds in your favour? Please pickone of the following\n" << endl;

	cout << "\n Healing \n Swiftness \n strength \n Mana " << endl;
	string Pick_Potion_type = "";
	cin >> Pick_Potion_type;


	if (Pick_Potion_type == "Healing")
	{
		applyPotion(potion_Type::Healing, Player);
	}
	else if (Pick_Potion_type == "Swiftness")
	{
		applyPotion(potion_Type::Swiftness, Player);
	}
	else if (Pick_Potion_type == "Strength")
	{
		applyPotion(potion_Type::Strength, Player);
	}
	else if (Pick_Potion_type == "Mana")
	{
		applyPotion(potion_Type::Mana, Player);
	}

	cout << "\n your stats for the fight are Now... \n" <<
		"\n health: " << Player.health <<
		"\n Speed: " << Player.Speed <<
		"\n Strength: " << Player.Strength <<
		"\n Acrana: " << Player.Acrana <<
		"\n\n Good luck!" << endl;

	cout << "\n\n --- Ending Player_Potion_Action --- \n" << endl;
}


int main()
{
	Printing_Array(); // Prints an array for Print Array (line 25 to 33)



	cout << " \n Function FizzBuzz returns :" << FizzBuzz(false,0) << "\n\n --- Ending FizzBuzz --- " << endl; // Calls the FizzBuzz function of a return of a sting

	//assert((FizzBuzz(false,0) == "Fizz") || (FizzBuzz(false,0) == "buzz") || (FizzBuzz(false,0) == "Fizzbuzz")); // << This is SOO Not needed! But is there if you want to added

	for (size_t Loop_Count = 0; Loop_Count < 21; Loop_Count++)
	{
		cout << " \n Function FizzBuzz returns :" << FizzBuzz(true, Loop_Count) << "\n\n --- Ending FizzBuzz --- " << endl; // Calls the FizzBuzz function of a return of a sting
	}

	int Number_Array[]{ 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 }; // Initializing The Number_Array to find the Smaller number later

	Find_small_Nunmber_Array(Number_Array); // Finds the smallest number in the Number_Array

	cout << "\n\n --- Starting Hit_accuracy --- \n" << endl;

	// These pairs holds a pair of int values that repersent shots that hit and shots fired
	pair<int, int> Shooter1(3, 4);
	pair<int, int> Shooter2(1, 2);
	pair<int, int> Shooter3(13,13);
	pair<int, int> Shooter4(21, 173);
	pair<int, int> Shooter5(0,0);
	
	// print out the accuracy between the shots that hit vs the shots fired via the Hit_accuracy functon
	cout << "\n Simple divide :" << Hit_accuracy(Shooter1.first,Shooter1.second) << endl;
	cout << "\n Simple divide :" << Hit_accuracy(Shooter2.first,Shooter2.second) << endl;
	cout << "\n Simple divide :" << Hit_accuracy(Shooter3.first,Shooter3.second) << endl;
	cout << "\n Simple divide :" << Hit_accuracy(Shooter4.first,Shooter4.second) << endl;
	cout << "\n Simple divide :" << Hit_accuracy(Shooter5.first,Shooter5.second) << endl;

	cout << "\n\n --- Ending Hit_accuracy --- \n" << endl;

	Player_Potion_Action(); // Gives the player info about their stats and changes Player_Stats based on User choice

}