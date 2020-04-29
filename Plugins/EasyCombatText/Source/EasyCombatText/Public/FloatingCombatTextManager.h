// Copyright 2020, Justin Wells, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "SRandomVectorInfo.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateColor.h"
#include "UObject/TextProperty.h"
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
  /* Will attach this actor to the given Static Mesh and Socket then starts the timeline */
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat Text Events")
  void ConstructTextWithSocketOnStaticMesh(FText& TextToSet, float TextUpTime, FRandomVectorInfo VectorRange, AActor* TargetActor, FName Socket, class UStaticMeshComponent* Mesh, float PlayRate, FSlateColor Color, FSlateFontInfo Font);
  virtual void ConstructTextWithSocketOnStaticMesh_Implementation(FText& TextToSet, float TextUpTime, FRandomVectorInfo VectorRange, AActor* TargetActor, FName Socket, class UStaticMeshComponent* Mesh, float PlayRate, FSlateColor Color, FSlateFontInfo Font);
  /* Will attach this actor to the given Skeletal Mesh and Socket then starts the timeline */
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat Text Events")
  void ConstructTextWithSocketOnSkeletalMesh(FText& TextToSet, float TextUpTime, FRandomVectorInfo VectorRange, AActor* TargetActor, FName Socket, class USkeletalMeshComponent* Mesh, float PlayRate, FSlateColor Color, FSlateFontInfo Font);
  virtual void ConstructTextWithSocketOnSkeletalMesh_Implementation(FText& TextToSet, float TextUpTime, FRandomVectorInfo VectorRange, AActor* TargetActor, FName Socket, class USkeletalMeshComponent* Mesh, float PlayRate, FSlateColor Color, FSlateFontInfo Font);
  /* Will attach this actor to the owner of the Combat Text Component then starts the timeline */
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat Text Events")
  void ConstructTextWithOutSocket(FText& TextToSet, float TextUpTime, FRandomVectorInfo VectorRange, AActor* TargetActor, float PlayRate, FSlateColor Color, FSlateFontInfo Font);
  virtual void ConstructTextWithOutSocket_Implementation(FText& TextToSet, float TextUpTime, FRandomVectorInfo VectorRange, AActor* TargetActor, float PlayRate, FSlateColor Color, FSlateFontInfo Font);
  /* Will attach this actor to the owner of the Combat Text Component then starts the timeline text will spawn at the given Hit Location */
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat Text Events")
  void ConstructTextWithSetStart(FText& TextToSet, float TextUpTime, FRandomVectorInfo VectorRange, AActor* TargetActor, float PlayRate, FVector HitLocation, FSlateColor Color, FSlateFontInfo Font);
  virtual void ConstructTextWithSetStart_Implementation(FText& TextToSet, float TextUpTime, FRandomVectorInfo VectorRange, AActor* TargetActor, float PlayRate, FVector HitLocation, FSlateColor Color, FSlateFontInfo Font);
  /* Will start moving text to end point */
  UFUNCTION(BlueprintCallable, Category = "Combat Text Functions")
  void StartTextAnimation();

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

  /* Called when text reaches it's endpoint */
  void OnAnimationEnd();

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
