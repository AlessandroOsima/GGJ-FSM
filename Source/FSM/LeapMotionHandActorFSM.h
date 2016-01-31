// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LeapMotionHandActor.h"
#include "LeapMotionHandActorFSM.generated.h"

/**
 * 
 */
UCLASS()
class FSM_API ALeapMotionHandActorFSM : public ALeapMotionHandActor
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Hit)
	void FindPawnInRange(FVector Location, USphereComponent * SphereCollider, float SlowdownAmount);

	
	
};
