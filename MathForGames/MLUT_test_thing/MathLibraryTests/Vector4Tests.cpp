#include "CppUnitTest.h"
#include "TestToString.h"
//#include "Utils.h"
#include "Vector4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ::MathLibrary;

namespace MathLibraryTests
{
	//TEST_CLASS(Vector4Tests)
	//{
	//public:
	//// Constructors
	//TEST_METHOD(DefaultConstructor)
	//{
	//	Float_Vector4_Struct vec;
	//	Assert::AreEqual(0.f, vec.Vector4_x);
	//	Assert::AreEqual(0.f, vec.Vector4_y);
	//	Assert::AreEqual(0.f, vec.Vector4_z);
	//	Assert::AreEqual(0.f, vec.Vector4_w);
	//}
	//TEST_METHOD(CopyConstructor)
	//{
	//	Float_Vector4_Struct vec(13.f, 0.1f, 8.f,1.f);
	//	Float_Vector4_Struct copy = vec;
	//	Assert::AreEqual(vec,copy);
	//}
	//TEST_METHOD(ParameterisedConstructor)
	//{
	//	Float_Vector4_Struct vec(1.f, 2.f, 3.f,1.f);
	//	Assert::AreEqual(1.f, vec.Vector4_x);
	//	Assert::AreEqual(2.f, vec.Vector4_y);
	//	Assert::AreEqual(3.f, vec.Vector4_z);
	//	Assert::AreEqual(1.f, vec.Vector4_w);
	//}

	//// Operators
	//TEST_METHOD(Add)
	//{
	//	for (float w = 0; w < 2; ++w) {
	//		Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f, w);
	//		Float_Vector4_Struct v3b(5.f, 4.00f, -12.f, w);

	//		Assert::AreEqual(Approximate(v3a + v3b), Approximate(Float_Vector4_Struct(18.5f, -44.23f, 850.f, w)));

	//		// Make sure + is const
	//		Assert::AreEqual(Float_Vector4_Struct(13.5f, -48.23f, 862.f, w), v3a);
	//	}
	//}

	//TEST_METHOD(Subtract)
	//{
	//	for (float w = 0; w < 2; ++w) {
	//		Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f, w);
	//		Float_Vector4_Struct v3b(5.f, 3.99f, -12.f, w);
	//		Assert::AreEqual(Approximate(v3a - v3b), Approximate(Float_Vector4_Struct(8.5f, -52.22f, 874.f, w)));

	//		//Make sure - is const
	//		Assert::AreEqual(Float_Vector4_Struct(13.5f, -48.23f, 862.f, w), v3a);
	//	}
	//}

	//// Hadamard product
	//TEST_METHOD(Multiply)
	//{
	//	for (float w = 0; w < 2; ++w) {
	//		Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f, w);
	//		Float_Vector4_Struct v3b(5.f, 4.00f, -12.f, w);

	//		Assert::AreEqual(Approximate(v3a * v3b), Approximate(Float_Vector4_Struct(67.5f, -192.92f, -10344, w)));

	//		// Make sure + is const
	//		Assert::AreEqual(Float_Vector4_Struct(13.5f, -48.23f, 862, w), v3a);
	//	}
	//}

	//TEST_METHOD(ScalarMultiply)
	//{
	//	for (float w = 0; w < 2; ++w) {
	//		Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f,w);
	//		Float_Vector4_Struct v3c = v3a * 0.256f;

	//		Assert::AreEqual(Approximate(v3c), Approximate(Float_Vector4_Struct(3.45600008965f, -12.3468809128f, 220.672012329f,w)));

	//		//Make sure * is const
	//		Assert::AreEqual(Float_Vector4_Struct(13.5f, -48.23f, 862.f,w), v3a);
	//	}
	//}
	//TEST_METHOD(ScalarDivide)
	//{
	//	for (float w = 0; w < 2; ++w) {
	//		Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f, w);
	//		Float_Vector4_Struct v3c = v3a / 3.0f;

	//		Assert::AreEqual(Approximate(v3c), Approximate(Float_Vector4_Struct(4.5f, -16.076666f, 287.33334f, w)));

	//		//Make sure * is const
	//		Assert::AreEqual(Float_Vector4_Struct(13.5f, -48.23f, 862.f, w), v3a);
	//	}
	//}

	//TEST_METHOD(Assignment)
	//{
	//	Float_Vector4_Struct v4a(13.5f, -48.23f, 862,1.f);
	//	Float_Vector4_Struct v4c(5.f, 4.00f, -12,0.f);

	//	v4a = v4c;
	//	Assert::AreEqual(v4a, v4c);
	//}

	//TEST_METHOD(AddAssign)
	//{
	//	//Test with w as 0 and 1
	//	for (float w = 0; w < 2; ++w) {
	//		Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f, w);
	//		Float_Vector4_Struct v3b(5.f, 3.99f, -12.f, w);

	//		Assert::AreEqual(Approximate(Float_Vector4_Struct(18.5f, -44.239998f, 850.f, w)),Approximate(v3a += v3b));
	//		Assert::AreEqual(Approximate(Float_Vector4_Struct(18.5f, -44.239998f, 850.f, w)),Approximate(v3a));

	//		//Make sure += mutates
	//		Assert::AreNotEqual(Float_Vector4_Struct(13.5f, -48.23f, 862.f, w), v3a);
	//	}
	//}

	//TEST_METHOD(SubtractAssign)
	//{
	//	//Test with w as 0 and 1
 //       for (float w = 0; w < 2; ++w) {
	//		Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f, w);
	//		Float_Vector4_Struct v3b(5.f, 3.99f, -12.f, w);

 //           Assert::AreEqual(Approximate(Float_Vector4_Struct(8.5f, -52.22f, 874.f, w)), Approximate(v3a -= v3b));
 //           Assert::AreEqual(Approximate(Float_Vector4_Struct(8.5f, -52.22f, 874.f, w)), Approximate(v3a));

 //           //Make sure -= mutates
 //           Assert::AreNotEqual(Float_Vector4_Struct(13.5f, -48.23f, 862.f, w), v3a);
 //       }
	//}

	//TEST_METHOD(MultiplyAssign)
	//{
	//	Float_Vector4_Struct v3a(13.5f, -48.23f, 862,1.0f);
	//	Float_Vector4_Struct v3b(5.f, 3.99f, -12.f,1.0f);

	//	Assert::AreEqual(Approximate(v3a *= v3b), Approximate(Float_Vector4_Struct(67.5f, -192.437698f, -10344.f,1.0f)));
	//	Assert::AreEqual(Approximate(v3a), Approximate(Float_Vector4_Struct(67.5f, -192.437698f, -10344.f, 1.0f)));

	//	//Make sure *= mutates
	//	Assert::AreNotEqual(Float_Vector4_Struct(13.5f, -48.23f, 862,3.4f), v3a);
	//}

	//// TODO: implement tests for compound operators

	//TEST_METHOD(ScalarMultiplyAssign)
	//{
	//	Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f, 3.4f);

	//	Assert::AreEqual(Approximate(v3a *= 0.256f), Approximate(Float_Vector4_Struct(3.45600008965f, -12.3468809128f, 220.672012329f,3.4f)));

	//	//Make sure *= is mutating
	//	Assert::AreEqual(Approximate(v3a), Approximate(Float_Vector4_Struct(3.45600008965f, -12.3468809128f, 220.672012329f, 3.4f)));
	//}
	//TEST_METHOD(ScalarDivideAssign)
	//{
	//	Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f,1.0f);

	//	Assert::AreEqual(Approximate(v3a /= 3.f), Approximate(Float_Vector4_Struct(4.5f, -16.076666f, 287.33334f,1.0f)));

	//	//Make sure * is mutating
	//	Assert::IsTrue(v3a.IsApproximatelyEqual(Float_Vector4_Struct(4.5f, -16.076666f, 287.33334, 1.0f)));
	//}

	//TEST_METHOD(Negative)
	//{
	//	Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f, 1.0f);

	//	Assert::IsTrue(-v3a == Float_Vector4_Struct(-13.5f, 48.23f, -862.f, 1.0f));
	//}

	//TEST_METHOD(Equality)
	//{
	//	Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f,1.0f);
	//	Float_Vector4_Struct v3b(13.5f, -48.23f, 862.f,1.0f);

	//	Assert::IsTrue(v3a == v3b);
	//}

	//TEST_METHOD(Inequality)
	//{
	//	Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f,0.f);
	//	Float_Vector4_Struct v3b(0.0f, 0.0f, 0.0f,0.0f);

	//	Assert::IsTrue(!(v3a == v3b));
	//}

	//TEST_METHOD(LessThan)
	//{
	//	Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f,1.0f);
	//	Float_Vector4_Struct v3b(1.5f, 1.f, 1.f,1.0f);

	//	Assert::IsTrue(v3b < v3a);
	//}

	//TEST_METHOD(SubscriptReference) {
	//	const Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f, 1.0f);

	//	Assert::AreEqual(v3a[0], 13.5f);
	//	Assert::AreEqual(v3a[1], -48.23f);
	//	Assert::AreEqual(v3a[2], 862.f);
	//	Assert::AreEqual(v3a[3], 1.0f);
	//}

	//TEST_METHOD(Subscript) {
	//	Float_Vector4_Struct v3a(0, 0, 0,0);
	//	v3a[0] = 3;
	//	Assert::AreEqual(v3a[0], 3.f);
	//	v3a[1] = 4;
	//	Assert::AreEqual(v3a[1], 4.f);
	//	v3a[2] = 6;
	//	Assert::AreEqual(v3a[2], 6.f);
	//	v3a[3] = 1;
	//	Assert::AreEqual(v3a[3], 1.f);

	//	Assert::AreEqual(v3a.Vector4_x, 3.f, L"X not set");
	//	Assert::AreEqual(v3a.Vector4_y, 4.f, L"Y not set");
	//	Assert::AreEqual(v3a.Vector4_z, 6.f, L"Z not set");
	//	Assert::AreEqual(v3a.Vector4_w, 1.f, L"W not set");
	//}

	//// Methods
	//TEST_METHOD(Dot)
	//{
	//	Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f,0.f);
	//	Float_Vector4_Struct v3b(5.f, 3.99f, -12.f, 0.f);
	//	float dot3 = v3a.V4_Dot_prod(v3b);

	//	Assert::AreEqual(Approximate(-10468.9375f), Approximate(dot3));

	//	Float_Vector4_Struct v3c(0.f, 0.f, 0.f,0.f);
	//	Float_Vector4_Struct v3d(5.f, 3.99f, -12.f,0.f);
	//	dot3 = v3c.V4_Dot_prod(v3d);

	//	Assert::AreEqual(0.0f, dot3);
	//}

	//TEST_METHOD(Cross)
	//{
	//	Float_Vector4_Struct v3a(13.5f, -48.23f, 862,0.f);
	//	Float_Vector4_Struct v3b(5, 3.99f, -12, 0.f);
	//	Float_Vector4_Struct v3c = v3a.V4_Cross_prod(v3b);

	//	Assert::AreEqual(Approximate(v3c), Approximate(Float_Vector4_Struct(-2860.62011719f, 4472.00000000f, 295.01498413f, 0.f)));
	//}

	//TEST_METHOD(Magnitude)
	//{
	//	Float_Vector4_Struct v3a(13.5f, -48.23f, 862,1.f);
	//	float mag3 = v3a.V4_Magnitude();
	//	Assert::AreEqual(Approximate(863.453735352f), Approximate(mag3));

	//	Float_Vector4_Struct v3b(0.f, 0.f, 0.f,1.f);
	//	mag3 = v3b.V4_Magnitude();
	//	Assert::AreEqual(0.f, mag3);
	//}
	//TEST_METHOD(Normalise)
	//{
	//	Float_Vector4_Struct v3a(13.5f, -48.23f, 862.f,1.0f);
	//	v3a.Normalise();
	//	Assert::AreEqual(Approximate(v3a), Approximate(Float_Vector4_Struct(0.0156349f, -0.0558571f, 0.998316f,1.0f)));

	//	Float_Vector4_Struct v3b(0.f, 0.f, 0.f,0.f);
	//	v3b.Normalise();
	//	Assert::AreEqual(Float_Vector4_Struct(0.f, 0.f, 0.f,0.f), v3b);
	//}

	//TEST_METHOD(Normalised)
	//{
	//	Float_Vector4_Struct v3a(13.5f, -48.23f, 862,1.f);
	//	Assert::AreEqual(Approximate(v3a.Normalised()), Approximate(Float_Vector4_Struct(0.0156349f, -0.0558571f, 0.998316f, 1.f)));

	//	Float_Vector4_Struct v3b(0.f, 0.f, 0.f, 0.f);
	//	Assert::AreEqual(Float_Vector4_Struct(0.f, 0.f, 0.f,0.f), v3b.Normalised());

	//	Float_Vector4_Struct v3c(0.f, 1.f, 0.f,1.f);
	//	Assert::AreEqual(Float_Vector4_Struct(0.f, 1.f, 0.f,1.f), v3c.Normalised());
	//}

	//TEST_METHOD(IsApproximatelyEqual)
	//{
	//	Float_Vector4_Struct v3a(13.500001f, -48.230001f, 862.f,1.0f);
	//	Float_Vector4_Struct v3b(13.5f, -48.23000f, 862.00001f, 1.0f);

	//	Assert::IsTrue(v3a.IsApproximatelyEqual(v3b));
	//}

	//TEST_METHOD(AngleBetween)
	//{
	//	Float_Vector4_Struct v3a(1.f, 0.f, 0.f,1.f);
	//	Float_Vector4_Struct v3b(0.f, 0.f, 1.f,1.f);

 //       constexpr float Deg2Rad = 3.14159f / 180.f;

	//	Assert::AreEqual(Approximate(Deg2Rad * 90.f), Approximate(v3a.AngleBetween(v3b)));
	//	Assert::AreEqual(Approximate(Deg2Rad * 90.f), Approximate(v3b.AngleBetween(v3a)));

	//	Float_Vector4_Struct v3c(82.f, -9.f, 140.f,0.f);
	//	Float_Vector4_Struct v3d(-20.f, 0.f, 0.f,0.f);

	//	Assert::AreEqual(Approximate(2.09974647f), Approximate(v3c.AngleBetween(v3d)));
	//	Assert::AreEqual(Approximate(2.09974647f), Approximate(v3d.AngleBetween(v3c)));
	//}

	//////////////////////////////

	//};
}
