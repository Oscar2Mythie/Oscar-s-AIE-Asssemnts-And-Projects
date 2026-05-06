#pragma once

#include <cstdlib>
#include <string>

#include "CppUnitTestAssert.h"

#include "TestUtilities.h"

#include <Vector3.h>
#include <Vector4.h>
#include <Matrix3.h>
#include <Matrix4.h>
#include <Color.h>

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework
		{
			using MathLibrary::Approximate;
			using MathLibrary::Float_Vector3_Struct;
			using MathLibrary::Float_Vector4_Struct;
			using MathLibrary::Float_Matrix3_Struct;
			using MathLibrary::Float_Matrix4_Struct;
			using MathLibrary::Color;

			template<typename T>
			std::wstring Stringify(const T& o, const int count) {
				std::wstring str = L"\n" + std::to_wstring(o[0])+L", ";
				for (int i = 1; i < count; ++i)
				{
					str += std::to_wstring(o[i]);
					if(i!=count-1) str+=L", ";
					if (count>4 && ((i+1) % (int)sqrt(count)) == 0) str += L"\n";
				}
				return str + L"\n";
			}

			template<> inline std::wstring ToString(const Approximate<typename Float_Matrix3_Struct>& t)
			{
				return Stringify<Approximate<typename Float_Matrix3_Struct>>(t, 9);
			}

			template<> inline std::wstring ToString(const Approximate<typename Float_Matrix4_Struct>& t)
			{
				return Stringify<Approximate<typename Float_Matrix4_Struct>>(t, 16);
			}

			template<> inline std::wstring ToString(const Approximate<typename Float_Vector3_Struct>& t)
			{
				return Stringify<Approximate<typename Float_Vector3_Struct>>(t, 3);
			}

			template<> inline std::wstring ToString(const Approximate<typename Float_Vector4_Struct>& t)
			{
				return Stringify<Approximate<typename Float_Vector4_Struct>>(t, 4);
			}

			template<> inline std::wstring ToString(const Approximate<typename float>& t)
			{
				return ToString(t.ref);
			}

			template<> inline std::wstring ToString<Float_Vector3_Struct>(const Float_Vector3_Struct& t)
			{
				return Stringify<Float_Vector3_Struct>(t, 3);
			}

			template<> inline std::wstring ToString<Float_Vector4_Struct>(const Float_Vector4_Struct& t)
			{
				return Stringify<Float_Vector4_Struct>(t, 4);
			}

			template<> inline std::wstring ToString<Float_Matrix3_Struct>(const Float_Matrix3_Struct& t)
			{
				return Stringify<Float_Matrix3_Struct>(t, 9);
			}

			template<> inline std::wstring ToString<Float_Matrix4_Struct>(const Float_Matrix4_Struct& t)
			{
				return Stringify<Float_Matrix4_Struct>(t, 16);
			}

			template<> inline std::wstring ToString<Color>(const Color& t)
			{
				return std::to_wstring(t.GetRed()) + L"," + std::to_wstring(t.GetGreen()) + L"," + std::to_wstring(t.GetBlue()) + L"," + std::to_wstring(t.GetAlpha());
			}
		}
	}
}