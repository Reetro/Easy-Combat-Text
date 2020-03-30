// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingCombatTextManager.h"
#include "Curves/CurveFloat.h"
#include "Components/SceneComponent.h"
#include "Components/WidgetComponent.h"
#include "CombatTextWidget.h"
#include "Engine.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AFloatingCombatTextManager::AFloatingCombatTextManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  static ConstructorHelpers::FObjectFinder<UCurveFloat> FloatCurveObject(TEXT("/EasyCombatText/TextCurve"));
  check(FloatCurveObject.Succeeded());

  FloatCurve = FloatCurveObject.Object;

  ConstructorHelpers::FClassFinder<UUserWidget> CombatWidgetClass(TEXT("/EasyCombatText/CombatText_W"));
  if (!ensure(CombatWidgetClass.Class != nullptr)) { return; }

  SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
  RootComponent = SceneComp;

  WidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("TextWidget"));
  WidgetComp->SetupAttachment(RootComponent);

  WidgetComp->SetWidgetSpace(EWidgetSpace::Screen);
  WidgetComp->SetWidgetClass(CombatWidgetClass.Class);
  WidgetComp->SetDrawSize(FVector2D(100.0f, 100.0f));
}

// Called every frame
void AFloatingCombatTextManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
  
  TextTimeline.TickTimeline(DeltaTime);
}

void AFloatingCombatTextManager::TimelineCallback(float val)
{
  FVector TargetPostion = FMath::Lerp(GetActorLocation(), EndPoint, val);

  SetActorLocation(TargetPostion);
}

void AFloatingCombatTextManager::OnAnimationEnd_Implementation()
{
  
}

void AFloatingCombatTextManager::StartTextAnimation()
{
  // Setup Timeline
  FOnTimelineFloat TimelineProgress;
  TimelineProgress.BindUFunction(this, FName("TimelineCallback"));
  TextTimeline.AddInterpFloat(FloatCurve, TimelineProgress);
  TextTimeline.SetTimelineLength(UpTime);
  TextTimeline.SetLooping(false);
  TextTimeline.SetPlayRate(TimelinePlayRate);
  TextTimeline.PlayFromStart();
}

void AFloatingCombatTextManager::ConstructText(FText TextToSet, float TextUpTime, FRandomVectorInfo VectorRange, AActor* TargetActor, FName Socket, float PlayRate)
{
  TextUpTime = UpTime;

  EndPoint = CreateRandomVectorInRange(VectorRange.MaxX, VectorRange.MinX, VectorRange.MaxY, VectorRange.MinY, VectorRange.MaxZ, VectorRange.MinZ);

  TextToDisplay = TextToSet;

  CurrentActor = TargetActor;

  AttachedSocket = Socket;

  TimelinePlayRate = PlayRate;

  FAttachmentTransformRules rules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);

  this->AttachToActor(CurrentActor, rules, AttachedSocket);

  UCombatTextWidget* LocalWidget = GetCurrentWidgetObject();

  if (LocalWidget)
  {
    LocalWidget->SetCombatText(TextToDisplay);
  }
  else
  {
    GEngine->AddOnScreenDebugMessage(
      -1, 
      0.35f,   
      FColor::Red.WithAlpha(64),
      FString::Printf(TEXT("Failed to create CombatText was unable to get combat text widget"))
    );
    return;
  }

  StartTextAnimation();
}

FVector AFloatingCombatTextManager::CreateRandomVectorInRange(float MaxX, float MinX, float MaxY, float MinY, float MaxZ, float MinZ)
{
  float VectorX = FMath::RandRange(MinX, MaxX);
  float VectorY = FMath::RandRange(MinY, MaxY);
  float VectorZ = FMath::RandRange(MinZ, MaxZ);

  return FVector(VectorX, VectorY, VectorZ);
}

AActor* AFloatingCombatTextManager::GetCurrentActor()
{
  return CurrentActor;
}

float AFloatingCombatTextManager::GetTextUpTime()
{
  return UpTime;
}

const FName AFloatingCombatTextManager::GetAttachedSocket()
{
  return AttachedSocket;
}

UCombatTextWidget* AFloatingCombatTextManager::GetCurrentWidgetObject()
{
  UCombatTextWidget* LocalWidget = Cast<UCombatTextWidget>(WidgetComp->GetUserWidgetObject());

  if (LocalWidget)
  {
    return LocalWidget;
  }
  else
  {
    return nullptr;
  }
}
