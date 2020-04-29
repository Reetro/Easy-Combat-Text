// Copyright 2020, Justin Wells, All rights reserved.


#include "CombatTextWidget.h"

void UCombatTextWidget::SetCombatText(FText Text, FSlateColor Color, FSlateFontInfo Font)
{
  CombatText = Text;
  TextColor = Color;
  FontSettings = Font;
}
