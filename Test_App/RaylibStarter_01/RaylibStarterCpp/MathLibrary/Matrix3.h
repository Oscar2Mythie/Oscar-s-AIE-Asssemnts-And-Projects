#pragma once

namespace MathLibrary
{
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
			for (int loopCount = 0; loopCount < 9; loopCount++) //
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

		Float_Matrix3_Struct(initializer_list<float> Mat3_V_list)  // allows the Matrix3 to take a list of values and asagin them into the each value slot 
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

		Float_Vector3_Struct operator*(const Float_Vector3_Struct& Rhs_Float_Vector3_Struct) const // multiply the matrix3 by Vector3
		{
			Float_Vector3_Struct tempary_Float_Vector3 = Rhs_Float_Vector3_Struct;

			Float_Vector3_Struct tempary_Blank_Vector3;

			float Add_muilt_holder = 0;

			for (int X_Loop = 0; X_Loop < 3; X_Loop++)
			{
				for (int Y_loop = 0; Y_loop < 3; Y_loop++)
				{
					Add_muilt_holder += tempary_Float_Vector3[Y_loop] * Mat3_grid[Y_loop][X_Loop];
				}

				tempary_Blank_Vector3[X_Loop] = Add_muilt_holder;

				Add_muilt_holder = 0;
			}
			return tempary_Blank_Vector3;
		}

		Float_Matrix3_Struct operator*(const Float_Matrix3_Struct& Rhs_Matrix3) const // multiply the matrix3 by matrix3
		{

			Float_Matrix3_Struct result_Matrix;

			for (int X_Loop = 0; X_Loop < 3; X_Loop++)
			{
				for (int Y_loop = 0; Y_loop < 3; Y_loop++)
				{
					float muitply_Sum = 0;
					for (int add_loop = 0; add_loop < 3; add_loop++)
					{
						muitply_Sum = muitply_Sum + (Mat3_grid[add_loop][Y_loop] * Rhs_Matrix3.Mat3_grid[X_Loop][add_loop]);
					}
					result_Matrix.Mat3_grid[X_Loop][Y_loop] = muitply_Sum;
				}
			}

			return result_Matrix;
		}

		Float_Matrix3_Struct operator*=(const Float_Matrix3_Struct& Rhs_Matrix3) // multiply the matrix3 by matrix3 and assigning
		{
			*this = *this * Rhs_Matrix3;

			return *this;
		}

		bool operator==(const Float_Matrix3_Struct& Rhs_Matrix3) const// testting if matrix3 dose match another matrix3
		{
			Float_Matrix3_Struct tempary_Float_Diffrence = *this;
			int  Match_Count = 0;

			for (int Loop = 0; Loop < 9; Loop++)
			{
				if (tempary_Float_Diffrence.Mat3_Array[Loop] == Rhs_Matrix3.Mat3_Array[Loop])
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

		float operator[](const int& index_of_matrix) const // Calls A element value of the matrix3
		{
			return Mat3_Array[index_of_matrix];
		}

		float &operator[](const int& index_of_matrix) // Calls A element value of the matrix3
		{
			return Mat3_Array[index_of_matrix];
		}

		// *** /\/\/\ Over loading Matrix3's /\/\/\ ***

		// *** \/\/\/ Member functions for Matrix3's \/\/\/ ***
		static Float_Matrix3_Struct MakeRotate_2D(float a)  // create a matrix3 with Rotate values 
		{
			return
			{
				cos(a), sin(a),0,
				-sin(a), cos(a),0,
				0,0,1
			};
		}

		static Float_Matrix3_Struct MakeScale(float Scale_X, float Scale_Y) // make an Matrix3 for a scale in 2d
		{
			return
			{
				Scale_X, 0, 0,
				0, Scale_Y, 0,
				0, 0, 1
			};
		}

		Float_Matrix3_Struct MakeTranslate(Float_Vector3_Struct& Rhs_Vector3) // make an Matrix3 with an Translate of an object
		{
			return Float_Matrix3_Struct
			{
				0,0,Rhs_Vector3.Vector3_x,
				0,0,Rhs_Vector3.Vector3_y,
				0,0,1
			};
		}

		Float_Vector3_Struct GetTanslate() // Get the values from the bottom row
		{
			return Float_Vector3_Struct(Mat3_grid[2][0], Mat3_grid[2][1], Mat3_grid[2][2]);
		}

		Float_Vector3_Struct GetRight_Y()  // get the values from the middle row
		{
			return Float_Vector3_Struct(Mat3_grid[1][0], Mat3_grid[1][1], Mat3_grid[1][2]);
		}

		Float_Vector3_Struct GetForward_X() // get the values from the top row 
		{
			return Float_Vector3_Struct(Mat3_grid[0][0], Mat3_grid[0][1], Mat3_grid[0][2]);
		}

		bool IsApproximatelyEqual(const Float_Matrix3_Struct& Rhs_Matrix3, float equal_within_value = 1e-4) const // test this matrix3 with another matrix3 and see if they are equal with each other within range of diffencet   
		{
			Float_Matrix3_Struct tempary_Float_Matrix3_Diffrence = *this; // grabs this Vector values

			for (int Loop = 0; Loop < 9; Loop++)  // loop thought all the elements of the two Matrix3's 
			{
				if ((tempary_Float_Matrix3_Diffrence[Loop] - Rhs_Matrix3[Loop]) < equal_within_value && (tempary_Float_Matrix3_Diffrence[Loop] - Rhs_Matrix3[Loop]) > -equal_within_value) // inside of the target range?
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

}