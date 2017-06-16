// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "Matrix.h"
#include <string.h>



FMatrix::FMatrix
(
	float M00 /* = 0.0f */, float M01 /* = 0.0f */, float M02 /* = 0.0f */, float M03 /* = 0.0f */,
	float M10 /* = 0.0f */, float M11 /* = 0.0f */, float M12 /* = 0.0f */, float M13 /* = 0.0f */,
	float M20 /* = 0.0f */, float M21 /* = 0.0f */, float M22 /* = 0.0f */, float M23 /* = 0.0f */,
	float M30 /* = 0.0f */, float M31 /* = 0.0f */, float M32 /* = 0.0f */, float M33 /* = 0.0f */
)
{
	M[0][0] = M00; M[0][1] = M01;  M[0][2] = M02;  M[0][3] = M03;
	M[1][0] = M10; M[1][1] = M11;  M[1][2] = M12;  M[1][3] = M13;
	M[2][0] = M20; M[2][1] = M21;  M[2][2] = M22;  M[2][3] = M23;
	M[3][0] = M30; M[3][1] = M31;  M[3][2] = M32;  M[3][3] = M33;
}

FMatrix::~FMatrix()
{
}

void FMatrix::Set
(
	float M00 /* = 0.0f */, float M01 /* = 0.0f */, float M02 /* = 0.0f */, float M03 /* = 0.0f */,
	float M10 /* = 0.0f */, float M11 /* = 0.0f */, float M12 /* = 0.0f */, float M13 /* = 0.0f */,
	float M20 /* = 0.0f */, float M21 /* = 0.0f */, float M22 /* = 0.0f */, float M23 /* = 0.0f */,
	float M30 /* = 0.0f */, float M31 /* = 0.0f */, float M32 /* = 0.0f */, float M33 /* = 0.0f */
)
{
	M[0][0] = M00; M[0][1] = M01;  M[0][2] = M02;  M[0][3] = M03;
	M[1][0] = M10; M[1][1] = M11;  M[1][2] = M12;  M[1][3] = M13;
	M[2][0] = M20; M[2][1] = M21;  M[2][2] = M22;  M[2][3] = M23;
	M[3][0] = M30; M[3][1] = M31;  M[3][2] = M32;  M[3][3] = M33;
}

void FMatrix::SetIdentity()
{
	M[0][0] = 1.0f; M[0][1] = 0.0f;  M[0][2] = 0.0f;  M[0][3] = 0.0f;
	M[1][0] = 0.0f; M[1][1] = 1.0f;  M[1][2] = 0.0f;  M[1][3] = 0.0f;
	M[2][0] = 0.0f; M[2][1] = 0.0f;  M[2][2] = 1.0f;  M[2][3] = 0.0f;
	M[3][0] = 0.0f; M[3][1] = 0.0f;  M[3][2] = 0.0f;  M[3][3] = 1.0f;
}

FMatrix& FMatrix::operator=(const FMatrix& Other)
{
	memcpy(*M, *Other.M, sizeof(float) * 16);
	//for (int X = 0; X < 4; ++X)
	//{
	//	for (int Y = 0; Y < 4; ++Y)
	//	{
	//		M[X][Y] = Other.M[X][Y];
	//	}
	//}

	return *this;
}

FMatrix	FMatrix::operator+(const FMatrix& Other) const
{
	FMatrix ResultMat;

	for (int X = 0; X < 4; ++X)
	{
		for (int Y = 0; Y < 4; ++Y)
		{
			ResultMat.M[X][Y] = M[X][Y] + Other.M[X][Y];
		}
	}

	return ResultMat;
}

FMatrix	FMatrix::operator*(const FMatrix& Other) const
{
	FMatrix ResultMat;

	for (int X = 0; X < 4; ++X)
	{
		for (int Y = 0; Y < 4; ++Y)
		{
			for (int Index = 0; Index < 4; ++Index)
			{
				ResultMat.M[X][Y] = M[X][Index] * Other.M[Index][Y];
			}
		}
	}

	return ResultMat;
}

FVector4 FMatrix::TransformFVector4(const FVector4& P) const
{
	FVector4 Result;
	Result.X = P.X * M[0][0] + P.Y * M[1][0] + P.Z * M[2][0] + P.W * M[3][0];
	Result.Y = P.X * M[0][1] + P.Y * M[1][1] + P.Z * M[2][1] + P.W * M[3][1];
	Result.Z = P.X * M[0][2] + P.Y * M[1][2] + P.Z * M[2][2] + P.W * M[3][2];
	Result.W = P.X * M[0][3] + P.Y * M[1][3] + P.Z * M[2][3] + P.W * M[3][3];
	return Result;
}

FVector4 FMatrix::TransformPosition(const FVector3& V) const
{
	return TransformFVector4(FVector4(V.X, V.Y, V.Z, 1.0f));
}

FVector4 FMatrix::TransformVector(const FVector3& V) const
{
	return TransformFVector4(FVector4(V.X, V.Y, V.Z, 0.0f));
}

float FMatrix::Determinant() const
{
	return	M[0][0] * (
		M[1][1] * (M[2][2] * M[3][3] - M[2][3] * M[3][2]) -
		M[2][1] * (M[1][2] * M[3][3] - M[1][3] * M[3][2]) +
		M[3][1] * (M[1][2] * M[2][3] - M[1][3] * M[2][2])
		) -
		M[1][0] * (
			M[0][1] * (M[2][2] * M[3][3] - M[2][3] * M[3][2]) -
			M[2][1] * (M[0][2] * M[3][3] - M[0][3] * M[3][2]) +
			M[3][1] * (M[0][2] * M[2][3] - M[0][3] * M[2][2])
			) +
		M[2][0] * (
			M[0][1] * (M[1][2] * M[3][3] - M[1][3] * M[3][2]) -
			M[1][1] * (M[0][2] * M[3][3] - M[0][3] * M[3][2]) +
			M[3][1] * (M[0][2] * M[1][3] - M[0][3] * M[1][2])
			) -
		M[3][0] * (
			M[0][1] * (M[1][2] * M[2][3] - M[1][3] * M[2][2]) -
			M[1][1] * (M[0][2] * M[2][3] - M[0][3] * M[2][2]) +
			M[2][1] * (M[0][2] * M[1][3] - M[0][3] * M[1][2])
			);
}
