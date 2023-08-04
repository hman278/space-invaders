// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpaceInvadersPlayerController.h"

ASpaceInvadersPlayerController::ASpaceInvadersPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void ASpaceInvadersPlayerController::BeginPlay()
{
	// Call the base class
	Super::BeginPlay();
}