// Copyright 2020, Justin Wells, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SRandomVectorInfo.generated.h"

USTRUCT(BlueprintType)
struct FRandomVectorInfo
{
  GENERATED_USTRUCT_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random Vector Range")
  float MinX;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random Vector Range")
  float MaxX;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random Vector Range")
  float MinY;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random Vector Range")
  float MaxY;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random Vector Range")
  float MinZ;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random Vector Range")
  float MaxZ;
};
