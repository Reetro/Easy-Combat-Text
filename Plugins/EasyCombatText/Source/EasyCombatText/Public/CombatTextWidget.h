// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CombatTextWidget.generated.h"

/**
 * 
 */
UCLASS()
class EASYCOMBATTEXT_API UCombatTextWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

  UPROPERTY(BlueprintReadOnly, Category = "Combat Text Vars")
  FText CombatText;

  UPROPERTY(BlueprintReadOnly, Category = "Combat Text Vars")
  FSlateColor TextColor;

  UPROPERTY(BlueprintReadOnly, Category = "Combat Text Vars")
  FSlateFontInfo FontSettings;

  UFUNCTION(BlueprintCallable, Category = "Combat Text Functions")
  void SetCombatText(FText Text, FSlateColor Color, FSlateFontInfo Font);

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
  class UWidgetAnimation* FadeAnimation;

};
