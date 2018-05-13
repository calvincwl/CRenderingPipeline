// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

#include "Math/Vector3.h"
#include "Math/Matrix.h"

class CCamera
{
public:
	CCamera();
	~CCamera();

	void SetData(float InNear, float InFar, float InFOV, float InAspect);
	void Update(float DeltaTime);
	const FMatrix& GetViewMatrix() { return ViewMatrix; }
	const FMatrix& GetProjectMatrix() { return ProjectMatrix; }

private:
	void UpdateViewMatrix();
	void UpdateProjectMatrix();

	float Near;
	float Far;
	float FOV;
	float Aspect;
	FVector3 Position;
	FVector3 Target;
	FVector3 ForwardVector;
	FVector3 RightVector;
	FVector3 UpVector;
	FMatrix ViewMatrix;
	FMatrix ProjectMatrix;
};

