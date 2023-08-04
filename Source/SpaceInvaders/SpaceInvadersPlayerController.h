// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpaceInvadersPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;

UCLASS()
class ASpaceInvadersPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASpaceInvadersPlayerController();

protected:
	virtual void BeginPlay();
};
