#pragma once

namespace MathLibrary
{
	struct Float_Vector4_Struct
	{
		float Vector4_x = 0; // place holders for the 4 Vector valuse for a Vector3
		float Vector4_y = 0;
		float Vector4_z = 0;
		float Vector4_w = 0;

		Float_Vector4_Struct() // Sets the values to the desired values from it's creation  
		{
			Vector4_x = 0;
			Vector4_y = 0;
			Vector4_z = 0;
			Vector4_w = 0;
		}

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

		Float_Vector4_Struct operator+(const Float_Vector4_Struct& adding_Target) const //adding self cloned Vector data to Target Vector
		{
			Float_Vector4_Struct temporary = *this; // Create a clone vectors from self

			temporary.Vector4_x += adding_Target.Vector4_x; // adding clone Vecotor.x to Target vector.x
			temporary.Vector4_y += adding_Target.Vector4_y; // adding clone Vecotor.x to Target vector.y
			temporary.Vector4_z += adding_Target.Vector4_z; // adding clone Vecotor.x to Target vector.z
			//temporary.Vector4_w += adding_Target.Vector4_w; // adding clone Vecotor.x to Target vector.w

			return temporary; // return the four added vector values.    
		}


		Float_Vector4_Struct operator+=(const Float_Vector4_Struct& adding_Target)  //adding self cloned Vector data to Target Vector
		{
			Vector4_x += adding_Target.Vector4_x; // adding clone Vecotor.x to Target vector.x
			Vector4_y += adding_Target.Vector4_y; // adding clone Vecotor.x to Target vector.y
			Vector4_z += adding_Target.Vector4_z; // adding clone Vecotor.x to Target vector.z
			//Vector4_w += adding_Target.Vector4_w; // adding clone Vecotor.x to Target vector.w

			return* this;
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

		Float_Vector4_Struct operator+=(const float Target_float)  //adding  self cloned Vector data to Target float
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
			//temporary.Vector4_z = (temporary.Vector4_w - subtracking_Target.Vector4_w); // subtracking clone Vecotor.x to Target vector.w


			return temporary; // return the four subtracked vector values.    
		}

		Float_Vector4_Struct operator-=(const Float_Vector4_Struct& subtracking_Target)  //subtracking self cloned Vector data to Target Vector
		{

			Vector4_x -= subtracking_Target.Vector4_x; // subtracking clone Vecotor.x to Target vector.x
			Vector4_y -= subtracking_Target.Vector4_y; // subtracking clone Vecotor.x to Target vector.y
			Vector4_z -= subtracking_Target.Vector4_z; // subtracking clone Vecotor.x to Target vector.z
			//temporary.Vector4_z = (temporary.Vector4_w - subtracking_Target.Vector4_w); // subtracking clone Vecotor.x to Target vector.w


			return *this;
		}

		Float_Vector4_Struct operator-(const float Target_float) const //subtracking  self cloned Vector data to Target float
		{
			Float_Vector4_Struct temporary = *this; // subtracking a clone vectors from self

			temporary.Vector4_x -= Target_float; // subtracking clone Vecotor.x to float
			temporary.Vector4_y -= Target_float; // subtracking clone Vecotor.y to float
			temporary.Vector4_z -= Target_float; // subtracking clone Vecotor.z to float


			return temporary; // return the four  divided vector values.    
		}

		Float_Vector4_Struct operator-=(const float Target_float)  //subtracking  self cloned Vector data to Target float
		{
			Float_Vector4_Struct temporary = *this; // subtracking a clone vectors from self

			temporary.Vector4_x -= Target_float; // subtracking clone Vecotor.x to float
			temporary.Vector4_y -= Target_float; // subtracking clone Vecotor.y to float
			temporary.Vector4_z -= Target_float; // subtracking clone Vecotor.z to float


			return temporary; // return the four  divided vector values.    
		}

		Float_Vector4_Struct operator*(const Float_Vector4_Struct& multiplying_Target) const //multiplying  self cloned Vector data to Target Vector
		{
			Float_Vector4_Struct temporary = *this; // Create a clone vectors from self

			temporary.Vector4_x = (temporary.Vector4_x * multiplying_Target.Vector4_x); // multiplying clone Vecotor.x to Target vector.x
			temporary.Vector4_y = (temporary.Vector4_y * multiplying_Target.Vector4_y); // multiplying clone Vecotor.y to Target vector.y
			temporary.Vector4_z = (temporary.Vector4_z * multiplying_Target.Vector4_z); // multiplying clone Vecotor.z to Target vector.z
			temporary.Vector4_w = (temporary.Vector4_w * multiplying_Target.Vector4_w); // multiplying clone Vecotor.w to Target vector.w

			return temporary; // return the four multiplied vector values.    
		}

		Float_Vector4_Struct operator*=(const Float_Vector4_Struct& multiplying_Target)  //multiplying  self cloned Vector data to Target Vector
		{
			Vector4_x *= multiplying_Target.Vector4_x; // multiplying clone Vecotor.x to Target vector.x
			Vector4_y *= multiplying_Target.Vector4_y; // multiplying clone Vecotor.y to Target vector.y
			Vector4_z *= multiplying_Target.Vector4_z; // multiplying clone Vecotor.z to Target vector.z
			//Vector4_w *= multiplying_Target.Vector4_w; // multiplying clone Vecotor.w to Target vector.w

			return *this; // return the four multiplied vector values.    
		}

		Float_Vector4_Struct operator*(const float Target_float) const //multiplying  self cloned Vector data to Target float
		{
			Float_Vector4_Struct temporary = *this; // Create a clone vectors from self

			temporary.Vector4_x *= Target_float; // multiplying clone Vecotor.x to float
			temporary.Vector4_y *= Target_float; // multiplying clone Vecotor.y to float
			temporary.Vector4_z *= Target_float; // multiplying clone Vecotor.z to float
			//temporary.Vector4_w *= Target_float; // multiplying clone Vecotor.w to float


			return temporary; // return the four divided vector values.    
		}

		Float_Vector4_Struct operator*=(const float Target_float)  //multiplying  self cloned Vector data to Target float
		{
			Vector4_x *= Target_float; // multiplying clone Vecotor.x to float
			Vector4_y *= Target_float; // multiplying clone Vecotor.y to float
			Vector4_z *= Target_float; // multiplying clone Vecotor.z to float
			//Vector4_w *= Target_float; // multiplying clone Vecotor.w to float

			return *this;
		}

		Float_Vector4_Struct operator/(const Float_Vector4_Struct& dividing_Target) const  //dividing  self cloned Vector data to Target Vector
		{
			Float_Vector4_Struct temporary = *this; // Create a clone vectors from self

			temporary.Vector4_x = (temporary.Vector4_x / dividing_Target.Vector4_x); // dividing clone Vecotor.x to Target vector.x
			temporary.Vector4_y = (temporary.Vector4_y / dividing_Target.Vector4_y); // dividing clone Vecotor.x to Target vector.y
			temporary.Vector4_z = (temporary.Vector4_z / dividing_Target.Vector4_z); // dividing clone Vecotor.x to Target vector.z
			temporary.Vector4_w = (temporary.Vector4_w / dividing_Target.Vector4_w); // dividing clone Vecotor.x to Target vector.w


			return temporary; // return the four divided vector values.    
		}

		//Float_Vector4_Struct operator/=(const Float_Vector4_Struct& dividing_Target)  //dividing  self cloned Vector data to Target Vector
		//{
		//	Vector4_x /= dividing_Target.Vector4_x; // dividing clone Vecotor.x to Target vector.x
		//	Vector4_y /= dividing_Target.Vector4_y; // dividing clone Vecotor.x to Target vector.y
		//	Vector4_z /= dividing_Target.Vector4_z; // dividing clone Vecotor.x to Target vector.z
		//	Vector4_w /= dividing_Target.Vector4_w; // dividing clone Vecotor.x to Target vector.w

		//	return *this; // return the four divided vector values.    
		//}

		Float_Vector4_Struct operator/(const float Target_float) const //dividing  self cloned Vector data to Target float
		{
			Float_Vector4_Struct temporary = *this; // Create a clone vectors from self

			temporary.Vector4_x /= Target_float; // dividing clone Vecotor.x to float
			temporary.Vector4_y /= Target_float; // dividing clone Vecotor.y to float
			temporary.Vector4_z /= Target_float; // dividing clone Vecotor.z to float
			//temporary.Vector4_w /= Target_float; // dividing clone Vecotor.w to float


			return temporary; // return the four divided vector values.    
		}

		Float_Vector4_Struct operator/=(const float Target_float)  //dividing  self cloned Vector data to Target float
		{
			Vector4_x /= Target_float; // dividing clone Vecotor.x to float
			Vector4_y /= Target_float; // dividing clone Vecotor.y to float
			Vector4_z /= Target_float; // dividing clone Vecotor.z to float
			//Vector4_w /= Target_float; // dividing clone Vecotor.w to float

			return *this; // return the four divided vector values.    
		}

		Float_Vector4_Struct operator=(const Float_Vector4_Struct& Rhs_Vector)  //  Assigning New vector values from another vector
		{
			Vector4_x = Rhs_Vector.Vector4_x;
			Vector4_y = Rhs_Vector.Vector4_y;
			Vector4_z = Rhs_Vector.Vector4_z;
			Vector4_w = Rhs_Vector.Vector4_w;

			return *this; // return the three new vector values.    
		}

		float& operator[](const int Return_Vector_value)  //instead of calling on the values by going this.Vector4_x, call the values as if it was an a refrance to an element of array
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


		bool operator==(const Float_Vector4_Struct& Testing_Vector4) const //Testing  Vector data see if it matches Testing_Vector3 
		{
			Float_Vector4_Struct temporary = *this; // Create a clone vectors from self

			return  ((temporary.Vector4_x == Testing_Vector4.Vector4_x) && (temporary.Vector4_y == Testing_Vector4.Vector4_y) && (temporary.Vector4_z == Testing_Vector4.Vector4_z) && (temporary.Vector4_w == Testing_Vector4.Vector4_w)); // return either true or false   
		}

		bool operator!=(const Float_Vector4_Struct& Testing_Vector4)  //Testing  Vector data see if it matches Testing_Vector3 
		{
			float threshold = 0.000001;

			Float_Vector4_Struct temporary = *this; // Create a clone vectors from self
			return
				(
					(fabsf(temporary.Vector4_x - Testing_Vector4.Vector4_x)) < threshold
					)
				&&
				(
					(fabsf(temporary.Vector4_y - Testing_Vector4.Vector4_y)) < threshold
					)
				&&
				(
					(fabsf(temporary.Vector4_z - Testing_Vector4.Vector4_w)) < threshold
					)
				&&
				(
					(fabsf(temporary.Vector4_w - Testing_Vector4.Vector4_w)) < threshold
					);
		}

		bool operator<(Float_Vector4_Struct& Testing_Vector4)  //Testing  Vector data see if it matches Testing_Vector3 
		{
			Float_Vector4_Struct temporary_squraed = *this * (*this); // Create a squared clone vectors from self
			Float_Vector4_Struct Testing_squraed_Vector4 = (Testing_Vector4 * Testing_Vector4); // Create a Sqaured clone vector from testing Vector

			float this_Squared_Magatune = temporary_squraed.Vector4_x + temporary_squraed.Vector4_y + temporary_squraed.Vector4_z + temporary_squraed.Vector4_w; // add all sqaured Vectors together from self clone
			float Testing_Squared_Magatune2 = Testing_squraed_Vector4.Vector4_x + Testing_squraed_Vector4.Vector4_y + Testing_squraed_Vector4.Vector4_z + Testing_squraed_Vector4.Vector4_w; // add all sqaured vectors together from testing clone 

			return (this_Squared_Magatune < Testing_Squared_Magatune2);  // if this_Squared_Magatune is smaller then Testing_Squared_Magatune2, then return true.
		}


		Float_Vector4_Struct operator-()  //  making the Vectors swhich from postive to negtive
		{
			Vector4_x *= -1;
			Vector4_y *= -1;
			Vector4_z *= -1;
			//Vector4_w *= -1;

			return *this; // return the three updated vector values.    
		}

		// *** /\/\/\ Over loading Vector4's /\/\/\ ***

		// *** \/\/\/ Member functions for Vector4's \/\/\/ ***

		float V4_Dot_prod(const Float_Vector4_Struct& Rhs_V4) // getting the dot product from two vector4's
		{
			Float_Vector4_Struct tempary_Float_Vector3 = *this; // clone the values from this vector 4

			float Dot_Prod_result = 0; // A place to store the sum total of the products between the two vector 4 vlaues

			for (int Y_loop = 0; Y_loop < 4; Y_loop++) // loop though all the values of the vector4
			{
				Dot_Prod_result += tempary_Float_Vector3[Y_loop] * Rhs_V4[Y_loop]; // incease the value of Dot_Prod_result by the product between the two values from the vector4's
			}

			return Dot_Prod_result; // return the sum of al the products from the two vector4's
		}

		Float_Vector4_Struct V4_Cross_prod(const Float_Vector4_Struct Rhs_V4) // Geting an vector from the Cross product of two vector4's 
		{
			return Float_Vector4_Struct
			(
				(Vector4_y * Rhs_V4.Vector4_z) - (Vector4_z * Rhs_V4.Vector4_y),
				(Vector4_z * Rhs_V4.Vector4_x) - (Vector4_x * Rhs_V4.Vector4_z),
				(Vector4_x * Rhs_V4.Vector4_y) - (Vector4_y * Rhs_V4.Vector4_x),
				0
			);
		}

		float V4_Magnitude() const // getting and returning the vector 4 Mangnitdue after by sqaure rooting the squred values of the vector4
		{
			return sqrtf((Vector4_x * Vector4_x) + (Vector4_y * Vector4_y) + (Vector4_z * Vector4_z));
		}

		void Normalise() //Normalise the vector4's values via dividing the Vector4's values with it'smagnitude  
		{
			this->Normalised();
		}

		Float_Vector4_Struct Normalised() // Send an Normalise copy of this Vector 
		{
			float Norm = V4_Magnitude();
			
			if (Norm > 0.0f)
			{
				return *this /= Norm;
			}
			else
			{
				return {0,0,0,0};
			}
		}

		bool IsApproximatelyEqual(const Float_Vector4_Struct& Rhs_Vector4, float equal_within_value = 1e-4) const // checks if this vector is equal to another vector within range. it checks by defualt if it's equal within 1-e4 
		{
			Float_Vector4_Struct tempary_Float_Vector3_Diffrence = *this; // clone this vector4' values 

			for (int Loop = 0; Loop < 4; Loop++) // lopp thought all it's elements and check to see if any value falls out side of range of the equal_within_value  
			{
				if ((tempary_Float_Vector3_Diffrence[Loop] - Rhs_Vector4[Loop]) < equal_within_value && (tempary_Float_Vector3_Diffrence[Loop] - Rhs_Vector4[Loop]) > -equal_within_value) // if any fail, return false
				{

				}
				else
				{
					return false;
				}
			}

			return true;
		}

		float AngleBetween(Float_Vector4_Struct Rhs_vector4) // Find the angle between this vector4 and other vector4 
		{
			//return acos(Normalised().V4_Dot_prod(Rhs_vector4.Normalised())); // using cos to find the angle


			return acos(Normalised().V4_Dot_prod(Rhs_vector4.Normalised())); // using cos to find the angle

			// code provided by Lachlan White \/\/\/

			double tmp = 0;

			tmp += (Vector4_x * Rhs_vector4.Vector4_x);

			tmp += (Vector4_y * Rhs_vector4.Vector4_y);

			tmp += (Vector4_z * Rhs_vector4.Vector4_z);

			float mag1 = std::sqrt((Vector4_x * Vector4_x) + (Vector4_y * Vector4_y) + (Vector4_z * Vector4_z));

			float mag2 = std::sqrt((Rhs_vector4.Vector4_x * Rhs_vector4.Vector4_x) + (Rhs_vector4.Vector4_y * Rhs_vector4.Vector4_y) + (Rhs_vector4.Vector4_z * Rhs_vector4.Vector4_z));

			tmp = tmp / (mag1 * mag2);

			tmp = std::acos(tmp);

			return tmp;
			// code provided by Lachlan White /\/\/\

		}

		float Distance(Float_Vector4_Struct Rhs_vector4) // find the diffrentnce between two Magnitude's to find the two vector4's  
		{
			Float_Vector4_Struct tempary_Float_Vector4 = *this;

			tempary_Float_Vector4 -= Rhs_vector4;

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
}