#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Matrix3 {
	// elements
	float m00 = 1.0f;
	float m01 = 0.0f;
	float m02 = 0.0f;
	float m10 = 0.0f;
	float m11 = 1.0f;
	float m12 = 0.0f;
	float m20 = 0.0f;
	float m21 = 0.0f;
	float m22 = 1.0f;

	float xm00 = m00;
	float xm01 = m01;
	float xm02 = m02;
	float xm10 = m10;
	float xm11 = m11;
	float xm12 = m12;
	float xm20 = m20;
	float xm21 = m21;
	float xm22 = m22;

	// con/des
	Matrix3() {}
	Matrix3(float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float v9) {
		m00 = v1;
		m01 = v2;
		m02 = v3;
		m10 = v4;
		m11 = v5;
		m12 = v6;
		m20 = v7;
		m21 = v8;
		m22 = v9;
	}
	~Matrix3() {}

	// dbug ToString 
	string ToString() const {
		return to_string(m00) + " , " + to_string(m01) + " , " + to_string(m02) + " , \n" +
			to_string(m10) + " , " + to_string(m11) + " , " + to_string(m12) + " , \n" +
			to_string(m20) + " , " + to_string(m21) + " , " + to_string(m22);
	}

	Matrix3 MakeIdentity() {
		this->m00 = 1.f;
		this->m01 = 0.f;
		this->m02 = 0.f;
		this->m10 = 0.f;
		this->m11 = 1.f;
		this->m12 = 0.f;
		this->m20 = 0.f;
		this->m21 = 0.f;
		this->m22 = 1.f;

		return Matrix3(m00, m01, m02, m10, m11, m12, m20, m21, m22);
	}

	Matrix3 MakeTranslation(float v1, float v2, float v3) {
		m20 = v1;
		m21 = v2;
		m22 = v3;
		return Matrix3(m00, m01, m02, m10, m11, m12, m20, m21, m22);
	}

	Matrix3 UpdateTranslate(float v1, float v2, float v3) {
		m20 += v1;
		m21 += v2;
		m22 += v3;
		return *this;
	}

	Matrix3 MakeRotateZ(float v1) {
		this->m00 = cosf(v1);
		this->m01 = sinf(v1);
		this->m10 = -1 * sinf(v1);
		this->m11 = cosf(v1);
		return Matrix3(m00, m01, m02, m10, m11, m12, m20, m21, m22);
	}

	void Rotate(float radians) {
		Matrix3 matrix;
		matrix.MakeIdentity();
		matrix.MakeRotateZ(radians);
		*this *= matrix;
	}

	Matrix3& operator *= (const Matrix3& other) {
		*this = *this * other;
		return *this;
	}
 
	Matrix3 operator*(Matrix3 val) {
		this->xm00 = val.m00 * m00 + val.m01 * m10 + val.m02 * m20;
		this->xm01 = val.m00 * m01 + val.m01 * m11 + val.m02 * m21;
		this->xm02 = val.m00 * m02 + val.m01 * m12 + val.m02 * m22;

		this->xm10 = val.m10 * m00 + val.m11 * m10 + val.m12 * m20;
		this->xm11 = val.m10 * m01 + val.m11 * m11 + val.m12 * m21;
		this->xm12 = val.m10 * m02 + val.m11 * m12 + val.m12 * m22;

		this->xm20 = val.m20 * m00 + val.m21 * m10 + val.m22 * m20;
		this->xm21 = val.m20 * m01 + val.m21 * m11 + val.m22 * m21;
		this->xm22 = val.m20 * m02 + val.m21 * m12 + val.m22 * m22;

		return Matrix3(xm00, xm01, xm02, xm10, xm11, xm12, xm20, xm21, xm22);
	}
};
