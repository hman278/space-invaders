// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RingMovementComponent.generated.h"

class ARing;

UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPACEINVADERS_API URingMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	URingMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = RingMovementComponent)
	void MoveToPointOnRing(ARing *Ring, FVector Point, bool bFaceOutside, bool bUseSmoothMovement);

	UFUNCTION(BlueprintCallable, Category = RingMovementComponent)
	void MoveToDistanceOnRing(ARing *Ring, float Distance, bool bFaceOutside, bool bUseSmoothMovement);

private:
	void MoveToPointOnRingLoop();

private:
	bool bCachedUseSmoothMovement;
	FTransform CachedNewTransform;
};
