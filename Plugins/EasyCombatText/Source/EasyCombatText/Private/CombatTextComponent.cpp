// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatTextComponent.h"
#include "Engine/World.h"
#include "FloatingCombatTextManager.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UCombatTextComponent::UCombatTextComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

  TextManager = AFloatingCombatTextManager::StaticClass();
  TextUpTime = 0.2f;
  LerpPlayRate = 0.02f;
  
  RandomVectorRange.MinX = -500.0f;
  RandomVectorRange.MaxX = 1000.0f;

  RandomVectorRange.MinY = -500.0f;
  RandomVectorRange.MaxY = 1000.0f;

  RandomVectorRange.MinZ = -500.0f;
  RandomVectorRange.MaxZ = 1000.0f;
}

AFloatingCombatTextManager* UCombatTextComponent::SpawnTextAtSocketOnStaticMesh(FText Text, FName SocketName, UStaticMeshComponent* Mesh)
{
  AFloatingCombatTextManager* FloatingText = GetWorld()->SpawnActor<AFloatingCombatTextManager>(TextManager);

  if (!ensure(FloatingText != nullptr)) { return nullptr; }

  FloatingText->ConstructTextWithSocketOnStaticMesh(Text, TextUpTime, RandomVectorRange, GetOwner(), SocketName, Mesh, LerpPlayRate);

  return FloatingText;
}

AFloatingCombatTextManager* UCombatTextComponent::SpawnTextAtSocketOnSkeletalMesh(FText Text, FName SocketName, USkeletalMeshComponent* Mesh)
{
  AFloatingCombatTextManager* FloatingText = GetWorld()->SpawnActor<AFloatingCombatTextManager>(TextManager);

  if (!ensure(FloatingText != nullptr)) { return nullptr; }

  FloatingText->ConstructTextWithSocketOnSkeletalMesh(Text, TextUpTime, RandomVectorRange, GetOwner(), SocketName, Mesh, LerpPlayRate);

  return FloatingText;
}

AFloatingCombatTextManager* UCombatTextComponent::SpawnTextOnActor(FText Text)
{
  AFloatingCombatTextManager* FloatingText = GetWorld()->SpawnActor<AFloatingCombatTextManager>(TextManager);

  if (!ensure(FloatingText != nullptr)) { return nullptr; }

  FloatingText->ConstructTextWithOutSocket(Text, TextUpTime, RandomVectorRange, GetOwner(), LerpPlayRate);

  return FloatingText;
}
