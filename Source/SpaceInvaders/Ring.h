// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ring.generated.h"

class USplineComponent;

UENUM(BlueprintType, Meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class ERingOwner : uint8
{
	ERO_PLAYER UMETA(DisplayName = "Player"),
	ERO_ALIEN UMETA(DisplayName = "Alien"),
};

ENUM_CLASS_FLAGS(ERingOwner);

UCLASS()
class SPACEINVADERS_API ARing : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARing();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, Category = Spline)
	USplineComponent *GetSplineComponent();

	// UFUNCTION(BlueprintCallable, Category = Spline)
	// float GetRingRadius();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Spline, meta = (AllowPrivateAccess = "true"))
	USplineComponent *SplineComponent;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default, meta = (AllowPrivateAccess = "true"))
	float RingRadius = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default, meta = (AllowPrivateAccess = "true"))
	ERingOwner RingOwner;

public:
	/*
		The idea is having a linked list like structure for the invaders knowing which links are the next ones to move to
		Singly (only keeps track of the next node) since they can't move back
	*/
	UPROPERTY(BlueprintReadWrite)
	ARing *NextRing = nullptr;
};
