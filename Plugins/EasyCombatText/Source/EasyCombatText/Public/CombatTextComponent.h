// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatTextComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EASYCOMBATTEXT_API UCombatTextComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatTextComponent();

  /* Creates a random vector in range this will be the starting position of the text */
  UFUNCTION(BlueprintPure, Category = "Combat Text Functions")
  FVector CreateRandomVectorInRange(float MaxX, float MinX, float MaxY, float MinY, float MaxZ, float MinZ);



};
