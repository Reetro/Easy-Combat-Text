// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatTextComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UCombatTextComponent::UCombatTextComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

FVector UCombatTextComponent::CreateRandomVectorInRange(float MaxX, float MinX, float MaxY, float MinY, float MaxZ, float MinZ)
{
  float VectorX = FMath::RandRange(MinX, MaxX);
  float VectorY = FMath::RandRange(MinY, MaxY);
  float VectorZ = FMath::RandRange(MinZ, MaxZ);
  
  return FVector(VectorX, VectorY, VectorZ);
}

