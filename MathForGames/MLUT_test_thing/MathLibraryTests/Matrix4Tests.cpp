#include "CppUnitTest.h"
#include "TestToString.h"

//#include "Utils.h"
#include "Matrix4.h"

#include <array>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using ::MathLibrary::Float_Matrix4_Struct;




using Matrix4x4 = std::array<float, 16>;  // Column-major
using Vector4x = std::array<float, 4>;     // Homogeneous vector

// Access element at (row, col)
constexpr float get(const Matrix4x4& m, int row, int col) {
	return m[col * 4 + row];  // Column-major indexing
}

// Set element at (row, col)
constexpr void set(Matrix4x4& m, int row, int col, float value) {
	m[col * 4 + row] = value;
}

// Multiply two column-major 4x4 matrices
constexpr Matrix4x4 multiply(const Matrix4x4& A, const Matrix4x4& B) {
	Matrix4x4 result{};

	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			float sum = 0.0f;
			for (int k = 0; k < 4; ++k) {
				sum += get(A, row, k) * get(B, k, col);
			}
			set(result, row, col, sum);
		}
	}

	return result;
}

constexpr Vector4x multiply(const Matrix4x4& m, const Vector4x& v) {
	Vector4x result{};
	for (int row = 0; row < 4; ++row) {
		float sum = 0.0f;
		for (int k = 0; k < 4; ++k) {
			sum += get(m, row, k) * v[k];  // Multiply row of matrix by column vector
		}
		result[row] = sum;
	}
	return result;
}


namespace MathLibraryTests
{
	TEST_CLASS(Matrix4Tests)
	{
	public:
		// default constructor
		TEST_METHOD(Constructor)
		{
			Float_Matrix4_Struct mat;

			Assert::AreEqual(1.f, mat.Mat4_Local_Xaxis_x_m1);
			Assert::AreEqual(0.f, mat.Mat4_Local_Yaxis_x_m2);
			Assert::AreEqual(0.f, mat.Mat4_Local_Zaxis_x_m3);
			Assert::AreEqual(0.f, mat.Mat4_Local_Trans_axis_x_m4);

			Assert::AreEqual(0.f, mat.Mat4_Local_Xaxis_y_m5);
			Assert::AreEqual(1.f, mat.Mat4_Local_Yaxis_y_m6);
			Assert::AreEqual(0.f, mat.Mat4_Local_Zaxis_y_m7);
			Assert::AreEqual(0.f, mat.Mat4_Local_Trans_axis_y_m8);

			Assert::AreEqual(0.f, mat.Mat4_Local_Xaxis_z_m9);
			Assert::AreEqual(0.f, mat.Mat4_Local_Yaxis_z_m10);
			Assert::AreEqual(1.f, mat.Mat4_Local_Zaxis_z_m11);
			Assert::AreEqual(0.f, mat.Mat4_Local_Trans_axis_z_m12);

			Assert::AreEqual(0.f, mat.Mat4_place_Holder_w_m13);
			Assert::AreEqual(0.f, mat.Mat4_place_Holder_w_m14);
			Assert::AreEqual(0.f, mat.Mat4_place_Holder_w_m15);
			Assert::AreEqual(1.f, mat.Mat4_Point_Or_Vector_m16);
		}
		// parameterized constructor (individual)
		TEST_METHOD(ConstructorParamFloats)
		{
			Float_Matrix4_Struct mat{
				1.f, 2.f, 3.f,4.f,
				5.f, 6.f,7.f, 8.f,
				9.f,10.f,11.f,12.f,
				13.f,14.f,15.f,16.f
			};

			Assert::AreEqual(1.f,  mat.Mat4_Local_Xaxis_x_m1);
			Assert::AreEqual(2.f,  mat.Mat4_Local_Yaxis_x_m2);
			Assert::AreEqual(3.f,  mat.Mat4_Local_Zaxis_x_m3);
			Assert::AreEqual(4.f,  mat.Mat4_Local_Trans_axis_x_m4);
			Assert::AreEqual(5.f,  mat.Mat4_Local_Xaxis_y_m5);
			Assert::AreEqual(6.f,  mat.Mat4_Local_Yaxis_y_m6);
			Assert::AreEqual(7.f,  mat.Mat4_Local_Zaxis_y_m7);
			Assert::AreEqual(8.f,  mat.Mat4_Local_Trans_axis_y_m8);
			Assert::AreEqual(9.f,  mat.Mat4_Local_Xaxis_z_m9);
			Assert::AreEqual(10.f, mat.Mat4_Local_Yaxis_z_m10);
			Assert::AreEqual(11.f, mat.Mat4_Local_Zaxis_z_m11);
			Assert::AreEqual(12.f, mat.Mat4_Local_Trans_axis_z_m12);
			Assert::AreEqual(13.f, mat.Mat4_place_Holder_w_m13);
			Assert::AreEqual(14.f, mat.Mat4_place_Holder_w_m14);
			Assert::AreEqual(15.f, mat.Mat4_place_Holder_w_m15);
			Assert::AreEqual(16.f, mat.Mat4_Point_Or_Vector_m16);
		}
		TEST_METHOD(CopyConstructor)
		{
			Float_Matrix4_Struct mat{
				1.f, 2.f, 3.f, 4.f,
				5.f, 6.f, 7.f, 8.f,
				9.f, 10.f, 11.f, 12.f,
				13.f, 14.f, 15.f, 16.f
		};

			Float_Matrix4_Struct other = mat;

			Assert::AreEqual(1.f, mat.Mat4_Local_Xaxis_x_m1);
			Assert::AreEqual(2.f, mat.Mat4_Local_Yaxis_x_m2);
			Assert::AreEqual(3.f, mat.Mat4_Local_Zaxis_x_m3);
			Assert::AreEqual(4.f, mat.Mat4_Local_Trans_axis_x_m4);
			Assert::AreEqual(5.f, mat.Mat4_Local_Xaxis_y_m5);
			Assert::AreEqual(6.f, mat.Mat4_Local_Yaxis_y_m6);
			Assert::AreEqual(7.f, mat.Mat4_Local_Zaxis_y_m7);
			Assert::AreEqual(8.f, mat.Mat4_Local_Trans_axis_y_m8);
			Assert::AreEqual(9.f, mat.Mat4_Local_Xaxis_z_m9);
			Assert::AreEqual(10.f, mat.Mat4_Local_Yaxis_z_m10);
			Assert::AreEqual(11.f, mat.Mat4_Local_Zaxis_z_m11);
			Assert::AreEqual(12.f, mat.Mat4_Local_Trans_axis_z_m12);
			Assert::AreEqual(13.f, mat.Mat4_place_Holder_w_m13);
			Assert::AreEqual(14.f, mat.Mat4_place_Holder_w_m14);
			Assert::AreEqual(15.f, mat.Mat4_place_Holder_w_m15);
			Assert::AreEqual(16.f, mat.Mat4_Point_Or_Vector_m16);
		}

		// mat3 * vec
		TEST_METHOD(TransformVec3)
		{
			Float_Matrix4_Struct m3b{
				-0.188076824f, 0.f, 0.982154310f,0.f,
				0.f, 1.f, 0.f,0.f,
				-0.982154310f, 0.f, -0.188076824f,0.f,
				3.f,0.f,0.f,1.f
			};

			Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f,1.f);

			Assert::AreEqual(Approximate(Float_Vector4_Struct(-846.15607f, -48.23f, -148.863144f,1.0f)) , Approximate(m3b*v3a));
		}
		// mat3 * mat3
		TEST_METHOD(Multiply)
		{
			Float_Matrix4_Struct m3a{
				1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8
		};

			Float_Matrix4_Struct m3c{
				4, 6, 4, 5,
				5, 6, 6, 4,
				5, 10, -9, -3,
				2, -12, -7, 3
			};

			constexpr auto mv = multiply(Matrix4x4{
				1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8
				}, Matrix4x4{
							4, 6, 4, 5,
							5, 6, 6, 4,
							5, 10, -9, -3,
							2, -12, -7, 3
				});

			//Returned value is correct
			Assert::AreEqual(Approximate(Float_Matrix4_Struct{ 38, 54,51,70,43,65,49,72,-8,-16,11,-40,-37,-47,-26,-12 }), Approximate(m3a * m3c));

			//Original is unchanged
			Assert::AreEqual(Float_Matrix4_Struct{ 1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8 }, m3a);
		}
		TEST_METHOD(MultiplyAssignment)
		{
			Float_Matrix4_Struct m3a{
				1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8 };

			Float_Matrix4_Struct m3c{
				4, 6, 4, 5,
				5, 6, 6, 4,
				5, 10, -9, -3,
				2, -12, -7, 3
			};

			//*= returns new value
			Assert::AreEqual(Float_Matrix4_Struct{ 38, 54,51,70,43,65,49,72,-8,-16,11,-40,-37,-47,-26,-12 } , m3a *= m3c);

			//original has changed
			Assert::AreNotEqual(Float_Matrix4_Struct{
				1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8 }, m3a);
		}

		TEST_METHOD(Equality)
		{
			Float_Matrix4_Struct m3a{ 38, 54, 51, 70, 43, 65, 49, 72, -8, -16, 11, -40, -37, -47, -26, -12 };
			Float_Matrix4_Struct m3b{ 38, 54, 51, 70, 43, 65, 49, 72, -8, -16, 11, -40, -37, -47, -26, -12 };


			//*= returns new value
			Assert::AreEqual(m3a,m3b);

			//original has changed
			Assert::AreNotEqual(Float_Matrix4_Struct{ 1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8 }, m3a);
		}


		TEST_METHOD(Subscript) {
			Float_Matrix4_Struct m3a{
				1, 3, 1, 2,
				2, 2, 3, 1,
				3, 5, 1, 4,
				2, 2, 5, 8
			};

			Assert::AreEqual(m3a[0], 1.f);
			Assert::AreEqual(m3a[1], 3.f);
			Assert::AreEqual(m3a[2], 1.f);
			Assert::AreEqual(m3a[3], 2.f);

			Assert::AreEqual(m3a[4], 2.f);
			Assert::AreEqual(m3a[5], 2.f);
			Assert::AreEqual(m3a[6], 3.f);
			Assert::AreEqual(m3a[7], 1.f);

			Assert::AreEqual(m3a[8], 3.f);
			Assert::AreEqual(m3a[9], 5.f);
			Assert::AreEqual(m3a[10], 1.f);
			Assert::AreEqual(m3a[11], 4.f);

			Assert::AreEqual(m3a[12], 2.f);
			Assert::AreEqual(m3a[13], 2.f);
			Assert::AreEqual(m3a[14], 5.f);
			Assert::AreEqual(m3a[15], 8.f);
		}

		TEST_METHOD(SubscriptReference) {
			Float_Matrix4_Struct m3a; //Identity

			m3a[0] = 1.f;
			m3a[1] = 4.f;
			m3a[2] = 1.f;
			m3a[3] = 2.f;
			m3a[4] = 3.f;
			m3a[5] = 2.f;
			m3a[6] = 3.f;
			m3a[7] = 2.f;
			m3a[8] = 0.f;
			m3a[9] = 3.f;
			m3a[10] = 2.f;
			m3a[11] = 0.f;
			m3a[12] = 1.f;
			m3a[13] = 3.f;
			m3a[14] = 2.f;
			m3a[15] = 3.f;

			Assert::AreEqual(
				Float_Matrix4_Struct{
					1.f, 4.f, 1.f, 2.f,
					3.f, 2.f, 3.f, 2.f,
					0.f, 3.f, 2.f, 0.f,
					1.f, 3.f, 2.f, 3.f
				}
				, m3a);

			Assert::IsTrue(
				m3a.Mat4_Local_Xaxis_x_m1 == 1.f && m3a.Mat4_Local_Yaxis_x_m2 == 4.f && m3a.Mat4_Local_Zaxis_x_m3 == 1.f && m3a.Mat4_Local_Trans_axis_x_m4 == 2.f &&
				m3a.Mat4_Local_Xaxis_y_m5 == 3.f && m3a.Mat4_Local_Yaxis_y_m6 == 2.f && m3a.Mat4_Local_Zaxis_y_m7 == 3.f && m3a.Mat4_Local_Trans_axis_y_m8 == 2.f &&
				m3a.Mat4_Local_Xaxis_z_m9 == 0.f && m3a.Mat4_Local_Yaxis_z_m10 == 3.f && m3a.Mat4_Local_Zaxis_z_m11 == 2.f && m3a.Mat4_Local_Trans_axis_z_m12 == 0.f &&
				m3a.Mat4_place_Holder_w_m13 == 1.f && m3a.Mat4_place_Holder_w_m14 == 3.f && m3a.Mat4_place_Holder_w_m15 == 2.f && m3a.Mat4_Point_Or_Vector_m16 == 3.f
			);
		}

		TEST_METHOD(MakeRotateX)
		{
			Float_Matrix4_Struct actual = Float_Matrix4_Struct::MakeRotate_X(3.98f);

			Assert::AreEqual(
				Approximate(
					Float_Matrix4_Struct{
						1, 0, 0, 0,
						0, -0.668648f, 0.743579f, 0,
						0, -0.743579f, -0.668648f, 0,
						0, 0, 0, 1 }
				), Approximate(actual) );
		}
		// make rotY from float
		TEST_METHOD(MakeRotateY)
		{
			Float_Matrix4_Struct actual = Float_Matrix4_Struct::MakeRotate_Y(1.76f);

            Assert::AreEqual(
				Approximate(Float_Matrix4_Struct{
					-0.188077f, 0, 0.982154f, 0,
					0, 1, 0, 0,
					-0.982154f, 0, -0.188077f, 0,
					0, 0, 0, 1}
                ),
                Approximate(actual));
		}
		// make rotZ from float
		TEST_METHOD(MakeRotateZ)
		{
			Float_Matrix4_Struct actual = Float_Matrix4_Struct::MakeRotate_Z(9.62f);

			Assert::AreEqual(
				Approximate(Float_Matrix4_Struct{
					-0.981005f, -0.193984f, 0,0,
					0.193984f, -0.981005f, 0,0,
					0, 0, 1,0,
					0,0,0,1 }),
				Approximate(actual));
		}
		// make scale from float
		TEST_METHOD(MakeScale)
		{
			Float_Matrix4_Struct actual = Float_Matrix4_Struct::MakeScale(2.0f,2.0f,2.0f);

			Assert::AreEqual(
				Float_Matrix4_Struct{
					2.f, 0, 0,0,
					0, 2.f, 0,0,
					0, 0, 2.f,0,
					0,0,0,1.f },
				actual);
		}

		TEST_METHOD(MakeTranslation)
		{
			Float_Matrix4_Struct actual = Float_Matrix4_Struct::MakeTranslate(2.0f, 3.0f, 4.0f);

			Assert::AreEqual(
				Float_Matrix4_Struct{ 1, 0, 0, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					2.f, 3.f, 4.f, 1 }, actual);
		}

		TEST_METHOD(GetForward)
		{
			Float_Matrix4_Struct actual = Float_Matrix4_Struct::MakeRotate_X(3.98f);
			Assert::AreEqual(Approximate(Float_Vector4_Struct(0, -0.743579f, -0.668648f, 0)), Approximate(actual.GetForward_Z()));
		}
		TEST_METHOD(GetRight)
		{
			Float_Matrix4_Struct actual = Float_Matrix4_Struct::MakeRotate_Y(1.76f);
			Assert::AreEqual(Approximate(Float_Vector4_Struct(-0.188077f, 0, 0.982154f, 0)), Approximate(actual.GetRight_X()));
		}
		TEST_METHOD(GetUp)
		{
			Float_Matrix4_Struct actual = Float_Matrix4_Struct::MakeRotate_Z(9.62f);
			Assert::AreEqual(Approximate(Float_Vector4_Struct(0.193984f, -0.981005f, 0, 0)), Approximate(actual.GetUp_Y()));
		}

		TEST_METHOD(IsApproximatelyEqual)
		{
			Float_Matrix4_Struct actual{ 1.00001f, 2.00001f, 3.00001f, 4.00001f, 5.00001f, 6.00001f, 7.00001f, 8.00001f, 9.00001f,10.00001f,11.000f,12.000f,13.000f,14.000f,15.000f,16.000f };
			Assert::IsTrue(actual.IsApproximatelyEqual(Float_Matrix4_Struct{ 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f,10.f,11.f,12.f,13.f,14.f,15.f,16.f }));
		}
	};
}