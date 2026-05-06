#include "CppUnitTest.h"
#include "TestToString.h"

#include "Matrix3.h"
#include "Vector3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ::MathLibrary;

namespace MathLibraryTests
{
	TEST_CLASS(Matrix3Tests)
	{
	public:
		// default constructor
		TEST_METHOD(Constructor)
		{
			Float_Matrix3_Struct mat;

			Assert::AreEqual(1.f, mat.Mat3_Local_Xaxis_x_m1);
			Assert::AreEqual(0.f, mat.Mat3_Local_Yaxis_x_m2);
			Assert::AreEqual(0.f, mat.Mat3_Local_Trans_axis_x_m3);

			Assert::AreEqual(0.f, mat.Mat3_Local_Xaxis_y_m4);
			Assert::AreEqual(1.f, mat.Mat3_Local_Yaxis_y_m5);
			Assert::AreEqual(0.f, mat.Mat3_Local_Trans_axis_y_m6);

			Assert::AreEqual(0.f, mat.Mat3_place_Holder_w_m7);
			Assert::AreEqual(0.f, mat.Mat3_place_Holder_w_m8);
			Assert::AreEqual(1.f, mat.Mat3_Point_Or_Vector_m9);
		}
		// parameterized constructor (individual)
		TEST_METHOD(ConstructorParamFloats)
		{
			Float_Matrix3_Struct mat{1.f, 2.f, 3.f,
				4.f, 5.f, 6.f,
				7.f, 8.f, 9.f
			};

			Assert::AreEqual(1.f, mat.Mat3_Local_Xaxis_x_m1);
			Assert::AreEqual(2.f, mat.Mat3_Local_Yaxis_x_m2);
			Assert::AreEqual(3.f, mat.Mat3_Local_Trans_axis_x_m3);
			Assert::AreEqual(4.f, mat.Mat3_Local_Xaxis_y_m4);
			Assert::AreEqual(5.f, mat.Mat3_Local_Yaxis_y_m5);
			Assert::AreEqual(6.f, mat.Mat3_Local_Trans_axis_y_m6);
			Assert::AreEqual(7.f, mat.Mat3_place_Holder_w_m7);
			Assert::AreEqual(8.f, mat.Mat3_place_Holder_w_m8);
			Assert::AreEqual(9.f, mat.Mat3_Point_Or_Vector_m9);
		}
		TEST_METHOD(CopyConstructor)
		{
			Float_Matrix3_Struct mat{ 1.f, 2.f, 3.f,
				4.f, 5.f, 6.f,
				7.f, 8.f, 9.f };

			Float_Matrix3_Struct other = mat;

			Assert::AreEqual(1.f, other.Mat3_Local_Xaxis_x_m1);
			Assert::AreEqual(2.f, other.Mat3_Local_Yaxis_x_m2);
			Assert::AreEqual(3.f, other.Mat3_Local_Trans_axis_x_m3);
			Assert::AreEqual(4.f, other.Mat3_Local_Xaxis_y_m4);
			Assert::AreEqual(5.f, other.Mat3_Local_Yaxis_y_m5);
			Assert::AreEqual(6.f, other.Mat3_Local_Trans_axis_y_m6);
			Assert::AreEqual(7.f, other.Mat3_place_Holder_w_m7);
			Assert::AreEqual(8.f, other.Mat3_place_Holder_w_m8);
			Assert::AreEqual(9.f, other.Mat3_Point_Or_Vector_m9);
		}

		// mat3 * vec
		TEST_METHOD(Assignment)
		{
			const Float_Matrix3_Struct m3a{ -0.188076824f, 0.f, 0.982154310f,
				0.f, 1.f, 0.f,
				-0.982154310f, 0.f, -0.188076824f };

			Float_Matrix3_Struct m3b;

			m3b = m3a;

			Assert::AreEqual(m3a,m3b);

			//Ensure m3a isn't changed
			Assert::AreEqual(Float_Matrix3_Struct{ -0.188076824f, 0.f, 0.982154310f, 0.f, 1.f, 0.f, -0.982154310f, 0.f, -0.188076824f }, m3a);
		}
		
		// mat3 * vec
		TEST_METHOD(TransformVec3)
		{
			const Float_Matrix3_Struct m3b{ -0.188076824f, 0.f, 0.982154310f,
				0.f, 1.f, 0.f,
				-0.982154310f, 0.f, -0.188076824f };

			const Float_Vector3_Struct v3a(13.5f, -48.23f, 862);
			const Float_Vector3_Struct v3b = m3b * v3a;

			Assert::AreEqual(Approximate(v3b),Approximate(Float_Vector3_Struct(-849.156067f, -48.23f, -148.863144f)));
		}
		// mat3 * mat3
		TEST_METHOD(Multiply)
		{
			const Float_Matrix3_Struct m3a{ 1, 3, 1, 2, 2, 2, 3, 1, 3 };
			const Float_Matrix3_Struct m3c{ 4, 6, 4, 5, 5, 6, 6, 4, 5 };

			//Returned value is correct
			Assert::AreEqual(Approximate(Float_Matrix3_Struct{ 28, 28, 28, 33, 31, 33, 29, 31, 29 }), Approximate(m3a * m3c));
			
			//Original is unchanged
			Assert::AreEqual(Float_Matrix3_Struct{ 1, 3, 1, 2, 2, 2, 3, 1, 3 }, m3a);
		}
		TEST_METHOD(MultiplyAssignment)
		{
			Float_Matrix3_Struct m3a{ 1, 3, 1, 2, 2, 2, 3, 1, 3 };
			const Float_Matrix3_Struct m3c{ 4, 6, 4, 5, 5, 6, 6, 4, 5 };

			//*= returns new value
			Assert::AreEqual(Float_Matrix3_Struct{ 28, 28, 28, 33, 31, 33, 29, 31, 29 }, m3a *= m3c);

			//original has changed
			Assert::AreNotEqual(Float_Matrix3_Struct{ 1, 3, 1, 2, 2, 2, 3, 1, 3 }, m3a);
		}
		TEST_METHOD(Equality)
		{
			const Float_Matrix3_Struct m3a{ 1, 3, 1, 2, 2, 2, 3, 1, 3 };
			const Float_Matrix3_Struct m3c{1, 3, 1, 2, 2, 2, 3, 1, 3};

			//*= returns new value
			Assert::IsTrue(m3a == m3c);
		}

		
		TEST_METHOD(Subscript) {
			Float_Matrix3_Struct m3a{ 1, 4, 1,
						2, 3, 2,
						3, 2, 3 };

			Assert::AreEqual(m3a[0], 1.f);
			Assert::AreEqual(m3a[1], 4.f);
			Assert::AreEqual(m3a[2], 1.f);
				
			Assert::AreEqual(m3a[3], 2.f);
			Assert::AreEqual(m3a[4], 3.f);
			Assert::AreEqual(m3a[5], 2.f);
				
			Assert::AreEqual(m3a[6], 3.f);
			Assert::AreEqual(m3a[7], 2.f);
			Assert::AreEqual(m3a[8], 3.f);
		}
		
		TEST_METHOD(SubscriptReference) {
			Float_Matrix3_Struct m3a; //Identity

			m3a[0]= 1.f;
			m3a[1]= 4.f;
			m3a[2]= 1.f;

			m3a[3]= 2.f;
			m3a[4]= 3.f;
			m3a[5]= 2.f;

			m3a[6]= 3.f;
			m3a[7]= 2.f;
            m3a[8]= 3.f;

			Assert::AreEqual(Float_Matrix3_Struct{ 1.f, 4.f, 1.f, 2.f, 3.f, 2.f, 3.f, 2.f, 3.f }, m3a);

			Assert::IsTrue(
				m3a.Mat3_Local_Xaxis_x_m1 == 1.f && m3a.Mat3_Local_Yaxis_x_m2 == 4.f && m3a.Mat3_Local_Trans_axis_x_m3 == 1.f &&
				m3a.Mat3_Local_Xaxis_y_m4 == 2.f && m3a.Mat3_Local_Yaxis_y_m5 == 3.f && m3a.Mat3_Local_Trans_axis_y_m6 == 2.f &&
				m3a.Mat3_place_Holder_w_m7 == 3.f && m3a.Mat3_place_Holder_w_m8 == 2.f && m3a.Mat3_Point_Or_Vector_m9 == 3.f
			);
        }

		TEST_METHOD(MakeRotate)
		{
			Float_Matrix3_Struct actual = Float_Matrix3_Struct::MakeRotate_2D(3.98f);
			constexpr auto s = 3.98f;
			auto x = cos(s) - sin(s);

			Assert::AreEqual(
				Approximate(Float_Matrix3_Struct{
					-0.668648f, -0.743579f,0,
					 0.743579f, -0.668648f,0,
					0,0,1 }),
				Approximate(actual));
		}
		
		// make scale from float
		TEST_METHOD(MakeScale)
		{
			Float_Matrix3_Struct actual = Float_Matrix3_Struct::MakeScale(2.0f,2.0f);

			Assert::AreEqual(
				Float_Matrix3_Struct{
					2.f, 0  , 0,
					0  , 2.f, 0,
					0  , 0  , 1.f },
				actual);
		}

        TEST_METHOD(GetForward)
        {

			//Assert::IsTrue(0);

			Float_Matrix3_Struct actual = Float_Matrix3_Struct::MakeRotate_2D(9.62f);
			Assert::AreEqual(Approximate(Float_Vector3_Struct(-0.981005f,-0.193984f, 0)), Approximate(actual.GetForward_X()));
        }
        TEST_METHOD(GetRight)
        {
			Float_Matrix3_Struct actual = Float_Matrix3_Struct::MakeRotate_2D(9.62f);
            Assert::AreEqual(Approximate(Float_Vector3_Struct(0.193984f,-0.981005f, 0)), Approximate(actual.GetRight_Y()));
        }

		TEST_METHOD(IsApproximatelyEqual)
		{
			Float_Matrix3_Struct actual{ 1.0001f, 2.0001f, 3.0001f, 4.0001f, 5.0001f, 6.0001f, 7.0001f, 8.0001f, 9.0001f };
			Assert::IsTrue(actual.IsApproximatelyEqual(Float_Matrix3_Struct{ 1.0001f, 2.0001f, 3.0001f, 4.0001f, 5.0001f, 6.0001f, 7.0001f, 8.0001f, 9.0001f }));
		}
	};
}