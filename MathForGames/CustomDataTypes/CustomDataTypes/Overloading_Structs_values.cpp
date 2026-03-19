#include <iostream>
#include <assert.h>
using namespace std;

struct Float_Vector3_Struct
{
	float Vector3_x = 0; // place holders for the 3 Vector valuse for a Vector3
	float Vector3_y = 0;
	float Vector3_z = 0;


	Float_Vector3_Struct(float V3x, float V3y, float V3z) // Sets the values to the desired values from it's creation  
	{
		Vector3_x = V3x;
		Vector3_y = V3y;
		Vector3_z = V3z;
	}

	Float_Vector3_Struct(const Float_Vector3_Struct &Other_Vector3) // copy constuckor
	{
		Vector3_x = Other_Vector3.Vector3_x;
		Vector3_y = Other_Vector3.Vector3_y;
		Vector3_z = Other_Vector3.Vector3_z;
	}

	Float_Vector3_Struct operator+(const Float_Vector3_Struct&adding_Target)  //adding self cloned Vector data to Target Vector
	{
		Float_Vector3_Struct temporary{this->Vector3_x,this->Vector3_y, this->Vector3_z}; // Create a clone vectors from self

		temporary.Vector3_x = (temporary.Vector3_x + adding_Target.Vector3_x); // adding clone Vecotor.x to Target vector.x
		temporary.Vector3_y = (temporary.Vector3_y + adding_Target.Vector3_y); // adding clone Vecotor.x to Target vector.y
		temporary.Vector3_z = (temporary.Vector3_z + adding_Target.Vector3_z); // adding clone Vecotor.x to Target vector.z


		return temporary; // return the three added vector values.    
	}

	Float_Vector3_Struct operator+(const float Target_float)  //adding  self cloned Vector data to Target float
	{
		Float_Vector3_Struct temporary = *this; // adding a clone vectors from self

		temporary.Vector3_x += Target_float; // adding clone Vecotor.x to float
		temporary.Vector3_y += Target_float; // adding clone Vecotor.x to float
		temporary.Vector3_z += Target_float; // adding clone Vecotor.x to float


		return temporary; // return the three divided vector values.    
	}

	Float_Vector3_Struct operator-(const Float_Vector3_Struct& subtracking_Target)  //subtracking self cloned Vector data to Target Vector
	{
		Float_Vector3_Struct temporary{ this->Vector3_x,this->Vector3_y, this->Vector3_z }; // Create a clone vectors from self

		temporary.Vector3_x = (temporary.Vector3_x - subtracking_Target.Vector3_x); // subtracking clone Vecotor.x to Target vector.x
		temporary.Vector3_y = (temporary.Vector3_y - subtracking_Target.Vector3_y); // subtracking clone Vecotor.x to Target vector.y
		temporary.Vector3_z = (temporary.Vector3_z - subtracking_Target.Vector3_z); // subtracking clone Vecotor.x to Target vector.z


		return temporary; // return the three subtracked vector values.    
	}
	Float_Vector3_Struct operator-(const float Target_float)  //subtracking  self cloned Vector data to Target float
	{
		Float_Vector3_Struct temporary = *this; // subtracking a clone vectors from self

		temporary.Vector3_x -= Target_float; // subtracking clone Vecotor.x to float
		temporary.Vector3_y -= Target_float; // subtracking clone Vecotor.x to float
		temporary.Vector3_z -= Target_float; // subtracking clone Vecotor.x to float


		return temporary; // return the three divided vector values.    
	}

	Float_Vector3_Struct operator*(const Float_Vector3_Struct& multiplying_Target)  //multiplying  self cloned Vector data to Target Vector
	{
		Float_Vector3_Struct temporary{ this->Vector3_x,this->Vector3_y, this->Vector3_z }; // Create a clone vectors from self

		temporary.Vector3_x = (temporary.Vector3_x * multiplying_Target.Vector3_x); // multiplying clone Vecotor.x to Target vector.x
		temporary.Vector3_y = (temporary.Vector3_y * multiplying_Target.Vector3_y); // multiplying clone Vecotor.x to Target vector.y
		temporary.Vector3_z = (temporary.Vector3_z * multiplying_Target.Vector3_z); // multiplying clone Vecotor.x to Target vector.z


		return temporary; // return the three multiplied vector values.    
	}

	Float_Vector3_Struct operator*(const float Target_float)  //multiplying  self cloned Vector data to Target float
	{
		Float_Vector3_Struct temporary = *this; // Create a clone vectors from self

		temporary.Vector3_x *= Target_float; // multiplying clone Vecotor.x to float
		temporary.Vector3_y *= Target_float; // multiplying clone Vecotor.x to float
		temporary.Vector3_z *= Target_float; // multiplying clone Vecotor.x to float


		return temporary; // return the three divided vector values.    
	}

	Float_Vector3_Struct operator/(const Float_Vector3_Struct& dividing_Target)  //dividing  self cloned Vector data to Target Vector
	{
		Float_Vector3_Struct temporary{ this->Vector3_x,this->Vector3_y, this->Vector3_z }; // Create a clone vectors from self

		temporary.Vector3_x = (temporary.Vector3_x / dividing_Target.Vector3_x); // dividing clone Vecotor.x to Target vector.x
		temporary.Vector3_y = (temporary.Vector3_y / dividing_Target.Vector3_y); // dividing clone Vecotor.x to Target vector.y
		temporary.Vector3_z = (temporary.Vector3_z / dividing_Target.Vector3_z); // dividing clone Vecotor.x to Target vector.z


		return temporary; // return the three divided vector values.    
	}

	Float_Vector3_Struct operator/(const float Target_float)  //dividing  self cloned Vector data to Target float
	{
		Float_Vector3_Struct temporary = *this; // Create a clone vectors from self

		temporary.Vector3_x /= Target_float; // dividing clone Vecotor.x to float
		temporary.Vector3_y /= Target_float; // dividing clone Vecotor.x to float
		temporary.Vector3_z /= Target_float; // dividing clone Vecotor.x to float


		return temporary; // return the three divided vector values.    
	}

	void display() // display the three Vector vlaues
	{
		cout << Float_Vector3_Struct::Vector3_x << endl;
		cout << Float_Vector3_Struct::Vector3_y << endl;
		cout << Float_Vector3_Struct::Vector3_z << endl;
		cout << endl;
	}

	~Float_Vector3_Struct()  // deconstrucker 
	{
		
	}
};

int main() 
{
	Float_Vector3_Struct First_Vector(2, 4, 6), Second_Vector(1,3,5);
	Float_Vector3_Struct Current_Vector = First_Vector + Second_Vector;

	Current_Vector.display();

	Current_Vector = (Current_Vector + 154);
	Current_Vector.display();

	Current_Vector = Current_Vector - First_Vector;
	Current_Vector.display();

	Current_Vector = (Current_Vector - -7.4);
	Current_Vector.display();

	Current_Vector = Current_Vector * Second_Vector;
	Current_Vector.display();

	Current_Vector = Current_Vector / First_Vector;
	Current_Vector.display();

	Current_Vector = (Current_Vector * 2.5);
	Current_Vector.display();

	Current_Vector = (Current_Vector / -3.4);
	Current_Vector.display();
}