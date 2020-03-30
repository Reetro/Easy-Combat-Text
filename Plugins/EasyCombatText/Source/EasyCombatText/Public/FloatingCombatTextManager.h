// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SRandomVectorInfo.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "FloatingCombatTextManager.generated.h"

UCLASS()
class EASYCOMBATTEXT_API AFloatingCombatTextManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingCombatTextManager();

  /* Creates a random vector in range this will be the end position of the text */
  UFUNCTION(BlueprintPure, Category = "Combat Text Functions")
  FVector CreateRandomVectorInRange(float MaxX, float MinX, float MaxY, float MinY, float MaxZ, float MinZ);
  /* Returns the current actor the text is attached to */
  UFUNCTION(BlueprintPure, Category = "Combat Text Functions")
  AActor* GetCurrentActor();
  /* Returns the UpTime set on the text */
  UFUNCTION(BlueprintPure, Category = "Combat Text Functions")
  float GetTextUpTime();
  /* Set the text to display and it's up time */
  UFUNCTION(BlueprintCallable, Category = "Combat Text Functions")
  void ConstructTextWithSocketOnStaticMesh(FText TextToSet, float TextUpTime, FRandomVectorInfo VectorRange, AActor* TargetActor, FName Socket, class UStaticMeshComponent* Mesh, float PlayRate);
  /* Set the text to display and it's up time */
  UFUNCTION(BlueprintCallable, Category = "Combat Text Functions")
  void ConstructTextWithSocketOnSkeletalMesh(FText TextToSet, float TextUpTime, FRandomVectorInfo VectorRange, AActor* TargetActor, FName Socket, class USkeletalMeshComponent* Mesh, float PlayRate);
  /* Set the text to display and it's up time */
  UFUNCTION(BlueprintCallable, Category = "Combat Text Functions")
  void ConstructTextWithOutSocket(FText TextToSet, float TextUpTime, FRandomVectorInfo VectorRange, AActor* TargetActor, float PlayRate);
  /* Will start moving text to end point */
  UFUNCTION(BlueprintCallable, Category = "Combat Text Functions")
  void StartTextAnimation();
  /* Called when text reaches it's endpoint */
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat Text Events")
  void OnAnimationEnd();
  void OnAnimationEnd_Implementation();
  /* This is the widget class the text will be displayed on */
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat Text Vars")
  class UCombatTextWidget* TextWidget;

  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  class USceneComponent* SceneComp;

  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  class UWidgetComponent* WidgetComp;
  /* Returns the socket this actor is attached to */
  UFUNCTION(BlueprintPure, Category = "Combat Text Functions")
  const FName GetAttachedSocket();
  /* Get the current widget object from the widget component */
  UFUNCTION(BlueprintPure, Category = "Combat Text Functions")
  class UCombatTextWidget* GetCurrentWidgetObject();

  /* Returns the starting position */
  UFUNCTION(BlueprintPure, Category = "Combat Text Functions")
  FVector GetStartLocation();

private:

  AActor* CurrentActor;

  float UpTime;

  FVector EndPoint;

  FText TextToDisplay;

  FName AttachedSocket;

  float TimelinePlayRate;

  class UCombatTextWidget* CurrentWidgetObject;

  void SetUpTime(float Delay);

  void DestroyText();

  UCombatTextWidget* CombatTextWidget;

  bool bAtSocket;

  FVector StartLocation;

  FVector SetStartLocation(class UStaticMeshComponent* Mesh);

  FVector SetStartLocation(class USkeletalMeshComponent* Mesh);

  FVector SetStartLocation();

protected:

  FTimeline TextTimeline;

  UPROPERTY()
  UCurveFloat* FloatCurve;

  UFUNCTION()
  void TimelineCallback(float val);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
