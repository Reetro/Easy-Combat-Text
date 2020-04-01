// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatTextWidget.h"

void UCombatTextWidget::SetCombatText(FText Text, FSlateColor Color)
{
  CombatText = Text;
  TextColor = Color;
}
