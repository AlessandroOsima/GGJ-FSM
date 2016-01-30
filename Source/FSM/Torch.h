// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Torch.generated.h"

UCLASS()
class FSM_API ATorch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATorch();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintNativeEvent, Category = "Torch Functions")
		void OnLighted();
		void OnLighted_Implementation();
	UFUNCTION(BlueprintNativeEvent, Category = "Torch Functions")
		void OnTurnOff();
		void OnTurnOff_Implementation();

	UFUNCTION(BlueprintCallable, Category = "Torch Functions")
		bool IsLighted() { return isLighted; }
	UFUNCTION(BlueprintCallable, Category = "Torch Functions")
		void Light();
	UFUNCTION(BlueprintCallable, Category = "Torch Functions")
		void TurnOff();		

private:
	bool isLighted;	
	
};
