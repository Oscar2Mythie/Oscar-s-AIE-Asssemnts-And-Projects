/*

Created by Oscar crowley 18/03/2025. Last updated on the 25/03/2026

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

	float& operator[](const int Return_Vector_value)  //dividing  self cloned Vector data to Target float
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

	 bool operator<(const Float_Vector3_Struct& Testing_Vector3)  //Testing  Vector data see if it matches Testing_Vector3 
	 {
		 Float_Vector3_Struct temporary_squraed = *this * (*this); // Create a squared clone vectors from self
		 Float_Vector3_Struct Testing_squraed_Vector3 = Testing_Vector3;
		 Testing_squraed_Vector3 *= Testing_squraed_Vector3;

		 bool result = false; // defaults to No it dose not match

		 if (temporary_squraed < Testing_squraed_Vector3) 
		 {
			 result = true;
		 }

		 return  result; // return either true or false   
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


	bool operator==(const Float_Vector4_Struct& Testing_Vector4)  //Testing  Vector data see if it matches Testing_Vector3 
	{
		Float_Vector4_Struct temporary = *this; // Create a clone vectors from self
		bool result = false; // defaults to No it dose not match

		if ((temporary.Vector4_x == Testing_Vector4.Vector4_x) && (temporary.Vector4_y == Testing_Vector4.Vector4_y) && (temporary.Vector4_z == Testing_Vector4.Vector4_z))
		{
			result = true; // sets to true when vectors match
		}

		return  result; // return either true or false   
	}

	bool operator!=(const Float_Vector4_Struct& Testing_Vector4)  //Testing  Vector data see if it matches Testing_Vector3 
	{
		Float_Vector4_Struct temporary = *this; // Create a clone vectors from self
		bool result = true; // defaults to No it dose not match

		if ((temporary.Vector4_x == Testing_Vector4.Vector4_x) && (temporary.Vector4_y == Testing_Vector4.Vector4_y) && (temporary.Vector4_z == Testing_Vector4.Vector4_z))
		{
			result = false; // sets to false when vectors match
		}

		return  result; // return either true or false   
	}

	bool operator<(const Float_Vector4_Struct& Testing_Vector4)  //Testing  Vector data see if it matches Testing_Vector3 
	{
		Float_Vector4_Struct temporary = *this; // Create a clone vectors from self
		bool result = false; // defaults to No it dose not match

		temporary.Vector4_x = temporary.Vector4_x * temporary.Vector4_x;
		temporary.Vector4_y = temporary.Vector4_y * temporary.Vector4_y;
		temporary.Vector4_z = temporary.Vector4_z * temporary.Vector4_z;

		return  result; // return either true or false   
	}

	Float_Vector4_Struct operator=(const Float_Vector4_Struct& Rhs_Vector)  //  Assigning New vector values from another vector
	{
		Vector4_x = Rhs_Vector.Vector4_x;
		Vector4_y = Rhs_Vector.Vector4_y;
		Vector4_z = Rhs_Vector.Vector4_z;

		return *this; // return the three new vector values.    
	}

	Float_Vector4_Struct operator-()  //  making the Vectors swhich from postive to negtive
	{
		Vector4_x *= -1;
		Vector4_y *= -1;
		Vector4_z *= -1;

		return *this; // return the three updated vector values.    
	}

	void display() // display the three Vector vlaues
	{
		cout << Float_Vector4_Struct::Vector4_x << endl;
		cout << Float_Vector4_Struct::Vector4_y << endl;
		cout << Float_Vector4_Struct::Vector4_z << endl;
		cout << endl;
	}

	~Float_Vector4_Struct()  // deconstrucker 
	{

	}
};

int main() 
{
	Float_Vector3_Struct First_Vector(2, 4, 6), Second_Vector(1,3,5);
	Float_Vector3_Struct Current_Vector = First_Vector + Second_Vector;

	Float_Vector3_Struct Copy_vector = First_Vector;
	Copy_vector.display();

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

	Current_Vector = First_Vector;
	Current_Vector.display();

	if (Current_Vector == First_Vector) 
	{
		cout << "Current_Vector Matches First_Vector" << endl;
	}

	Current_Vector = -Current_Vector;
	Current_Vector.display();

	if (Current_Vector < Second_Vector) 
	{
		cout << "Current_Vector is less then Second_Vector" << endl;
	}
}