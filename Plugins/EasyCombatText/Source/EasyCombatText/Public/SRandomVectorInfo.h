// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SRandomVectorInfo.generated.h"

USTRUCT(BlueprintType)
struct FRandomVectorInfo
{
  GENERATED_USTRUCT_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float MinX;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float MaxX;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float MinY;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float MaxY;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float MinZ;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float MaxZ;
};
