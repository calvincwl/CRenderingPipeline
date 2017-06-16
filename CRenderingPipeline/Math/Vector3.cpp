// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "Vector3.h"
#include "Math/MathUtility.h"


const FVector3 FVector3::ZeroVector(0.0f, 0.0f, 0.0f);
const FVector3 FVector3::OneVector(1.0f, 1.0f, 1.0f);
const FVector3 FVector3::UpVector(0.0f, 1.0f, 0.0f);
const FVector3 FVector3::ForwardVector(0.0f, 0.0f, 1.0f);
const FVector3 FVector3::RightVector(1.0f, 0.0f, 0.0f);

FVector3::FVector3(float InX /* = 0.0f */, float InY /* = 0.0f */, float InZ /* = 0.0f */)
	: X(InX), Y(InY), Z(InZ)
{
}


FVector3::~FVector3()
{
}

FVector3& FVector3::operator=(const FVector3& V)
{
	X = V.X;
	Y = V.Y;
	Z = V.Z;

	return *this;
}

FVector3 FVector3::operator^(const FVector3& V) const
{
	return FVector3
	(
		Y * V.Z - Z * V.Y,
		Z * V.X - X * V.Z,
		X * V.Y - Y * V.X
	);
}

FVector3 FVector3::CrossProduct(const FVector3& A, const FVector3& B)
{
	return A ^ B;
}

float FVector3::operator|(const FVector3& V) const
{
	return X * V.X + Y * V.Y + Z * V.Z;
}

float FVector3::DotProduct(const FVector3& A, const FVector3& B)
{
	return A | B;
}

FVector3 FVector3::Normalize(const FVector3& V)
{
	float Size = V.Size();
	if (Size <= FMath::Float_Epsilon)
	{
		return V;
	}
	else
	{
		float InvSize = 1.0f / Size;
		return FVector3(V.X * InvSize, V.Y * InvSize, V.Z * InvSize);
	}
}

FVector3 FVector3::operator+(const FVector3& V) const
{
	return FVector3(X + V.X, Y + V.Y, Z + V.Z);
}

FVector3 FVector3::operator-(const FVector3& V) const
{
	return FVector3(X - V.X, Y - V.Y, Z - V.Z);
}

FVector3 FVector3::operator*(const FVector3& V) const
{
	return FVector3(X * V.X, Y * V.Y, Z * V.Z);
}

FVector3 FVector3::operator/(const FVector3& V) const
{
	return FVector3(X / V.X, Y / V.Y, Z / V.Z);
}

FVector3 FVector3::operator+(float Bias) const
{
	return FVector3(X + Bias, Y + Bias, Z + Bias);
}

FVector3 FVector3::operator-(float Bias) const
{
	return FVector3(X - Bias, Y - Bias, Z - Bias);
}

FVector3 FVector3::operator*(float Scale) const
{
	return FVector3(X * Scale, Y * Scale, Z * Scale);
}

FVector3 FVector3::operator/(float Scale) const
{
	const float RScale = 1.f / Scale;
	return FVector3(X * RScale, Y * RScale, Z * RScale);
}

FVector3 FVector3::operator-() const
{
	return FVector3(-X, -Y, -Z);
}

FVector3 FVector3::operator+=(const FVector3& V)
{
	X += V.X; Y += V.Y; Z += V.Z;
	return *this;
}

FVector3 FVector3::operator-=(const FVector3& V)
{
	X -= V.X; Y -= V.Y; Z -= V.Z;
	return *this;
}

FVector3 FVector3::operator*=(const FVector3& V)
{
	X *= V.X; Y *= V.Y; Z *= V.Z;
	return *this;
}

FVector3 FVector3::operator/=(const FVector3& V)
{
	X /= V.X; Y /= V.Y; Z /= V.Z;
	return *this;
}

FVector3 FVector3::operator*=(float Scale)
{
	X *= Scale; Y *= Scale; Z *= Scale;
	return *this;
}

FVector3 FVector3::operator/=(float V)
{
	const float RV = 1.f / V;
	X *= RV; Y *= RV; Z *= RV;
	return *this;
}

float FVector3::Size() const
{
	return FMath::Sqrt(X * X + Y * Y + Z * Z);
}
