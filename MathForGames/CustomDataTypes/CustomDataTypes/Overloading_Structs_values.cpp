/*

Created by Oscar crowley 18/03/2025. Last updated on the 29/04/2026

*/


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

	// *** \/\/\/ Over loading Vector3's \/\/\/ ***

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
		temporary.Vector3_y += Target_float; // adding clone Vecotor.y to float
		temporary.Vector3_z += Target_float; // adding clone Vecotor.z to float


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

	Float_Vector3_Struct operator*=(const Float_Vector3_Struct& multiplying_Target)  //multiplying  self cloned Vector data to Target Vector
	{
		Float_Vector3_Struct temporary{ this->Vector3_x,this->Vector3_y, this->Vector3_z }; // Create a clone vectors from self

		temporary.Vector3_x *= multiplying_Target.Vector3_x; // multiplying clone Vecotor.x to Target vector.x
		temporary.Vector3_y *= multiplying_Target.Vector3_y; // multiplying clone Vecotor.y to Target vector.y
		temporary.Vector3_z *= multiplying_Target.Vector3_z; // multiplying clone Vecotor.z to Target vector.z


		return temporary; // return the three multiplied vector values.    
	}

	Float_Vector3_Struct operator*=(const float Target_float)  //multiplying  self cloned Vector data to Target float
	{
		Float_Vector3_Struct temporary = *this; // Create a clone vectors from self

		temporary.Vector3_x *= Target_float; // multiplying clone Vecotor.x to float
		temporary.Vector3_y *= Target_float; // multiplying clone Vecotor.y to float
		temporary.Vector3_z *= Target_float; // multiplying clone Vecotor.z to float


		return temporary; // return the three divided vector values.    
	}

	Float_Vector3_Struct operator*(const float Target_float)  //multiplying  self cloned Vector data to Target float
	{
		Float_Vector3_Struct temporary = *this; // Create a clone vectors from self

		temporary.Vector3_x *= Target_float; // multiplying clone Vecotor.x to float
		temporary.Vector3_y *= Target_float; // multiplying clone Vecotor.y to float
		temporary.Vector3_z *= Target_float; // multiplying clone Vecotor.z to float


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
		temporary.Vector3_y /= Target_float; // dividing clone Vecotor.y to float
		temporary.Vector3_z /= Target_float; // dividing clone Vecotor.z to float


		return temporary; // return the three divided vector values.    
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


	 bool operator==(const Float_Vector3_Struct &Testing_Vector3)  //Testing  Vector data see if it matches Testing_Vector3 
	{
		Float_Vector3_Struct temporary = *this; // Create a clone vectors from self
		bool result = false; // defaults to No it dose not match

		if ((temporary.Vector3_x == Testing_Vector3.Vector3_x) && (temporary.Vector3_y == Testing_Vector3.Vector3_y) && (temporary.Vector3_z == Testing_Vector3.Vector3_z)) 
		{
			result = true; // sets to true when vectors match
		}

		return  result; // return either true or false   
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
		 Float_Vector3_Struct Testing_squraed_Vector3 = (Testing_Vector3 * Testing_Vector3);

		 float this_Squared_Magatune = temporary_squraed.Vector3_x + temporary_squraed.Vector3_y + temporary_squraed.Vector3_z;
		 float Testing_Squared_Magatune2 = Testing_squraed_Vector3.Vector3_x + Testing_squraed_Vector3.Vector3_y + Testing_squraed_Vector3.Vector3_z;

		 return (this_Squared_Magatune < Testing_Squared_Magatune2);
	 }

	Float_Vector3_Struct operator=(const Float_Vector3_Struct &Rhs_Vector)  //  Assigning New vector values from another vector
	{
		Vector3_x = Rhs_Vector.Vector3_x;
		Vector3_y = Rhs_Vector.Vector3_y;
		Vector3_z = Rhs_Vector.Vector3_z;

		return *this; // return the three new vector values.    
	}

		Float_Vector3_Struct operator-()  //  making the Vectors swhich from postive to negtive
	{
		 Vector3_x *= -1 ;
		 Vector3_y *= -1 ;
		 Vector3_z *= -1 ;

		return *this; // return the three updated vector values.    
	}

		// *** /\/\/\ Over loading Vector3's /\/\/\ ***

		// *** \/\/\/ Member functions for Vector3's \/\/\/ ***

		float V3_Dot_prod(const Float_Vector3_Struct& Rhs_V3)  // creating an Dot product from an vector 3
		{
			Float_Vector3_Struct tempary_Float_Vector3 = *this;
			
			float Dot_Prod_result = 0;

			for (int Y_loop = 0; Y_loop < 3; Y_loop++)
			{
				Dot_Prod_result += tempary_Float_Vector3[Y_loop] * Rhs_V3[Y_loop];
			}

			return Dot_Prod_result;
		}

		Float_Vector3_Struct V3_Cross_prod(const Float_Vector3_Struct Rhs_V3) // creating an croos product from an vector 3
		{
			return Float_Vector3_Struct
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
			float Norm = V3_Magnitude(); // Get the Magnitude

			// divide the Vector3 by it's Magnitude

			cout << "Normalise x and you get: " << (Vector3_x /= Norm) << endl;
			Vector3_x /= Norm;
			cout << "Normalise y and you get: " << (Vector3_y /= Norm) << endl;
			Vector3_y /= Norm;
			cout << "Normalise z and you get: " << (Vector3_y /= Norm) << endl;
			Vector3_z /= Norm;
			cout << endl;
		}

		Float_Vector3_Struct Normalised() const // sends the Normalise vector
		{
			Float_Vector3_Struct Norm_copy = *this;
			Norm_copy.Normalise();
			Norm_copy.display();

			return Norm_copy;
		}

		bool IsApproximatelyEqual(Float_Vector3_Struct& Rhs_Vector3, float equal_within_value = 1e-4) // an function that acts like an equals if it got within the range of target value
		{
			Float_Vector3_Struct tempary_Float_Vector3_Diffrence = *this; // grabs this Vector values

			for (int Loop = 0; Loop < 3; Loop ++)
			{
				if ((tempary_Float_Vector3_Diffrence[Loop]- Rhs_Vector3[Loop]) < equal_within_value || (tempary_Float_Vector3_Diffrence[Loop] - Rhs_Vector3[Loop]) > -equal_within_value) // inside of the target range?
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
			float tempary_Magnitude_X = sqrtf((Vector3_x * Vector3_x)+(Vector3_y * Vector3_y));
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

struct Float_Vector4_Struct
{
	float Vector4_x = 0; // place holders for the 4 Vector valuse for a Vector3
	float Vector4_y = 0;
	float Vector4_z = 0;
	float Vector4_w = 0;


	Float_Vector4_Struct(float V4x, float V4y, float V4z, float V4w) // Sets the values to the desired values from it's creation  
	{
		Vector4_x = V4x;
		Vector4_y = V4y;
		Vector4_z = V4z;
		Vector4_w = V4w;
	}

	Float_Vector4_Struct(const Float_Vector4_Struct& Other_Vector4) // copy constuckor
	{
		Vector4_x = Other_Vector4.Vector4_x;
		Vector4_y = Other_Vector4.Vector4_y;
		Vector4_z = Other_Vector4.Vector4_z;
		Vector4_w = Other_Vector4.Vector4_w;
	}

	// *** \/\/\/ Over loading Vector3's \/\/\/ ***

	Float_Vector4_Struct operator+(const Float_Vector4_Struct& adding_Target)  //adding self cloned Vector data to Target Vector
	{
		Float_Vector4_Struct temporary{ this->Vector4_x,this->Vector4_y, this->Vector4_z,this->Vector4_w }; // Create a clone vectors from self

		temporary.Vector4_x = (temporary.Vector4_x + adding_Target.Vector4_x); // adding clone Vecotor.x to Target vector.x
		temporary.Vector4_y = (temporary.Vector4_y + adding_Target.Vector4_y); // adding clone Vecotor.x to Target vector.y
		temporary.Vector4_z = (temporary.Vector4_z + adding_Target.Vector4_z); // adding clone Vecotor.x to Target vector.z
		temporary.Vector4_w = (temporary.Vector4_w + adding_Target.Vector4_w); // adding clone Vecotor.x to Target vector.w

		return temporary; // return the four added vector values.    
	}

	Float_Vector4_Struct operator+(const float Target_float)  //adding  self cloned Vector data to Target float
	{
		Float_Vector4_Struct temporary = *this; // adding a clone vectors from self

		temporary.Vector4_x += Target_float; // adding clone Vecotor.x to float
		temporary.Vector4_y += Target_float; // adding clone Vecotor.y to float
		temporary.Vector4_z += Target_float; // adding clone Vecotor.z to float
		temporary.Vector4_w += Target_float; // adding clone Vecotor.w to float


		return temporary; // return the four divided vector values.    
	}

	Float_Vector4_Struct operator-(const Float_Vector4_Struct& subtracking_Target)  //subtracking self cloned Vector data to Target Vector
	{
		Float_Vector4_Struct temporary{ this->Vector4_x,this->Vector4_y, this->Vector4_z,this->Vector4_w }; // Create a clone vectors from self

		temporary.Vector4_x = (temporary.Vector4_x - subtracking_Target.Vector4_x); // subtracking clone Vecotor.x to Target vector.x
		temporary.Vector4_y = (temporary.Vector4_y - subtracking_Target.Vector4_y); // subtracking clone Vecotor.x to Target vector.y
		temporary.Vector4_z = (temporary.Vector4_z - subtracking_Target.Vector4_z); // subtracking clone Vecotor.x to Target vector.z
		temporary.Vector4_z = (temporary.Vector4_w - subtracking_Target.Vector4_w); // subtracking clone Vecotor.x to Target vector.w


		return temporary; // return the four subtracked vector values.    
	}
	Float_Vector4_Struct operator-(const float Target_float)  //subtracking  self cloned Vector data to Target float
	{
		Float_Vector4_Struct temporary = *this; // subtracking a clone vectors from self

		temporary.Vector4_x -= Target_float; // subtracking clone Vecotor.x to float
		temporary.Vector4_y -= Target_float; // subtracking clone Vecotor.y to float
		temporary.Vector4_z -= Target_float; // subtracking clone Vecotor.z to float


		return temporary; // return the four  divided vector values.    
	}

	Float_Vector4_Struct operator*(const Float_Vector4_Struct& multiplying_Target)  //multiplying  self cloned Vector data to Target Vector
	{
		Float_Vector4_Struct temporary{ this->Vector4_x,this->Vector4_y, this->Vector4_z, this->Vector4_w }; // Create a clone vectors from self

		temporary.Vector4_x = (temporary.Vector4_x * multiplying_Target.Vector4_x); // multiplying clone Vecotor.x to Target vector.x
		temporary.Vector4_y = (temporary.Vector4_y * multiplying_Target.Vector4_y); // multiplying clone Vecotor.y to Target vector.y
		temporary.Vector4_z = (temporary.Vector4_z * multiplying_Target.Vector4_z); // multiplying clone Vecotor.z to Target vector.z
		temporary.Vector4_w = (temporary.Vector4_w * multiplying_Target.Vector4_w); // multiplying clone Vecotor.w to Target vector.w

		return temporary; // return the four multiplied vector values.    
	}

	Float_Vector4_Struct operator*(const float Target_float)  //multiplying  self cloned Vector data to Target float
	{
		Float_Vector4_Struct temporary = *this; // Create a clone vectors from self

		temporary.Vector4_x *= Target_float; // multiplying clone Vecotor.x to float
		temporary.Vector4_y *= Target_float; // multiplying clone Vecotor.y to float
		temporary.Vector4_z *= Target_float; // multiplying clone Vecotor.z to float
		temporary.Vector4_w *= Target_float; // multiplying clone Vecotor.w to float


		return temporary; // return the four divided vector values.    
	}

	Float_Vector4_Struct operator/(const Float_Vector4_Struct& dividing_Target)  //dividing  self cloned Vector data to Target Vector
	{
		Float_Vector4_Struct temporary{ this->Vector4_x,this->Vector4_y, this->Vector4_z,this->Vector4_w }; // Create a clone vectors from self

		temporary.Vector4_x = (temporary.Vector4_x / dividing_Target.Vector4_x); // dividing clone Vecotor.x to Target vector.x
		temporary.Vector4_y = (temporary.Vector4_y / dividing_Target.Vector4_y); // dividing clone Vecotor.x to Target vector.y
		temporary.Vector4_z = (temporary.Vector4_z / dividing_Target.Vector4_z); // dividing clone Vecotor.x to Target vector.z
		temporary.Vector4_w = (temporary.Vector4_w / dividing_Target.Vector4_w); // dividing clone Vecotor.x to Target vector.w


		return temporary; // return the four divided vector values.    
	}

	Float_Vector4_Struct operator/(const float Target_float)  //dividing  self cloned Vector data to Target float
	{
		Float_Vector4_Struct temporary = *this; // Create a clone vectors from self

		temporary.Vector4_x /= Target_float; // dividing clone Vecotor.x to float
		temporary.Vector4_y /= Target_float; // dividing clone Vecotor.y to float
		temporary.Vector4_z /= Target_float; // dividing clone Vecotor.z to float
		temporary.Vector4_w /= Target_float; // dividing clone Vecotor.w to float


		return temporary; // return the four divided vector values.    
	}

	float& operator[](const int Return_Vector_value)  //instead of calling on the values by going this.Vector4_x, call the values as if it was an a element of array
	{

		float Returning_data = 0; // default value to return

		if (Return_Vector_value == 0) // if the requested element int value was 0, return Vector4_x
		{
			return Vector4_x;

		}
		else if (Return_Vector_value == 1) // if the requested element int value was 1, return Vector4_y
		{
			return Vector4_y;
		}
		else if (Return_Vector_value == 2) // if the requested element int value was 2, return Vector4_z
		{
			return Vector4_z;
		}
		else if (Return_Vector_value == 3) // if the requested element int value was 3, return Vector4_w
		{
			return Vector4_w;
		}
		else // // if the requested element int value was out side the range of 0 to 3 return 0
		{
			return Returning_data;
		}

	}

	float operator[](const int Return_Vector_value) const //instead of calling on the values by going this.Vector4_x, call the values as if it was an a element of array
	{

		float Returning_data = 0; // default value to return

		if (Return_Vector_value == 0) // if the requested element int value was 0, return Vector4_x
		{
			return Vector4_x;

		}
		else if (Return_Vector_value == 1) // if the requested element int value was 1, return Vector4_y
		{
			return Vector4_y;
		}
		else if (Return_Vector_value == 2) // if the requested element int value was 2, return Vector4_z
		{
			return Vector4_z;
		}
		else if (Return_Vector_value == 3) // if the requested element int value was 3, return Vector4_w
		{
			return Vector4_w;
		}
		else // // if the requested element int value was out side the range of 0 to 3 return 0
		{
			return Returning_data;
		}

	}


	bool operator==(const Float_Vector4_Struct& Testing_Vector4)  //Testing  Vector data see if it matches Testing_Vector3 
	{
		Float_Vector4_Struct temporary = *this; // Create a clone vectors from self

		return  ((temporary.Vector4_x == Testing_Vector4.Vector4_x) && (temporary.Vector4_y == Testing_Vector4.Vector4_y) && (temporary.Vector4_z == Testing_Vector4.Vector4_z) && (temporary.Vector4_w == Testing_Vector4.Vector4_w)); // return either true or false   
	}

	bool operator!=(const Float_Vector4_Struct& Testing_Vector4)  //Testing  Vector data see if it matches Testing_Vector3 
	{
		Float_Vector4_Struct temporary = *this; // Create a clone vectors from self
		bool result = true; // defaults to No it dose not match

		if ((temporary.Vector4_x == Testing_Vector4.Vector4_x) && (temporary.Vector4_y == Testing_Vector4.Vector4_y) && (temporary.Vector4_z == Testing_Vector4.Vector4_z) && (temporary.Vector4_w == Testing_Vector4.Vector4_w))
		{
			result = false; // sets to false when vectors match
		}

		return  result; // return either true or false   
	}

	bool operator<(Float_Vector4_Struct& Testing_Vector4)  //Testing  Vector data see if it matches Testing_Vector3 
	{
		Float_Vector4_Struct temporary_squraed = *this * (*this); // Create a squared clone vectors from self
		Float_Vector4_Struct Testing_squraed_Vector4 = (Testing_Vector4 * Testing_Vector4); // Create a Sqaured clone vector from testing Vector

		float this_Squared_Magatune = temporary_squraed.Vector4_x + temporary_squraed.Vector4_y + temporary_squraed.Vector4_z +temporary_squraed.Vector4_w; // add all sqaured Vectors together from self clone
		float Testing_Squared_Magatune2 = Testing_squraed_Vector4.Vector4_x + Testing_squraed_Vector4.Vector4_y + Testing_squraed_Vector4.Vector4_z + Testing_squraed_Vector4.Vector4_w; // add all sqaured vectors together from testing clone 

		return (this_Squared_Magatune < Testing_Squared_Magatune2); 
	}

	Float_Vector4_Struct operator=(const Float_Vector4_Struct& Rhs_Vector)  //  Assigning New vector values from another vector
	{
		Vector4_x = Rhs_Vector.Vector4_x;
		Vector4_y = Rhs_Vector.Vector4_y;
		Vector4_z = Rhs_Vector.Vector4_z;
		Vector4_w = Rhs_Vector.Vector4_w;

		return *this; // return the four new vector values.    
	}

	Float_Vector4_Struct operator-()  //  making the Vectors swhich from postive to negtive
	{
		Vector4_x *= -1;
		Vector4_y *= -1;
		Vector4_z *= -1;
		Vector4_w *= -1;

		return *this; // return the three updated vector values.    
	}

	// *** /\/\/\ Over loading Vector4's /\/\/\ ***

	// *** \/\/\/ Member functions for Vector4's \/\/\/ ***

	float V4_Dot_prod(const Float_Vector4_Struct& Rhs_V4)
	{
		Float_Vector4_Struct tempary_Float_Vector3 = *this;

		float Dot_Prod_result = 0;

		for (int Y_loop = 0; Y_loop < 4; Y_loop++)
		{
			Dot_Prod_result += tempary_Float_Vector3[Y_loop] * Rhs_V4[Y_loop];
		}

		return Dot_Prod_result;
	}

	Float_Vector4_Struct V4_Cross_prod(const Float_Vector4_Struct Rhs_V4)
	{
		return Float_Vector4_Struct
		(
			(Vector4_y * Rhs_V4.Vector4_z) - (Vector4_z * Rhs_V4.Vector4_y),
			(Vector4_z * Rhs_V4.Vector4_x) - (Vector4_x * Rhs_V4.Vector4_z),
			(Vector4_x * Rhs_V4.Vector4_y) - (Vector4_y * Rhs_V4.Vector4_x),
			0
		);
	}

	float V4_Magnitude() const
	{
		return sqrtf((Vector4_x * Vector4_x) + (Vector4_y * Vector4_y) + (Vector4_z * Vector4_z));
	}

	void Normalise()
	{
		float Norm = V4_Magnitude();

		cout << "Normalise x and you get: " << (Vector4_x /= Norm) << endl;
		Vector4_x /= Norm;
		cout << "Normalise y and you get: " << (Vector4_y /= Norm) << endl;
		Vector4_y /= Norm;
		cout << "Normalise z and you get: " << (Vector4_y /= Norm) << endl;
		Vector4_z /= Norm;
		cout << endl;
	}

	Float_Vector4_Struct Normalised() const
	{
		Float_Vector4_Struct Norm_copy = *this;
		Norm_copy.Normalise();
		Norm_copy.display();

		return Norm_copy;
	}

	bool IsApproximatelyEqual(Float_Vector4_Struct& Rhs_Vector4, float equal_within_value = 1e-4)
	{
		Float_Vector4_Struct tempary_Float_Vector3_Diffrence = *this;

		for (int Loop = 0; Loop < 4; Loop++)
		{
			if ((tempary_Float_Vector3_Diffrence[Loop]- Rhs_Vector4[Loop]) < equal_within_value || (tempary_Float_Vector3_Diffrence[Loop] - Rhs_Vector4[Loop]) > -equal_within_value)
			{

			}
			else
			{
				return true;
			}
		}

		return false;
	}

	float AngleBetween(Float_Vector4_Struct Rhs_vector4)
	{
		return acos(Normalised().V4_Dot_prod(Rhs_vector4.Normalised()));
	}

	float Distance(Float_Vector4_Struct Rhs_vector4)
	{
		Float_Vector4_Struct tempary_Float_Vector4 = *this;

		tempary_Float_Vector4 = tempary_Float_Vector4 - Rhs_vector4;

		return (tempary_Float_Vector4.V4_Magnitude());
	}

	// *** /\/\/\ Member functions for Vector4's /\/\/\ ***

	void display() // display the three Vector vlaues
	{
		cout << "-- Vector 4 values --" << endl;
		
		cout << Float_Vector4_Struct::Vector4_x << endl;
		cout << Float_Vector4_Struct::Vector4_y << endl;
		cout << Float_Vector4_Struct::Vector4_z << endl;
		cout << Float_Vector4_Struct::Vector4_w << endl;
		cout << endl;
	}

	~Float_Vector4_Struct()  // deconstrucker 
	{

	}
};

struct Float_Matrix3_Struct
{
	union 
	{
		struct 
		{
			float
//				local X axis		local y axis		World origin Point
				Mat3_Local_Xaxis_x_m1, Mat3_Local_Yaxis_x_m2, Mat3_Local_Trans_axis_x_m3, //  X axis  
				Mat3_Local_Xaxis_y_m4, Mat3_Local_Yaxis_y_m5, Mat3_Local_Trans_axis_y_m6, //  Y axis
//				\/ place holder and Must start as 0 \/			A point or A vector  
				Mat3_place_Holder_w_m7, Mat3_place_Holder_w_m8, Mat3_Point_Or_Vector_m9;
		};
		float Mat3_Array[9]; // Holds values of the Matrix3 in eleaments of a array 
		float Mat3_grid[3][3]; // Holds values of the Matrix3 in eleaments of a 3 by 3 grid
	};

	Float_Matrix3_Struct() // constructor
	{
		for (int loopCount = 0; loopCount < 9; loopCount++)
		{
			if (loopCount % 4 == 0)
			{
				Mat3_Array[loopCount] = 1;
			}
			else
			{
				Mat3_Array[loopCount] = 0;
			}
		}
	}


	Float_Matrix3_Struct(const Float_Matrix3_Struct& Copy_Matrix3_Struct) // copy constructor
	{
		for (int loopCount = 0; loopCount < 9; loopCount++)
		{
			Mat3_Array[loopCount] = Copy_Matrix3_Struct.Mat3_Array[loopCount];
		}
	}

	Float_Matrix3_Struct(initializer_list<float> Mat3_V_list) 
	{
		int Mat3_V = 0;
		for (float Loop : Mat3_V_list)
		{
			Mat3_Array[Mat3_V] = Loop;
			Mat3_V++;
		}
	}

	// *** \/\/\/ Over loading Matrix3's \/\/\/ ***

	Float_Matrix3_Struct operator=(const Float_Matrix3_Struct& Rhs_Matrix3) // assigning values from a matrix3
	{
		
		for (int X_Loop = 0; X_Loop < 3; X_Loop++)
		{
			for (int Y_loop = 0; Y_loop < 3; Y_loop++)
			{
				Mat3_grid[X_Loop][Y_loop] = Rhs_Matrix3.Mat3_grid[X_Loop][Y_loop];
			}
		}

		return *this;
	}

	Float_Vector3_Struct operator*(const Float_Vector3_Struct& Rhs_Float_Vector3_Struct) // multiply the matrix3 by Vector3
	{
		Float_Vector3_Struct tempary_Float_Vector3 = Rhs_Float_Vector3_Struct;
		
		float Add_muilt_holder = 0;

		for (int X_Loop = 0; X_Loop < 3; X_Loop++)
		{
			for (int Y_loop = 0; Y_loop < 3; Y_loop++)
			{
				Add_muilt_holder += tempary_Float_Vector3[Y_loop] * Mat3_grid[X_Loop][Y_loop];
			}

			tempary_Float_Vector3[X_Loop] = Add_muilt_holder;

			Add_muilt_holder = 0;
		}

		tempary_Float_Vector3.display();
		return tempary_Float_Vector3;
	}

	Float_Matrix3_Struct operator*(const Float_Matrix3_Struct& Rhs_Matrix3) // multiply the matrix3 by matrix3
	{
		for (int X_Loop = 0; X_Loop < 3; X_Loop++)
		{
			for (int Y_loop = 0; Y_loop < 3; Y_loop++)
			{
				for (int add_loop = 0; add_loop < 3; add_loop++)
				{
					Mat3_grid[X_Loop][Y_loop] += (Mat3_grid[X_Loop][add_loop] * Rhs_Matrix3.Mat3_grid[add_loop][Y_loop]);

				}
			}
		}

		return *this;
	}

	Float_Matrix3_Struct operator*=(const Float_Matrix3_Struct& Rhs_Matrix3) // multiply the matrix3 by matrix3 and assigning
	{
		*this = *this * Rhs_Matrix3;

		return *this;
	}

	bool operator==(const Float_Matrix3_Struct& Rhs_Matrix3) // testting if matrix3 dose match another matrix3
	{
		int  Match_Count = 0;

		for (int Loop = 0; Loop < 9; Loop++) 
		{
			if (Mat3_Array[Loop] = Rhs_Matrix3.Mat3_Array[Loop])
			{
				Match_Count++;
			}
		}

		return (Match_Count == 9);
	}

	bool operator!=(const Float_Matrix3_Struct& Rhs_Matrix3) // testting if matrix3 does'nt match another matrix3
	{
		int  Match_Count = 0;

		for (int Loop = 0; Loop < 9; Loop++)
		{
			if (Mat3_Array[Loop] = Rhs_Matrix3.Mat3_Array[Loop])
			{
				Match_Count++;
			}
		}

		return (Match_Count < 9);
	}

	float operator[](const int& index_of_matrix) // Calls A element value of the matrix3
	{
		return Mat3_Array[index_of_matrix];
	}

	// *** /\/\/\ Over loading Matrix3's /\/\/\ ***

	// *** \/\/\/ Member functions for Matrix3's \/\/\/ ***
	Float_Matrix3_Struct MakeRotate_2D(float a)
	{
		return 
		{
			cos(a), -sin(a),0,
			sin(a), cos(a),0,
			0,0,1
		};
	}

	Float_Matrix3_Struct MakeScale(float Scale_X, float Scale_Y)
	{
		return
		{
			Scale_X, 0, 0,
			0, Scale_Y, 0,
			0, 0, 1
		};
	}

	Float_Matrix3_Struct MakeTranslate(Float_Vector3_Struct& Rhs_Vector3)
	{
		return Float_Matrix3_Struct
		{
			0,0,Rhs_Vector3.Vector3_x,
			0,0,Rhs_Vector3.Vector3_y,
			0,0,1
		};
	}

	Float_Vector3_Struct GetTanslate()
	{
		return Float_Vector3_Struct(Mat3_grid[2][0], Mat3_grid[2][1], Mat3_grid[2][2]);
	}

	Float_Vector3_Struct GetRight_Y() 
	{
		return Float_Vector3_Struct(Mat3_grid[1][0], Mat3_grid[1][1], Mat3_grid[1][2]);
	}

	Float_Vector3_Struct GetForward_X() 
	{
		return Float_Vector3_Struct(Mat3_grid[0][0], Mat3_grid[0][1], Mat3_grid[0][2]);
	}

	bool IsApproximatelyEqual(Float_Matrix3_Struct& Rhs_Matrix3, float equal_within_value = 1e-4)
	{
		Float_Matrix3_Struct tempary_Float_Matrix3_Diffrence = *this; // grabs this Vector values

		for (int Loop = 0; Loop < 9; Loop++)
		{
			if ((tempary_Float_Matrix3_Diffrence[Loop]- Rhs_Matrix3[Loop]) < equal_within_value && (tempary_Float_Matrix3_Diffrence[Loop] - Rhs_Matrix3[Loop]) > -equal_within_value) // inside of the target range?
			{
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	// *** /\/\/\ Member functions for Matrix3's /\/\/\ ***
	 
	void display() 
	{
		cout << "\n Cuurent Matrix3 values" << endl;
		cout << Mat3_Local_Xaxis_x_m1 << "  " << Mat3_Local_Yaxis_x_m2 << "   " << Mat3_Local_Trans_axis_x_m3 << endl;
		cout << Mat3_Local_Xaxis_y_m4 << "  " << Mat3_Local_Yaxis_y_m5 << "   " << Mat3_Local_Trans_axis_y_m6 << endl;
		cout << Mat3_place_Holder_w_m7 << "  " << Mat3_place_Holder_w_m8 << "   " << Mat3_Point_Or_Vector_m9 << endl;
	}

	~Float_Matrix3_Struct() 
	{

	}
};

struct Float_Matrix4_Struct
{
	union
	{
		struct
		{
			float
				//			local X axis		local y axis		local Z axis		World origin Point
				Mat4_Local_Xaxis_x_m1, Mat4_Local_Yaxis_x_m2, Mat4_Local_Zaxis_x_m3, Mat4_Local_Trans_axis_x_m4, //  X axis  
				Mat4_Local_Xaxis_y_m5, Mat4_Local_Yaxis_y_m6, Mat4_Local_Zaxis_y_m7, Mat4_Local_Trans_axis_y_m8, //  Y axis
				Mat4_Local_Xaxis_z_m9, Mat4_Local_Yaxis_z_m10, Mat4_Local_Zaxis_z_m11, Mat4_Local_Trans_axis_z_m12, //  z axis
				//				\/ place holder and Must start as 0 \/						A point or A vector  
				Mat4_place_Holder_w_m13, Mat4_place_Holder_w_m14, Mat4_place_Holder_w_m15, Mat4_Point_Or_Vector_m16;
		};
		float Mat4_Array[16]; // Holds values of the Matrix3 in eleaments of a array 
		float Mat4_grid[4][4]; // Holds values of the Matrix3 in eleaments of a 4 by 4 grid
	};

	Float_Matrix4_Struct() // constructor
	{
		for (int loopCount = 0; loopCount < 16; loopCount++)
		{
			if (loopCount % 5 == 0)
			{
				Mat4_Array[loopCount] = 1;
			}
			else
			{
				Mat4_Array[loopCount] = 0;
			}
		}
	}

	Float_Matrix4_Struct(const Float_Matrix4_Struct& Copy_Matrix4_Struct) // copy constructor
	{
		for (int loopCount = 0; loopCount < 16; loopCount++)
		{
			Mat4_Array[loopCount] = Copy_Matrix4_Struct.Mat4_Array[loopCount];
		}
	}

	Float_Matrix4_Struct(initializer_list<float> Mat4_V_list)
	{
		int Mat4_V = 0;
		for (float Loop : Mat4_V_list)
		{
			Mat4_Array[Mat4_V] = Loop;
			Mat4_V++;
		}
	}

	// *** \/\/\/ Over loading Matrix4's \/\/\/ ***

	Float_Matrix4_Struct operator=(const Float_Matrix4_Struct& Rhs_Matrix4) // assigning values from a matrix3
	{

		for (int X_Loop = 0; X_Loop < 4; X_Loop++)
		{
			for (int Y_loop = 0; Y_loop < 4; Y_loop++)
			{
				Mat4_grid[X_Loop][Y_loop] = Rhs_Matrix4.Mat4_grid[X_Loop][Y_loop];
			}
		}

		return *this;
	}

	Float_Vector4_Struct operator*(const Float_Vector4_Struct& Rhs_Float_Vector4_Struct) // multiply the matrix3 by Vector3
	{
		Float_Vector4_Struct tempary_Float_Vector4 = Rhs_Float_Vector4_Struct;

		float Add_muilt_holder = 0;

		for (int X_Loop = 0; X_Loop < 4; X_Loop++)
		{
			for (int Y_loop = 0; Y_loop < 4; Y_loop++)
			{
				Add_muilt_holder += tempary_Float_Vector4[Y_loop] * Mat4_grid[X_Loop][Y_loop];
			}

			tempary_Float_Vector4[X_Loop] = Add_muilt_holder;

			Add_muilt_holder = 0;
		}

		tempary_Float_Vector4.display();
		return tempary_Float_Vector4;
	}

	Float_Matrix4_Struct operator*(const Float_Matrix4_Struct& Rhs_Matrix4) // multiply the matrix3 by matrix3
	{
		for (int X_Loop = 0; X_Loop < 4; X_Loop++)
		{
			for (int Y_loop = 0; Y_loop < 4; Y_loop++)
			{
				for (int add_loop = 0; add_loop < 4; add_loop++)
				{
					Mat4_grid[X_Loop][Y_loop] += (Mat4_grid[X_Loop][add_loop] * Rhs_Matrix4.Mat4_grid[add_loop][Y_loop]);

				}
			}
		}

		return *this;
	}

	Float_Matrix4_Struct operator*=(const Float_Matrix4_Struct& Rhs_Matrix4) // multiply the matrix3 by matrix3 and assigning
	{
		*this = *this * Rhs_Matrix4;

		return *this;
	}

	bool operator==(const Float_Matrix4_Struct& Rhs_Matrix4) // testting if matrix3 dose match another matrix3
	{
		int  Match_Count = 0;

		for (int Loop = 0; Loop < 16; Loop++)
		{
			if (Mat4_Array[Loop] = Rhs_Matrix4.Mat4_Array[Loop])
			{
				Match_Count++;
			}
		}

		return (Match_Count == 9);
	}

	bool operator!=(const Float_Matrix4_Struct& Rhs_Matrix4) // testting if matrix3 does'nt match another matrix3
	{
		int  Match_Count = 0;

		for (int Loop = 0; Loop < 16; Loop++)
		{
			if (Mat4_Array[Loop] = Rhs_Matrix4.Mat4_Array[Loop])
			{
				Match_Count++;
			}
		}

		return (Match_Count < 9);
	}

	float operator[](const int& index_of_matrix) // Calls A element value of the matrix3
	{
		return Mat4_Array[index_of_matrix];
	}

	// *** /\/\/\ Over loading Matrix4's /\/\/\ ***

	// *** \/\/\/ Member functions for Matrix3's \/\/\/ ***

	static Float_Matrix4_Struct Rotate_X(float a)
	{
		return
		{
			1,	0,	0,0,
			0, cosf(a), -sinf(a),0,
			0, sinf(a), cosf(a),1
		};
	}

	static Float_Matrix4_Struct Rotate_Y(float a)
	{
		return
		{
			cosf(a), 0, -sinf(a),0,
				0,	 1,		0,0,
			sinf(a), 0, cosf(a),1
		};
	}

	static Float_Matrix4_Struct Rotate_Z(float a)
	{
		return
		{
			cosf(a),sinf(a), 0,0,
			-sinf(a),cosf(a),0,0,
			0,0,	0, 1
		};
	}

	static Float_Matrix4_Struct Euler_Rotate(float Pitch_X, float Yaw_Y, float roll_Z)
	{
		Float_Matrix4_Struct X = Rotate_X(Pitch_X);
		Float_Matrix4_Struct Y = Rotate_Y(Yaw_Y);
		Float_Matrix4_Struct Z = Rotate_Z(roll_Z);

		return (Z * Y * X);
	}

	static Float_Matrix4_Struct MakeScale(float Scale_X, float Scale_Y, float Scale_Z)
	{
		return
		{
			Scale_X, 0, 0,0,
			0, Scale_Y, 0,0,
			0, 0, Scale_Z,0,
			0, 0, 0, 1
		};
	}

	Float_Vector4_Struct GetRight_X()
	{
		return Float_Vector4_Struct(Mat4_grid[0][0], Mat4_grid[0][1], Mat4_grid[0][2], Mat4_grid[0][3]);
	}

	Float_Vector4_Struct GetRight_Y()
	{
		return Float_Vector4_Struct(Mat4_grid[1][0], Mat4_grid[1][1], Mat4_grid[1][2], Mat4_grid[1][3]);
	}

	Float_Vector4_Struct GetForward_Z()
	{
		return Float_Vector4_Struct(Mat4_grid[2][0], Mat4_grid[2][1], Mat4_grid[2][2], Mat4_grid[2][3]);
	}

	Float_Vector4_Struct GetPosition_W()
	{
		return Float_Vector4_Struct(Mat4_grid[3][0], Mat4_grid[3][1], Mat4_grid[3][2], Mat4_grid[3][3]);
	}

	bool IsApproximatelyEqual(Float_Matrix4_Struct& Rhs_Matrix4, float equal_within_value = 1e-4)
	{
		Float_Matrix4_Struct tempary_Float_Matrix4_Diffrence = *this; // grabs this Vector values

		for (int Loop = 0; Loop < 16; Loop++)
		{
			if ((tempary_Float_Matrix4_Diffrence[Loop] - Rhs_Matrix4[Loop]) < equal_within_value && (tempary_Float_Matrix4_Diffrence[Loop] - Rhs_Matrix4[Loop]) > -equal_within_value) // inside of the target range?
			{
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	Float_Matrix4_Struct SetTranslate(Float_Vector4_Struct& Rhs_Vector)
	{
		Float_Matrix4_Struct tempary_Float_Matrix4 = *this;
		
		Mat4_grid[0][3] = Rhs_Vector.Vector4_x;
		Mat4_grid[1][3] = Rhs_Vector.Vector4_y;
		Mat4_grid[2][3] = Rhs_Vector.Vector4_z;

		return *this;
	}

	Float_Matrix4_Struct MakeTranslate(Float_Vector4_Struct& Rhs_Vector) 
	{
		Float_Matrix4_Struct tempary_Float_Matrix4 = *this;

		tempary_Float_Matrix4.Mat4_grid[0][3] = Rhs_Vector.Vector4_x;
		tempary_Float_Matrix4.Mat4_grid[1][3] = Rhs_Vector.Vector4_y;
		tempary_Float_Matrix4.Mat4_grid[2][3] = Rhs_Vector.Vector4_z;

		return tempary_Float_Matrix4;
	}

	// *** /\/\/\ Member functions for Matrix4's /\/\/\ ***

	void display() // display the Matrix4 values in a lose grid like fastion
	{
		cout << "\n Cuurent Matrix4 values" << endl;
		cout << Mat4_Local_Xaxis_x_m1 << "  " << Mat4_Local_Yaxis_x_m2 << "   " << Mat4_Local_Zaxis_x_m3 << "   " << Mat4_Local_Trans_axis_x_m4 << endl;
		cout << Mat4_Local_Xaxis_y_m5 << "  " << Mat4_Local_Yaxis_y_m6 << "   " << Mat4_Local_Zaxis_y_m7 << "   " << Mat4_Local_Trans_axis_y_m8 << endl;
		cout << Mat4_Local_Xaxis_z_m9 << "  " << Mat4_Local_Yaxis_z_m10 << "   " << Mat4_Local_Zaxis_z_m11 << "   " << Mat4_Local_Trans_axis_z_m12 << endl;
		cout << Mat4_place_Holder_w_m13 << "  " << Mat4_place_Holder_w_m14 << "   " << Mat4_place_Holder_w_m15 << "   " << Mat4_Point_Or_Vector_m16 << endl;
	}

	~Float_Matrix4_Struct()
	{

	}
};

void Vector3_Overload_Mem_Functions(Float_Vector3_Struct First_Vector3, Float_Vector3_Struct Second_Vector3) // vector3 that is Overloaded
{
	cout << "*** Running Overloaded Vector 3's ***" << endl;
	
	Float_Vector3_Struct Current_Vector3 = First_Vector3 + Second_Vector3; // Create a Current Vectors by asigning it the sum of First_Vector3 and Second_Vector3
	Float_Vector3_Struct Copy_vector3 = First_Vector3; // asigning An new vactor the same values of the First_Vector3
	Copy_vector3.display(); // display the copy Vector3

	Current_Vector3.display(); // Display the Current_Vector3

	Current_Vector3 = (Current_Vector3 + 154); // add all values of Current_Vector3 with an float using the overloaded + operartor 
	Current_Vector3.display(); // display the Current_Vector3

	Current_Vector3 = Current_Vector3 - First_Vector3; // subtrack all values of Current_Vector3 with Vector3 using the overloaded - operartor 
	Current_Vector3.display();

	Current_Vector3 = (Current_Vector3 - -7.4); // subtrack all values of Current_Vector3 with float value  using the overloaded - operartor 
	Current_Vector3.display();

	Current_Vector3 = Current_Vector3 * First_Vector3; // muitply all values of Current_Vector3 with an Vector3 using the overloaded * operartor 
	Current_Vector3.display();

	Current_Vector3 = (Current_Vector3 * 2.5); // muitply all values of Current_Vector3 with an float using the overloaded * operartor 
	Current_Vector3.display();

	Current_Vector3 = Current_Vector3 / First_Vector3; // divide all values of Current_Vector3 with an Vector3 using the overloaded / operartor 
	Current_Vector3.display();

	Current_Vector3 = (Current_Vector3 / -3.4); // divide all values of Current_Vector3 with an float using the overloaded / operartor 
	Current_Vector3.display();

	Current_Vector3 = First_Vector3;  // Set the values from Current_Vector3 to  be the same as a vector3 with the overloaded = operator
	Current_Vector3.display();

	if (Current_Vector3 == First_Vector3) // test if both vectors are equal to each other by testing each vector value with pverloaed == operartor
	{
		cout << "Current_Vector Matches First_Vector" << endl;
	}

	Current_Vector3 = -Current_Vector3; // change all the vector3 values from postive to negtive or negtive to posstive with the overloaded -Vector3 operartor
	Current_Vector3.display();

	if (Current_Vector3 < Second_Vector3) // Test if one vector3 is greater then other Vectorwith the overloaded < operator 
	{
		cout << "Current_Vector is less then Second_Vector" << endl;
	}
	else
	{
		cout << "Current_Vector isn't less then Second_Vector" << endl;
	}

	cout << "index 1 value of the Second_Vector3 is : " << Second_Vector3[1] << endl;

	cout << "\n*** Ending Overloaded Vector 3's *-*" << endl;


	cout << "\n *-* Starting Member functions for Vector 3's *-*" << endl;

	cout << "\n Dot product between First_Vector3 and Second_Vector3 equals: " << First_Vector3.V3_Dot_prod(Second_Vector3) << endl;

	Current_Vector3 = First_Vector3.V3_Cross_prod(Second_Vector3);
	cout << "\n Cross product between Second_Vector3 and First_Vector3 equals: " << endl;
	Current_Vector3.display();

	cout << "Magnitude of Current_Vector3 is: " << Current_Vector3.V3_Magnitude() << endl;

	cout << "what happens when we Normalise Current_Vector3?\n" << endl;

	Current_Vector3.Normalise();

	cout << "Lets see Second_Vector3 Normalised\n" << endl;
	Second_Vector3.Normalised();

	cout << " is Second_Vector3 Approximately Equal to First_Vector3 with default?: " << Second_Vector3.IsApproximatelyEqual(First_Vector3) << endl;

	cout << " is Second_Vector3 Approximately Equal to First_Vector3 by 3.5?: " << Second_Vector3.IsApproximatelyEqual(First_Vector3, 3.5) << endl;

	cout << "what is the Distance between Current_Vector3 and First_Vector3: " << Current_Vector3.Distance(First_Vector3) << endl;

	cout << "\n Here is the 2d angle of First_Vector3 comapred to world origin(1,0): " << First_Vector3.Angle2D() << "\n ^^^ hard coded ^^^" << endl;

	cout << "\n*-* Ending Member functions for Vector 3's *-*" << endl;
}

void Vector4_Overload_Mem_Functions(Float_Vector4_Struct First_Vector4, Float_Vector4_Struct Second_Vector4) // vector3 that is Overloaded
{

	cout << "\n *** Running Overloaded Vector 4's ***" << endl;

	Float_Vector4_Struct Current_Vector4 = First_Vector4 + Second_Vector4; // Create a Current Vectors by asigning it the sum of First_Vector3 and Second_Vector3
	Float_Vector4_Struct Copy_vector4 = First_Vector4; // asigning An new vactor the same values of the First_Vector3
	Copy_vector4.display(); // display the copy Vector3

	Current_Vector4.display(); // Display the Current_Vector3

	Current_Vector4 = (Current_Vector4 + 154); // add all values of Current_Vector3 with an float using the overloaded + operartor 
	Current_Vector4.display(); // display the Current_Vector3

	Current_Vector4 = Current_Vector4 - Second_Vector4; // subtrack all values of Current_Vector3 with Vector3 using the overloaded - operartor 
	Current_Vector4.display();

	Current_Vector4 = (Current_Vector4 - -7.4); // subtrack all values of Current_Vector3 with float value  using the overloaded - operartor 
	Current_Vector4.display();

	Current_Vector4 = Current_Vector4 * First_Vector4; // muitply all values of Current_Vector3 with an Vector3 using the overloaded * operartor 
	Current_Vector4.display();

	Current_Vector4 = (Current_Vector4 * 2.5); // muitply all values of Current_Vector3 with an float using the overloaded * operartor 
	Current_Vector4.display();

	Current_Vector4 = Current_Vector4 / Second_Vector4; // divide all values of Current_Vector3 with an Vector3 using the overloaded / operartor 
	Current_Vector4.display();

	Current_Vector4 = (Current_Vector4 / -3.4); // divide all values of Current_Vector3 with an float using the overloaded / operartor 
	Current_Vector4.display();

	Current_Vector4 = First_Vector4;  // Set the values from Current_Vector3 to  be the same as a vector3 with the overloaded = operator
	Current_Vector4.display();

	if (Current_Vector4 == First_Vector4) // test if both vectors are equal to each other by testing each vector value with pverloaed == operartor
	{
		cout << "Current_Vector Matches First_Vector" << endl;
	}

	Current_Vector4 = -Current_Vector4; // change all the vector3 values from postive to negtive or negtive to posstive with the overloaded -Vector3 operartor
	Current_Vector4.display();

	if (Current_Vector4 < Second_Vector4) // Test if one vector3 is greater then other Vectorwith the overloaded < operator 
	{
		cout << "Current_Vector is less then Second_Vector" << endl;
	}
	else
	{
		cout << "Current_Vector isn't less then Second_Vector" << endl;
	}

	cout << "index 1 value of the Second_Vector4 is : " << Second_Vector4[1] << endl;

	cout << "\n*** Ending Overloaded Vector 4's ***" << endl;

	cout << "\n *-* Starting Member functions for Vector 4's *-*" << endl;

	cout << "\n Dot product between First_Vector4 and Second_Vector4 equals: " << First_Vector4.V4_Dot_prod(Second_Vector4) << endl;

	Current_Vector4 = First_Vector4.V4_Cross_prod(Second_Vector4);
	cout << "\n Cross product between Second_Vector4 and First_Vector4 equals: " << endl;
	Current_Vector4.display();

	cout << "Magnitude of Current_Vector4 is: " << Current_Vector4.V4_Magnitude() << endl;

	cout << "what happens when we Normalise Current_Vector4?\n" << endl;

	Current_Vector4.Normalise();

	cout << "Lets see Second_Vector4 Normalised\n" << endl;
	Second_Vector4.Normalised();

	cout << " is Second_Vector4 Approximately Equal to First_Vector4 with default?: " << Second_Vector4.IsApproximatelyEqual(First_Vector4) << endl;

	cout << " is Second_Vector4 Approximately Equal to First_Vector4 by 3.5?: " << Second_Vector4.IsApproximatelyEqual(First_Vector4, 3.5) << endl;

	cout << "what is the Distance between Current_Vector4 and First_Vector4: " << Current_Vector4.Distance(First_Vector4) << endl;

	cout << "\n*-* Ending Member functions for Vector 4's *-*" << endl;
}

void Matrix3_Overload_Mem_Functions(Float_Matrix3_Struct First_Matrix3, Float_Matrix3_Struct Second_Matrix3, Float_Vector3_Struct First_Vector3)
{
	cout << "\n*** Running Overloaded Matrix 3's ***" << endl;

	First_Matrix3.display();
	Second_Matrix3.display();

	Float_Matrix3_Struct Current_Matrix3 = First_Matrix3;

	Current_Matrix3 * First_Matrix3;
	Current_Matrix3.display();

	First_Vector3 = Current_Matrix3 * First_Vector3;
	Current_Matrix3.display();

	Current_Matrix3 *= Second_Matrix3;
	Current_Matrix3.display();

	
	if (First_Matrix3 == Second_Matrix3)
	{
		cout << "\n Matrix3 dose  match " << endl;
		Current_Matrix3.display();
	}
	else
	{
		cout << "Matrix3 dose not match ... reseting data" << endl;
		Current_Matrix3 = Second_Matrix3;
		Current_Matrix3.display();
	};

	if (Current_Matrix3 != Second_Matrix3)
	{
		cout << "Matrix3 dose not match ... Seting New vlaues" << endl;
		Current_Matrix3 * First_Matrix3;
		Current_Matrix3.display();

	}
	else
	{
		cout << "Matrix3 dose  match ... Doing notthing" << endl;
		Current_Matrix3.display();
	}

	cout << "\n Current_Matrix3 Yy value is: " << Current_Matrix3[4] << endl;

	cout << "\n*** Ending Overloaded Matrix 3's ***" << endl;


	cout << "\n *-* Starting Member functions for Matrix 3's *-*" << endl;

	Float_Matrix3_Struct Display_Marix3;
	Display_Marix3 = Display_Marix3.MakeRotate_2D(45);

	cout << "\n making an matrix for Rotation: " << endl;
	Display_Marix3.display();

	cout << "\n making an matrix for scale: " << endl;
	Display_Marix3 = Display_Marix3.MakeScale(24, 5);
	Display_Marix3.display();

	cout << "\n making an matrix for Translate: " << endl;
	Display_Marix3 = Display_Marix3.MakeTranslate(First_Vector3);
	Display_Marix3.display();

	cout << "\n Getting Right Axis_direction of Current_Matrix3: " << endl;
	Float_Vector3_Struct Axis_direction = Current_Matrix3.GetRight_Y();
	Axis_direction.display();

	cout << "\n Getting Forward Axis_direction of Second_Matrix3: " << endl;
	Axis_direction = Second_Matrix3.GetRight_Y();
	Axis_direction.display();

	cout << "\n Getting Translation of Current_Matrix3: " << endl;
	Float_Vector3_Struct Postion_Marix3 = Current_Matrix3.GetTanslate();
	Postion_Marix3.display();

	cout << "\n is Current_Matrix3 Approximately Equal to Second_Matrix3?: " << Current_Matrix3.IsApproximatelyEqual(First_Matrix3) << endl;

	cout << "\n is Current_Matrix3 Approximately Equal to Second_Matrix3 within 6?: " << Current_Matrix3.IsApproximatelyEqual(First_Matrix3,6) << endl;

	cout << "\n *-* Ending Member functions for Matrix 3's *-*" << endl;
}

void Matrix4_Overload_Mem_Functions(Float_Matrix4_Struct Third_Matrix4, Float_Matrix4_Struct Forth_Matrix4, Float_Vector4_Struct forth_vector4)
{
	cout << "\n*** Running Overloaded Matrix 4's ***" << endl;

	Third_Matrix4.display();
	Forth_Matrix4.display();

	Float_Matrix4_Struct Current_Matrix4 = Third_Matrix4;

	Current_Matrix4* Forth_Matrix4;
	Current_Matrix4.display();

	forth_vector4 = Current_Matrix4 * forth_vector4;
	Current_Matrix4.display();

	Current_Matrix4 *= Forth_Matrix4;
	Current_Matrix4.display();


	if (Third_Matrix4 == Forth_Matrix4)
	{
		cout << "\n Matrix4 dose  match " << endl;
		Current_Matrix4.display();
	}
	else
	{
		cout << "Matrix4 dose not match ... reseting data" << endl;
		Current_Matrix4 = Forth_Matrix4;
		Current_Matrix4.display();
	};

	if (Current_Matrix4 != Forth_Matrix4)
	{
		cout << "Matrix4 dose not match ... Seting New vlaues" << endl;
		Current_Matrix4* Third_Matrix4;
		Current_Matrix4.display();

	}
	else
	{
		cout << "Matrix4 doset match ... Doing notthing" << endl;
		Current_Matrix4.display();
	}

	cout << "\n Current_Matrix4 Zz value is: " << Current_Matrix4[9] << endl;

	cout << "\n*** Ending Overloaded Matrix 4's ***" << endl;
}

int main() 
{
	Float_Vector3_Struct First_Vector3(2, 4, 6), Second_Vector3(1, 3, 5); // Create two New vector3

	Vector3_Overload_Mem_Functions(First_Vector3,Second_Vector3); // Testing Vector3 has overloaded it's operators

	Float_Vector4_Struct Third_Vector4(34, 956, 27, 65), forth_vector4(47, 42, 365, 2); // Create two new vector4

	Vector4_Overload_Mem_Functions(Third_Vector4, forth_vector4); // Testing Vector4 has overloaded it's operators

	Float_Matrix3_Struct First_Matrix3{1,4,3,8,2,9,0,0,1}, Second_Matrix3;

	Matrix3_Overload_Mem_Functions(First_Matrix3, Second_Matrix3, First_Vector3);

	Float_Matrix4_Struct Third_Matrix4{1,4,3,8,2,9,0,2,5,7,3,7,0,0,0,1}, Forth_Matrix4;

	Matrix4_Overload_Mem_Functions(Third_Matrix4, Forth_Matrix4, forth_vector4);
}
