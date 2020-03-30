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

  RandomVectorRange.MinY = 500.0f;
  RandomVectorRange.MaxY = 1000.0f;

  RandomVectorRange.MinZ = -500.0f;
  RandomVectorRange.MaxZ = 1000.0f;
}

AFloatingCombatTextManager* UCombatTextComponent::SpawnText(FText Text)
{
  AFloatingCombatTextManager* FloatingText = GetWorld()->SpawnActor<AFloatingCombatTextManager>(TextManager);

  if (!ensure(FloatingText != nullptr)) { return nullptr; }

  FloatingText->ConstructText(Text, TextUpTime, RandomVectorRange, GetOwner(), TextSocket, LerpPlayRate);

  return FloatingText;
}
