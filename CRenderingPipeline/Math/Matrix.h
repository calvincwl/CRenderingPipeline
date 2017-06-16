// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

#include "Math/Vector3.h"
#include "Math/Vector4.h"

class FMatrix
{
public:
	float M[4][4];

	FMatrix
	(
		float M00 = 0.0f, float M01 = 0.0f, float M02 = 0.0f, float M03 = 0.0f,
		float M10 = 0.0f, float M11 = 0.0f, float M12 = 0.0f, float M13 = 0.0f,
		float M20 = 0.0f, float M21 = 0.0f, float M22 = 0.0f, float M23 = 0.0f,
		float M30 = 0.0f, float M31 = 0.0f, float M32 = 0.0f, float M33 = 0.0f
	);
	~FMatrix();

	void Set
	(
		float M00 = 0.0f, float M01 = 0.0f, float M02 = 0.0f, float M03 = 0.0f,
		float M10 = 0.0f, float M11 = 0.0f, float M12 = 0.0f, float M13 = 0.0f,
		float M20 = 0.0f, float M21 = 0.0f, float M22 = 0.0f, float M23 = 0.0f,
		float M30 = 0.0f, float M31 = 0.0f, float M32 = 0.0f, float M33 = 0.0f
	);
	void SetIdentity();
	FMatrix& operator=(const FMatrix& Other);
	FMatrix	operator+(const FMatrix& Other) const;
	FMatrix	operator*(const FMatrix& Other) const;

	//************************************
	// Method:    TransformFVector4
	// FullName:  FMatrix::TransformFVector4
	// Access:    public 
	// Returns:   FVector4
	// Qualifier: const Homogeneous transform.
	// Parameter: const FVector4 & V
	//************************************
	FVector4 TransformFVector4(const FVector4& V) const;
	FVector4 TransformPosition(const FVector3& V) const;
	FVector4 TransformVector(const FVector3& V) const;
	float Determinant() const;
};

