/*

Created by Oscar crowley 18/03/2025. Last updated on the 1/04/2026

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

	void display() // display the three Vector vlaues
	{
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

	Float_Matrix3_Struct(Float_Matrix3_Struct& Copy_Matrix3_Struct) // copy constructor
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
		
		for (int X_Loop = 0; X_Loop < 3; X_Loop++)
		{
			for (int Y_loop = 0; Y_loop < 3; Y_loop++)
			{
				tempary_Float_Vector3[Y_loop] *= Mat3_grid[X_Loop][Y_loop];
			}
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

void Vector3_Overloaded(Float_Vector3_Struct First_Vector3, Float_Vector3_Struct Second_Vector3) // vector3 that is Overloaded
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

	cout << "\n*** Ending Overloaded Vector 3's ***" << endl;
}

void Vector4_Overloaded(Float_Vector4_Struct First_Vector4, Float_Vector4_Struct Second_Vector4) // vector3 that is Overloaded
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
}

void Matrix3_Overloaded(Float_Matrix3_Struct First_Matrix3, Float_Matrix3_Struct Second_Matrix3, Float_Vector3_Struct First_Vector3)
{
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


}

int main() 
{
	Float_Vector3_Struct First_Vector3(2, 4, 6), Second_Vector3(1, 3, 5); // Create two New vector3

	Vector3_Overloaded(First_Vector3,Second_Vector3); // Testing Vector3 has overloaded it's operators

	Float_Vector4_Struct Third_Vector4(34, 956, 27, 65), forth_vector4(47, 42, 365, 2); // Create two new vector4

	Vector4_Overloaded(Third_Vector4, forth_vector4); // Testing Vector4 has overloaded it's operators

	Float_Matrix3_Struct First_Matrix3{1,4,3,8,2,9,0,0,1}, Second_Matrix3;

	Matrix3_Overloaded(First_Matrix3, Second_Matrix3, First_Vector3);
}