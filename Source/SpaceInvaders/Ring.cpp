// Fill out your copyright notice in the Description page of Project Settings.

#include "Ring.h"

#include "Components/SplineComponent.h"

// Sets default values
ARing::ARing()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	RootComponent = SplineComponent;
	SplineComponent->SetClosedLoop(true);
}

// Called when the game starts or when spawned
void ARing::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

USplineComponent *ARing::GetSplineComponent()
{
	return SplineComponent;
}