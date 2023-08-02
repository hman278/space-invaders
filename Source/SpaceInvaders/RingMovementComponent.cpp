// Fill out your copyright notice in the Description page of Project Settings.

#include "RingMovementComponent.h"
#include "Components/SplineComponent.h"
#include "Ring.h"

// Sets default values for this component's properties
URingMovementComponent::URingMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void URingMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void URingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URingMovementComponent::MoveToPointOnRing(ARing *Ring, const FVector &Point, bool bFaceOutside)
{
	FTransform NewTransform =
		Ring->GetSplineComponent()->FindTransformClosestToWorldLocation(Point, ESplineCoordinateSpace::Local, false);

	// Make the actor face outside direction
	NewTransform.SetRotation(
		NewTransform.GetRotation() * FQuat::MakeFromEuler(FVector(0.f, 0.f, bFaceOutside ? -90.f : 90.f)));
	GetOwner()->SetActorTransform(NewTransform);
}
