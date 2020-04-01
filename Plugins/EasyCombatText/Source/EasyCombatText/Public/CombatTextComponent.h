// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SRandomVectorInfo.h"
#include "UObject/TextProperty.h"
#include "Styling/SlateColor.h"
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
  UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category = "Text Settings")
  TSubclassOf<class AFloatingCombatTextManager> TextManager;
  /* This is how long the text will be up for once this delay is over text will fade out and be destroyed */
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text Settings")
  float TextUpTime;
  /* When text is spawn it will move to a random end location this where you can set the range of the random vector */
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text Settings")
  FRandomVectorInfo RandomVectorRange;
  /* The play rate of the lerp timeline */
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text Settings")
  float LerpPlayRate;
  /* Color of the combat text */
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text Settings")
  FSlateColor TextColor;
  /* The function will spawn combat text on the given socket on a static mesh */
  UFUNCTION(BlueprintCallable, Category = "Combat Text Functions")
  AFloatingCombatTextManager* SpawnTextAtSocketOnStaticMesh(FText Text, FName SocketName, class UStaticMeshComponent* Mesh);
  /* The function will spawn combat text on the given socket on a skeletal mesh */
  UFUNCTION(BlueprintCallable, Category = "Combat Text Functions")
  AFloatingCombatTextManager* SpawnTextAtSocketOnSkeletalMesh(FText Text, FName SocketName, class USkeletalMeshComponent* Mesh);
  /* The function will spawn combat text from the actors root location */
  UFUNCTION(BlueprintCallable, Category = "Combat Text Functions")
  AFloatingCombatTextManager* SpawnTextOnActor(FText Text);
  /* This function will spawn text at the given hit location */
  UFUNCTION(BlueprintCallable, Category = "Combat Text Functions")
  AFloatingCombatTextManager* SpawnTextAtHitLocation(FText Text, FVector HitLocation);
};
