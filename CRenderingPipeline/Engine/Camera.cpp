// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "Camera.h"
#include "Math/MathUtility.h"



CCamera::CCamera()
{
	Target = FVector3::ZeroVector;
	Position = -FVector3::ForwardVector * 4.0f;
}


CCamera::~CCamera()
{
}

void CCamera::SetData(float InNear, float InFar, float InFOV, float InAspect)
{
	Near = InNear;
	Far = InFar;
	FOV = InFOV;
	Aspect = InAspect;
}

void CCamera::Update(float DeltaTime)
{
	UpdateViewMatrix();
	UpdateProjectMatrix();
}

void CCamera::UpdateViewMatrix()
{
	ForwardVector = FVector3::Normalize(Target - Position);
	RightVector = FVector3::Normalize(FVector3::UpVector ^ ForwardVector);
	UpVector = FVector3::Normalize(ForwardVector ^ RightVector);

	ViewMatrix.Set
	(
		RightVector.X,				UpVector.X,				ForwardVector.X,			0.0f,
		RightVector.Y,				UpVector.Y,				ForwardVector.Y,			0.0f,
		RightVector.Z,				UpVector.Z,				ForwardVector.Z,			0.0f,
		-Position | RightVector,	-Position | UpVector,	-Position | ForwardVector,	1.0f
	);
}

void CCamera::UpdateProjectMatrix()
{
	float CotTheta = 1.0f / FMath::Tan(FMath::DegreesToRadians(FOV / 2.0f));
	ProjectMatrix.Set
	(
		CotTheta / Aspect,	0.0f,		0.0f,						0.0f,
		0.0f,				CotTheta,	0.0f,						0.0f,
		0.0f,				0.0f,		Far / (Far - Near),			1.0f,
		0.0f,				0.0f,		Far * Near / (Near - Far),	0.0f
	);
}
