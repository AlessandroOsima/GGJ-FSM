// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TorchManager.generated.h"

UCLASS()
class FSM_API ATorchManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATorchManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintNativeEvent, Category = "Torch Functions")
		void OnTorchLightedEvent();
		void OnTorchLightedEvent_Implementation();
	UFUNCTION(BlueprintNativeEvent, Category = "Torch Functions")
		void OnTorchTurnOffEvent();
		void OnTorchTurnOffEvent_Implementation();

	UFUNCTION(BlueprintCallable, Category = "Torch Functions")
		void OnTorchLighted();
	UFUNCTION(BlueprintCallable, Category = "Torch Functions")
		void OnTorchTurnOff();
	UFUNCTION(BlueprintCallable, Category = "Torch Functions")
		int32 GetTorchCount() { return myTorchCount; };

private:
	int myTorchCount;
	
};
