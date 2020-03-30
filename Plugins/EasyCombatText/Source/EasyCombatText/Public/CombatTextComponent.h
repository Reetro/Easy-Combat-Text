// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SRandomVectorInfo.h"
#include "Components/ActorComponent.h"
#include "CombatTextComponent.generated.h"

/* This component will spawn floating combat text on the actor it's placed just remember to call the SpawnText function on the Component */
UCLASS( ClassGroup=(CombatText), meta=(BlueprintSpawnableComponent) )
class EASYCOMBATTEXT_API UCombatTextComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatTextComponent();

  /* This is the actor that will spawn and display the combat text */
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite ,Category = "Text Settings")
  TSubclassOf<class AFloatingCombatTextManager> TextManager;
  /* This how long the text will be up for */
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Text Settings")
  float TextUpTime;
  /* Socket to spawn text from */
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Text Settings")
  FName TextSocket;
  /* When text is spawn it will move to a random location this where can set the range of the random vector */
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Text Settings")
  FRandomVectorInfo RandomVectorRange;
  /* The play rate of the lerp timeline */
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Text Settings")
  float LerpPlayRate;
  /* The function used to spawn floating combat text */
  UFUNCTION(BlueprintCallable, Category = "Combat Text Functions")
  AFloatingCombatTextManager* SpawnText(FText Text);
};
