// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

class FVector3
{
public:
	float X;
	float Y;
	float Z;

	static const FVector3 ZeroVector;
	static const FVector3 OneVector;
	static const FVector3 UpVector;
	static const FVector3 ForwardVector;
	static const FVector3 RightVector;

	FVector3(float InX = 0.0f, float InY = 0.0f, float InZ = 0.0f);
	~FVector3();

	static FVector3 CrossProduct(const FVector3& A, const FVector3& B);
	static float DotProduct(const FVector3& A, const FVector3& B);
	static FVector3 Normalize(const FVector3& V);

	FVector3& operator=(const FVector3& V);
	FVector3 operator^(const FVector3& V) const;
	float operator|(const FVector3& V) const;
	FVector3 operator+(const FVector3& V) const;
	FVector3 operator-(const FVector3& V) const;
	FVector3 operator*(const FVector3& V) const;
	FVector3 operator/(const FVector3& V) const;
	FVector3 operator+(float Bias) const;
	FVector3 operator-(float Bias) const;
	FVector3 operator*(float Scale) const;
	FVector3 operator/(float Scale) const;
	FVector3 operator-() const;
	FVector3 operator+=(const FVector3& V);
	FVector3 operator-=(const FVector3& V);
	FVector3 operator*=(const FVector3& V);
	FVector3 operator/=(const FVector3& V);
	FVector3 operator*=(float Scale);
	FVector3 operator/=(float V);
	float Size() const;
};
