// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatTextWidget.h"

void UCombatTextWidget::SetCombatText(FText Text, FSlateColor Color, FSlateFontInfo Font)
{
  CombatText = Text;
  TextColor = Color;
  FontSettings = Font;
}
