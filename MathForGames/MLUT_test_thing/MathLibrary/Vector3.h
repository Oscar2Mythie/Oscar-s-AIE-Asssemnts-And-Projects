#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace MathLibrary
{
    struct Vector3
    {
		float Vector3_x = 0; // place holders for the 3 Vector valuse for a Vector3
		float Vector3_y = 0;
		float Vector3_z = 0;


		Vector3(float V3x, float V3y, float V3z) // Sets the values to the desired values from it's creation  
		{
			Vector3_x = V3x;
			Vector3_y = V3y;
			Vector3_z = V3z;
		}

		Vector3(const Vector3& Other_Vector3) // copy constuckor
		{
			Vector3_x = Other_Vector3.Vector3_x;
			Vector3_y = Other_Vector3.Vector3_y;
			Vector3_z = Other_Vector3.Vector3_z;
		}

		Vector3 operator+(const Vector3& adding_Target)  //adding self cloned Vector data to Target Vector
		{
			Vector3 temporary{ this->Vector3_x,this->Vector3_y, this->Vector3_z }; // Create a clone vectors from self

			temporary.Vector3_x = (temporary.Vector3_x + adding_Target.Vector3_x); // adding clone Vecotor.x to Target vector.x
			temporary.Vector3_y = (temporary.Vector3_y + adding_Target.Vector3_y); // adding clone Vecotor.x to Target vector.y
			temporary.Vector3_z = (temporary.Vector3_z + adding_Target.Vector3_z); // adding clone Vecotor.x to Target vector.z


			return temporary; // return the three added vector values.    
		}

		Vector3 operator+(const float Target_float)  //adding  self cloned Vector data to Target float
		{
			Vector3 temporary = *this; // adding a clone vectors from self

			temporary.Vector3_x += Target_float; // adding clone Vecotor.x to float
			temporary.Vector3_y += Target_float; // adding clone Vecotor.x to float
			temporary.Vector3_z += Target_float; // adding clone Vecotor.x to float


			return temporary; // return the three divided vector values.    
		}

		Vector3 operator-(const Vector3& subtracking_Target)  //subtracking self cloned Vector data to Target Vector
		{
			Vector3 temporary{ this->Vector3_x,this->Vector3_y, this->Vector3_z }; // Create a clone vectors from self

			temporary.Vector3_x = (temporary.Vector3_x - subtracking_Target.Vector3_x); // subtracking clone Vecotor.x to Target vector.x
			temporary.Vector3_y = (temporary.Vector3_y - subtracking_Target.Vector3_y); // subtracking clone Vecotor.x to Target vector.y
			temporary.Vector3_z = (temporary.Vector3_z - subtracking_Target.Vector3_z); // subtracking clone Vecotor.x to Target vector.z


			return temporary; // return the three subtracked vector values.    
		}
		Vector3 operator-(const float Target_float)  //subtracking  self cloned Vector data to Target float
		{
			Vector3 temporary = *this; // subtracking a clone vectors from self

			temporary.Vector3_x -= Target_float; // subtracking clone Vecotor.x to float
			temporary.Vector3_y -= Target_float; // subtracking clone Vecotor.x to float
			temporary.Vector3_z -= Target_float; // subtracking clone Vecotor.x to float


			return temporary; // return the three divided vector values.    
		}

		Vector3 operator*(const Vector3& multiplying_Target)  //multiplying  self cloned Vector data to Target Vector
		{
			Vector3 temporary{ this->Vector3_x,this->Vector3_y, this->Vector3_z }; // Create a clone vectors from self

			temporary.Vector3_x = (temporary.Vector3_x * multiplying_Target.Vector3_x); // multiplying clone Vecotor.x to Target vector.x
			temporary.Vector3_y = (temporary.Vector3_y * multiplying_Target.Vector3_y); // multiplying clone Vecotor.x to Target vector.y
			temporary.Vector3_z = (temporary.Vector3_z * multiplying_Target.Vector3_z); // multiplying clone Vecotor.x to Target vector.z


			return temporary; // return the three multiplied vector values.    
		}

		Vector3 operator*(const float Target_float)  //multiplying  self cloned Vector data to Target float
		{
			Vector3 temporary = *this; // Create a clone vectors from self

			temporary.Vector3_x *= Target_float; // multiplying clone Vecotor.x to float
			temporary.Vector3_y *= Target_float; // multiplying clone Vecotor.x to float
			temporary.Vector3_z *= Target_float; // multiplying clone Vecotor.x to float


			return temporary; // return the three divided vector values.    
		}

		Vector3 operator/(const Vector3& dividing_Target)  //dividing  self cloned Vector data to Target Vector
		{
			Vector3 temporary{ this->Vector3_x,this->Vector3_y, this->Vector3_z }; // Create a clone vectors from self

			temporary.Vector3_x = (temporary.Vector3_x / dividing_Target.Vector3_x); // dividing clone Vecotor.x to Target vector.x
			temporary.Vector3_y = (temporary.Vector3_y / dividing_Target.Vector3_y); // dividing clone Vecotor.x to Target vector.y
			temporary.Vector3_z = (temporary.Vector3_z / dividing_Target.Vector3_z); // dividing clone Vecotor.x to Target vector.z


			return temporary; // return the three divided vector values.    
		}

		Vector3 operator/(const float Target_float)  //dividing  self cloned Vector data to Target float
		{
			Vector3 temporary = *this; // Create a clone vectors from self

			temporary.Vector3_x /= Target_float; // dividing clone Vecotor.x to float
			temporary.Vector3_y /= Target_float; // dividing clone Vecotor.x to float
			temporary.Vector3_z /= Target_float; // dividing clone Vecotor.x to float


			return temporary; // return the three divided vector values.    
		}

		bool operator==(const Vector3& Testing_Vector3)  //dividing  self cloned Vector data to Target float
		{
			Vector3 temporary = *this; // Create a clone vectors from self
			bool result = false;

			if ((temporary.Vector3_x == Testing_Vector3.Vector3_x) && (temporary.Vector3_y == Testing_Vector3.Vector3_y) && (temporary.Vector3_z == Testing_Vector3.Vector3_z))
			{
				result = true;
			}

			return  result; // return the three divided vector values.    
		}

		Vector3 operator=(const Vector3& Rhs_Vector)  //  updating
		{
			Vector3_x = Rhs_Vector.Vector3_x;
			Vector3_y = Rhs_Vector.Vector3_y;
			Vector3_z = Rhs_Vector.Vector3_z;

			return *this; // return the three divided vector values.    
		}

		void display() // display the three Vector vlaues
		{
			cout << Vector3::Vector3_x << endl;
			cout << Vector3::Vector3_y << endl;
			cout << Vector3::Vector3_z << endl;
			cout << endl;
		}

		~Vector3()  // deconstrucker 
		{

		}
    };
}