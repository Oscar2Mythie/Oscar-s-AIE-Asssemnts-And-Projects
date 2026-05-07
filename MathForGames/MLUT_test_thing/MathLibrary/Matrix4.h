#pragma once

namespace MathLibrary
{
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

			Float_Vector4_Struct tempary_Blank_Vector4;

			float Add_muilt_holder = 0;

			for (int X_Loop = 0; X_Loop < 4; X_Loop++)
			{
				for (int Y_loop = 0; Y_loop < 4; Y_loop++)
				{
					Add_muilt_holder += tempary_Float_Vector4[Y_loop] * Mat4_grid[Y_loop][X_Loop];
				}

				tempary_Blank_Vector4[X_Loop] = Add_muilt_holder;

				Add_muilt_holder = 0;
			}

			return tempary_Blank_Vector4;
		}

		Float_Matrix4_Struct operator*(const Float_Matrix4_Struct& Rhs_Matrix4) const // multiply the matrix4 by matrix4
		{
			Float_Matrix4_Struct result_Matrix;

			for (int X_Loop = 0; X_Loop < 4; X_Loop++)
			{
				for (int Y_loop = 0; Y_loop < 4; Y_loop++)
				{
					float muitply_Sum = 0;
					for (int add_loop = 0; add_loop < 4; add_loop++)
					{
						muitply_Sum = muitply_Sum + (Mat4_grid[add_loop][Y_loop] * Rhs_Matrix4.Mat4_grid[X_Loop][add_loop]);
					}
					result_Matrix.Mat4_grid[X_Loop][Y_loop] = muitply_Sum;
				}
			}

			return result_Matrix;
		}

		Float_Matrix4_Struct operator*=(const Float_Matrix4_Struct& Rhs_Matrix4) // multiply the matrix3 by matrix3 and assigning
		{
			*this = *this * Rhs_Matrix4;

			return *this;
		}

		bool operator==(const Float_Matrix4_Struct& Rhs_Matrix4) const// testting if matrix3 dose match another matrix3
		{
			
			Float_Matrix4_Struct Temporary_Matrix4 = *this;

			for (int Loop = 0; Loop < 16; Loop++)
			{
				if (Temporary_Matrix4.Mat4_Array[Loop] == Rhs_Matrix4.Mat4_Array[Loop])
				{
					
				}
				else
				{
					return false;
				}
			}

			return true;
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

		float operator[](const int& index_of_matrix) const// Calls A element value of the matrix3
		{
			return Mat4_Array[index_of_matrix];
		}

		float& operator[](const int& index_of_matrix) // Calls A element value of the matrix3
		{
			return Mat4_Array[index_of_matrix];
		}

		// *** /\/\/\ Over loading Matrix4's /\/\/\ ***

		// *** \/\/\/ Member functions for Matrix4's \/\/\/ ***

		static Float_Matrix4_Struct MakeRotate_X(float a) // create a Rotation matrix4 for roating on the X axis
		{
			return
			{
				1,	0,	0,0,
				0, cosf(a), -sinf(a),0,
				0, sinf(a), cosf(a),0,
				0,0,0,1
			};
		}

		static Float_Matrix4_Struct MakeRotate_Y(float a) // create a Rotation matrix4 for roating on the Y axis
		{
			return
			{
				cosf(a), 0, sinf(a),0,
					0,	 1,		0,0,
				-sinf(a), 0, cosf(a),0,
				0,0,0,1
			};
		}

		static Float_Matrix4_Struct MakeRotate_Z(float a) // create a Rotation matrix4 for roating on the Z axis
		{
			return
			{
				cosf(a),sinf(a), 0,0,
				-sinf(a),cosf(a),0,0,
				0,0,1,0,
				0,0,0,1
			};
		}

		static Float_Matrix4_Struct Euler_Rotate(float Pitch_X, float Yaw_Y, float roll_Z) // Create 3 matrix4 for each of the axis's, then return the product of the three matrix4. 
		{
			Float_Matrix4_Struct X = MakeRotate_X(Pitch_X);
			Float_Matrix4_Struct Y = MakeRotate_Y(Yaw_Y);
			Float_Matrix4_Struct Z = MakeRotate_Z(roll_Z);

			return (Z * Y * X);
		}

		static Float_Matrix4_Struct MakeScale(float Scale_X, float Scale_Y, float Scale_Z) // Make an Matrix4 with values for scaling. 
		{
			return
			{
				Scale_X, 0, 0,0,
				0, Scale_Y, 0,0,
				0, 0, Scale_Z,0,
				0, 0, 0, 1
			};
		}

		Float_Vector4_Struct GetRight_X() // return a vector with values from the left column of this mattrix
		{
			return Float_Vector4_Struct(Mat4_grid[0][0], Mat4_grid[0][1], Mat4_grid[0][2], Mat4_grid[0][3]);
		}

		Float_Vector4_Struct GetUp_Y() // return a vector with values from the left-middle column of this mattrix
		{
			return Float_Vector4_Struct(Mat4_grid[1][0], Mat4_grid[1][1], Mat4_grid[1][2], Mat4_grid[1][3]);
		}

		Float_Vector4_Struct GetForward_Z() // return a vector with values from the right-middle column of this mattrix
		{
			return Float_Vector4_Struct(Mat4_grid[2][0], Mat4_grid[2][1], Mat4_grid[2][2], Mat4_grid[2][3]);
		}

		Float_Vector4_Struct GetPosition_W() // return a vector with values from the right column of this mattrix
		{
			return Float_Vector4_Struct(Mat4_grid[0][3], Mat4_grid[1][3], Mat4_grid[2][3], Mat4_grid[3][3]);
		}

		bool IsApproximatelyEqual(const Float_Matrix4_Struct& Rhs_Matrix4, float equal_within_value = 1e-4) const //
		{
			Float_Matrix4_Struct tempary_Float_Matrix4_Diffrence = *this; // test this matrix4 with another matrix4 and see if they are equal with each other within range of diffencet 

			for (int Loop = 0; Loop < 16; Loop++) // loop though all the elmemnts of the matrix4 and compaire the diffrance between them. if the diffrance is within equal_within_value range, return true.
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

		Float_Matrix4_Struct SetTranslate(Float_Vector4_Struct& Rhs_Vector) // update the right column with values from an translate vector4
		{
			Float_Matrix4_Struct tempary_Float_Matrix4 = *this;

			Mat4_grid[0][3] = Rhs_Vector.Vector4_x;
			Mat4_grid[1][3] = Rhs_Vector.Vector4_y;
			Mat4_grid[2][3] = Rhs_Vector.Vector4_z;

			return *this;
		}

		static Float_Matrix4_Struct MakeTranslate(Float_Vector4_Struct& Rhs_Vector)  // Make an Matrix4 with an vector 4 data save in the right column
		{
			Float_Matrix4_Struct tempary_Float_Matrix4;

			tempary_Float_Matrix4.Mat4_grid[3][0] = Rhs_Vector.Vector4_x;
			tempary_Float_Matrix4.Mat4_grid[3][1] = Rhs_Vector.Vector4_y;
			tempary_Float_Matrix4.Mat4_grid[3][2] = Rhs_Vector.Vector4_z;
			tempary_Float_Matrix4.Mat4_grid[3][3] = Rhs_Vector.Vector4_w;

			return tempary_Float_Matrix4;
		}

		static Float_Matrix4_Struct MakeTranslate(float x, float y, float z)  // Make an Matrix4 with floats 3 data save in the right column
		{
			Float_Matrix4_Struct tempary_Float_Matrix4;

			tempary_Float_Matrix4.Mat4_grid[3][0] = x;
			tempary_Float_Matrix4.Mat4_grid[3][1] = y;
			tempary_Float_Matrix4.Mat4_grid[3][2] = z;
			tempary_Float_Matrix4.Mat4_grid[3][3] = 1;


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
}