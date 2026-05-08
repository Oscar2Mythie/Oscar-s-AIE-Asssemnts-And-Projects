#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace MathLibrary
{
	struct Float_Vector3_Struct
	{
		float Vector3_x = 0; // place holders for the 3 Vector valuse for a Vector3
		float Vector3_y = 0;
		float Vector3_z = 0;

		Float_Vector3_Struct() // Sets the values to the desired values from it's creation  
		{
			Vector3_x = 0;
			Vector3_y = 0;
			Vector3_z = 0;
		}

		Float_Vector3_Struct(float V3x, float V3y, float V3z) // Sets the values to the desired values from it's creation  
		{
			Vector3_x = V3x;
			Vector3_y = V3y;
			Vector3_z = V3z;
		}

		Float_Vector3_Struct(const Float_Vector3_Struct& Other_Vector3) // copy constuckor
		{
			Vector3_x = Other_Vector3.Vector3_x;
			Vector3_y = Other_Vector3.Vector3_y;
			Vector3_z = Other_Vector3.Vector3_z;
		}

		// *** \/\/\/ Over loading Vector3's \/\/\/ ***

		Float_Vector3_Struct operator+(const Float_Vector3_Struct& adding_Target)  //adding self cloned Vector data to Target Vector
		{
			Float_Vector3_Struct temporary = *this; // Create a clone vectors from self

			temporary.Vector3_x += adding_Target.Vector3_x; // adding clone Vecotor.x to Target vector.x
			temporary.Vector3_y += adding_Target.Vector3_y; // adding clone Vecotor.x to Target vector.y
			temporary.Vector3_z += adding_Target.Vector3_z; // adding clone Vecotor.x to Target vector.z

			return temporary; // return the three added vector values.    
		}


		Float_Vector3_Struct operator+=(const Float_Vector3_Struct& adding_Target)  //adding self cloned Vector data to Target Vector
		{
			 // Create a clone vectors from self

			Vector3_x += adding_Target.Vector3_x; // adding clone Vecotor.x to Target vector.x
			Vector3_y += adding_Target.Vector3_y; // adding clone Vecotor.x to Target vector.y
			Vector3_z += adding_Target.Vector3_z; // adding clone Vecotor.x to Target vector.z


			return *this; // return the three added vector values.    
		}

		Float_Vector3_Struct operator+(const float Target_float) //adding  self cloned Vector data to Target float
		{
			Float_Vector3_Struct temporary = *this; // adding a clone vectors from self

			temporary.Vector3_x += Target_float; // adding clone Vecotor.x to float
			temporary.Vector3_y += Target_float; // adding clone Vecotor.y to float
			temporary.Vector3_z += Target_float; // adding clone Vecotor.z to float


			return temporary; // return the three divided vector values.    
		}

		//Float_Vector3_Struct operator+=(const float Target_float)  //adding  self cloned Vector data to Target float
		//{
		//	Float_Vector3_Struct temporary = *this; // adding a clone vectors from self

		//	temporary.Vector3_x += Target_float; // adding clone Vecotor.x to float
		//	temporary.Vector3_y += Target_float; // adding clone Vecotor.y to float
		//	temporary.Vector3_z += Target_float; // adding clone Vecotor.z to float


		//	return temporary; // return the three divided vector values.    
		//}

		//Float_Vector3_Struct operator+=(const float Target_float) const //adding  self cloned Vector data to Target float
		//{
		//	Float_Vector3_Struct temporary = *this; // adding a clone vectors from self

		//	temporary.Vector3_x += Target_float; // adding clone Vecotor.x to float
		//	temporary.Vector3_y += Target_float; // adding clone Vecotor.y to float
		//	temporary.Vector3_z += Target_float; // adding clone Vecotor.z to float


		//	return temporary; // return the three divided vector values.    
		//}

		Float_Vector3_Struct operator-(const Float_Vector3_Struct& subtracking_Target) const //subtracking self cloned Vector data to Target Vector
		{
			Float_Vector3_Struct temporary = *this; // Create a clone vectors from self

			temporary.Vector3_x = (temporary.Vector3_x - subtracking_Target.Vector3_x); // subtracking clone Vecotor.x to Target vector.x
			temporary.Vector3_y = (temporary.Vector3_y - subtracking_Target.Vector3_y); // subtracking clone Vecotor.x to Target vector.y
			temporary.Vector3_z = (temporary.Vector3_z - subtracking_Target.Vector3_z); // subtracking clone Vecotor.x to Target vector.z


			return temporary; // return the three subtracked vector values.    
		}

		Float_Vector3_Struct operator-=(const Float_Vector3_Struct& subtracking_Target)  //subtracking self cloned Vector data to Target Vector
		{

			Vector3_x -= subtracking_Target.Vector3_x; // subtracking clone Vecotor.x to Target vector.x
			Vector3_y -= subtracking_Target.Vector3_y; // subtracking clone Vecotor.x to Target vector.y
			Vector3_z -= subtracking_Target.Vector3_z; // subtracking clone Vecotor.x to Target vector.z
  
			return *this;
		}

		Float_Vector3_Struct operator-(const float Target_float) const  //subtracking  self cloned Vector data to Target float
		{
			Float_Vector3_Struct temporary = *this; // subtracking a clone vectors from self

			temporary.Vector3_x -= Target_float; // subtracking clone Vecotor.x to float
			temporary.Vector3_y -= Target_float; // subtracking clone Vecotor.y to float
			temporary.Vector3_z -= Target_float; // subtracking clone Vecotor.z to float


			return temporary; // return the three divided vector values.    
		}

		Float_Vector3_Struct operator-=(const float Target_float)  //subtracking  self cloned Vector data to Target float
		{
			Float_Vector3_Struct temporary = *this; // subtracking a clone vectors from self

			temporary.Vector3_x -= Target_float; // subtracking clone Vecotor.x to float
			temporary.Vector3_y -= Target_float; // subtracking clone Vecotor.y to float
			temporary.Vector3_z -= Target_float; // subtracking clone Vecotor.z to float


			return temporary; // return the three divided vector values.    
		}

		Float_Vector3_Struct operator*(const Float_Vector3_Struct& multiplying_Target)  //multiplying  self cloned Vector data to Target Vector
		{
			Float_Vector3_Struct temporary{ this->Vector3_x,this->Vector3_y, this->Vector3_z }; // Create a clone vectors from self

			temporary.Vector3_x = (temporary.Vector3_x * multiplying_Target.Vector3_x); // multiplying clone Vecotor.x to Target vector.x
			temporary.Vector3_y = (temporary.Vector3_y * multiplying_Target.Vector3_y); // multiplying clone Vecotor.y to Target vector.y
			temporary.Vector3_z = (temporary.Vector3_z * multiplying_Target.Vector3_z); // multiplying clone Vecotor.z to Target vector.z


			return temporary; // return the three multiplied vector values.    
		}
		Float_Vector3_Struct operator*(const float Target_float) const  //multiplying  self cloned Vector data to Target float
		{
			Float_Vector3_Struct temporary = *this; // Create a clone vectors from self

			temporary.Vector3_x *= Target_float; // multiplying clone Vecotor.x to float
			temporary.Vector3_y *= Target_float; // multiplying clone Vecotor.y to float
			temporary.Vector3_z *= Target_float; // multiplying clone Vecotor.z to float


			return temporary; // return the three divided vector values.    
		}
		Float_Vector3_Struct operator*=(const Float_Vector3_Struct& multiplying_Target)  //multiplying  self cloned Vector data to Target Vector
		{

			Vector3_x *= multiplying_Target.Vector3_x; // multiplying clone Vecotor.x to Target vector.x
			Vector3_y *= multiplying_Target.Vector3_y; // multiplying clone Vecotor.y to Target vector.y
			Vector3_z *= multiplying_Target.Vector3_z; // multiplying clone Vecotor.z to Target vector.z


			return *this; // return the three multiplied vector values.    
		}
		Float_Vector3_Struct operator*=(const float Target_float)  //multiplying  self cloned Vector data to Target float
		{ 

			Vector3_x *= Target_float; // multiplying clone Vecotor.x to float
			Vector3_y *= Target_float; // multiplying clone Vecotor.y to float
			Vector3_z *= Target_float; // multiplying clone Vecotor.z to float


			return *this; // return the three divided vector values.    
		}

		Float_Vector3_Struct operator/(const Float_Vector3_Struct& dividing_Target)  //dividing  self cloned Vector data to Target Vector
		{
			Float_Vector3_Struct temporary{ this->Vector3_x,this->Vector3_y, this->Vector3_z }; // Create a clone vectors from self

			temporary.Vector3_x = (temporary.Vector3_x / dividing_Target.Vector3_x); // dividing clone Vecotor.x to Target vector.x
			temporary.Vector3_y = (temporary.Vector3_y / dividing_Target.Vector3_y); // dividing clone Vecotor.x to Target vector.y
			temporary.Vector3_z = (temporary.Vector3_z / dividing_Target.Vector3_z); // dividing clone Vecotor.x to Target vector.z


			return temporary; // return the three divided vector values.    
		}

		Float_Vector3_Struct operator/=(const Float_Vector3_Struct& dividing_Target)  //dividing  self cloned Vector data to Target Vector
		{
			Float_Vector3_Struct temporary{ this->Vector3_x,this->Vector3_y, this->Vector3_z }; // Create a clone vectors from self

			temporary.Vector3_x = (temporary.Vector3_x / dividing_Target.Vector3_x); // dividing clone Vecotor.x to Target vector.x
			temporary.Vector3_y = (temporary.Vector3_y / dividing_Target.Vector3_y); // dividing clone Vecotor.x to Target vector.y
			temporary.Vector3_z = (temporary.Vector3_z / dividing_Target.Vector3_z); // dividing clone Vecotor.x to Target vector.z


			return temporary; // return the three divided vector values.    
		}

		Float_Vector3_Struct operator/(const float Target_float) const //dividing  self cloned Vector data to Target float
		{
			Float_Vector3_Struct temporary = *this; // Create a clone vectors from self

			temporary.Vector3_x /= Target_float; // dividing clone Vecotor.x to float
			temporary.Vector3_y /= Target_float; // dividing clone Vecotor.y to float
			temporary.Vector3_z /= Target_float; // dividing clone Vecotor.z to float


			return temporary; // return the three divided vector values.    
		}

		Float_Vector3_Struct operator/=(const float Target_float)  //dividing  self cloned Vector data to Target float
		{
			Vector3_x /= Target_float; // dividing clone Vecotor.x to float
			Vector3_y /= Target_float; // dividing clone Vecotor.y to float
			Vector3_z /= Target_float; // dividing clone Vecotor.z to float   

			return *this;
		}

		float& operator[](const int Return_Vector_value)  //returning an element as if it was an array
		{

			float Returning_data = -1;

			if (Return_Vector_value == 0)
			{
				return Vector3_x;

			}
			else if (Return_Vector_value == 1)
			{
				return Vector3_y;
			}
			else if (Return_Vector_value == 2)
			{
				return Vector3_z;
			}
			else
			{
				return Returning_data;
			}

		}
		float operator[](const int Return_Vector_value) const  //returning an const element as if it was an array
		{

			float Returning_data = -1;

			if (Return_Vector_value == 0)
			{
				return Vector3_x;

			}
			else if (Return_Vector_value == 1)
			{
				return Vector3_y;
			}
			else if (Return_Vector_value == 2)
			{
				return Vector3_z;
			}
			else
			{
				return Returning_data;
			}

		}


		bool operator==(const Float_Vector3_Struct& Testing_Vector3) const //Testing  Vector data see if it matches Testing_Vector3 
		{
			float threshold = 0.000001;

			Float_Vector3_Struct temporary = *this; // Create a clone vectors from self
			return  
				(
					(fabsf(temporary.Vector3_x - Testing_Vector3.Vector3_x)) < threshold
				)
				&& 
				(
					(fabsf(temporary.Vector3_y - Testing_Vector3.Vector3_y)) < threshold
				)
				&& 
				(
					(fabsf(temporary.Vector3_z - Testing_Vector3.Vector3_z)) < threshold
				); // return either true or false   
		}
		bool operator!=(const Float_Vector3_Struct& Testing_Vector3)  //Testing  Vector data see if it matches Testing_Vector3 
		{
			Float_Vector3_Struct temporary = *this; // Create a clone vectors from self
			bool result = true; // defaults to No it dose not match

			if ((temporary.Vector3_x == Testing_Vector3.Vector3_x) && (temporary.Vector3_y == Testing_Vector3.Vector3_y) && (temporary.Vector3_z == Testing_Vector3.Vector3_z))
			{
				result = false; // sets to false when vectors match
			}

			return  result; // return either true or false   
		}
		bool operator<(Float_Vector3_Struct& Testing_Vector3)  //Testing  Vector data see if it matches Testing_Vector3 
		{
			Float_Vector3_Struct temporary_squraed = *this * (*this); // Create a squared clone vectors from self
			Float_Vector3_Struct Testing_squraed_Vector3 = (Testing_Vector3 * Testing_Vector3); // Create squeared a vector from the vector we are testing against

			float this_Squared_Magatune = temporary_squraed.Vector3_x + temporary_squraed.Vector3_y + temporary_squraed.Vector3_z; // Get the Squared magatune from the squeard vector clone
			float Testing_Squared_Magatune2 = Testing_squraed_Vector3.Vector3_x + Testing_squraed_Vector3.Vector3_y + Testing_squraed_Vector3.Vector3_z; // Get the Squared magatune from the Squared testing vector

			return (this_Squared_Magatune < Testing_Squared_Magatune2); // if this_Squared_Magatune is less then Testing_Squared_Magatune2, then return true
		}

		Float_Vector3_Struct operator=(const Float_Vector3_Struct& Rhs_Vector)  //  Assigning New vector values from another vector
		{
			Vector3_x = Rhs_Vector.Vector3_x;
			Vector3_y = Rhs_Vector.Vector3_y;
			Vector3_z = Rhs_Vector.Vector3_z;

			return *this; // return the three new vector values.    
		}

		Float_Vector3_Struct operator-()  //  making the Vectors swhich from postive to negtive
		{
			Float_Vector3_Struct Vector3_negtive = *this;
			
			Vector3_negtive.Vector3_x *= -1;
			Vector3_negtive.Vector3_y *= -1;
			Vector3_negtive.Vector3_z *= -1;

			return Vector3_negtive; // return the three updated vector values.    
		}

		// *** /\/\/\ Over loading Vector3's /\/\/\ ***

		// *** \/\/\/ Member functions for Vector3's \/\/\/ ***

		float V3_Dot_prod(const Float_Vector3_Struct& Rhs_V3)  // creating an Dot product from two vector 3's
		{
			Float_Vector3_Struct tempary_Float_Vector3 = *this; // Grab vector values from this vector

			float Dot_Prod_result = 0; // A value to hold the sum of all the values

			for (int Y_loop = 0; Y_loop < 3; Y_loop++) // looping 3 times to get the three values within the vector3 
			{
				Dot_Prod_result += tempary_Float_Vector3[Y_loop] * Rhs_V3[Y_loop]; // incease the value by the product of the element of each vector3 values.
			}

			return Dot_Prod_result; // return the sum of the product beteween the values from the Vector3's
		}

		Float_Vector3_Struct V3_Cross_prod(const Float_Vector3_Struct Rhs_V3) const // creating an croos product from an vector 3
		{
			return Float_Vector3_Struct // return the sunbtracked values from the products from thevector3's
			(
				(Vector3_y * Rhs_V3.Vector3_z) - (Vector3_z * Rhs_V3.Vector3_y),
				(Vector3_z * Rhs_V3.Vector3_x) - (Vector3_x * Rhs_V3.Vector3_z),
				(Vector3_x * Rhs_V3.Vector3_y) - (Vector3_y * Rhs_V3.Vector3_x)
			);
		}

		float V3_Magnitude() const // Get the Magnitude from an vector 3
		{
			return sqrtf((Vector3_x * Vector3_x) + (Vector3_y * Vector3_y) + (Vector3_z * Vector3_z));
		}

		void Normalise() // normalises the vector 3 in place
		{
			*this = Normalised(); 
		}

		Float_Vector3_Struct Normalised()  // sends the Normalise vector [This feels like this dose not work ... due to Normalise not returning data from being a void function]
		{
			float Norm = V3_Magnitude(); // Get the Magnitude

			if (Norm > 0.0f)
			{
				return *this /= Norm;
			}
			else
			{
				return {0,0,0};
			}
		}

		bool IsApproximatelyEqual(const Float_Vector3_Struct& Rhs_Vector3, float equal_within_value = 1e-4) const // an function that acts like an equals if it got within the range of target value
		{
			Float_Vector3_Struct tempary_Float_Vector3_Diffrence = *this; // grabs this Vector values


			for (int Loop = 0; Loop < 3; Loop++) // check each value of the vector3's by subtracking each vector value. Should it result with a value greater or less then equal_within_value, return false
			{
				if ((fabsf(tempary_Float_Vector3_Diffrence[Loop]) - fabsf(Rhs_Vector3[Loop])) < equal_within_value) // inside of the target range?
				{
				}
				else
				{
					return false;
				}
			}
			return true;
		}

		float AngleBetween(Float_Vector3_Struct Rhs_vector3) // finds the angle between this vector another vector 3
		{
			return acos(Normalised().V3_Dot_prod(Rhs_vector3.Normalised()));
		}

		float Distance(Float_Vector3_Struct Rhs_vector3) // gets the distance between two vector 3's, using the V3_Magnitude() function
		{
			Float_Vector3_Struct tempary_Float_Vector3 = *this;

			tempary_Float_Vector3 = tempary_Float_Vector3 - Rhs_vector3;

			return (tempary_Float_Vector3.V3_Magnitude());
		}

		float Angle2D()
		{
			float tempary_dot = (Vector3_x * 1) + (Vector3_y * 0);
			float tempary_Magnitude_X = sqrtf((Vector3_x * Vector3_x) + (Vector3_y * Vector3_y));
			float tempary_Magnitude_Y = sqrtf((1 * 1) + (0 * 0));

			return acos(tempary_dot / (tempary_Magnitude_X * tempary_Magnitude_Y));
		}

		// *** /\/\/\ Member functions for Vector3's /\/\/\ ***

		void display() // display the three Vector vlaues
		{
			cout << "-- Vector 3 values --" << endl;

			cout << Float_Vector3_Struct::Vector3_x << endl;
			cout << Float_Vector3_Struct::Vector3_y << endl;
			cout << Float_Vector3_Struct::Vector3_z << endl;
			cout << endl;
		}

		~Float_Vector3_Struct()  // deconstrucker 
		{

		}
	};
}