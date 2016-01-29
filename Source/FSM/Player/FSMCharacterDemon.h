// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "FSMCharacterDemon.generated.h"

UCLASS()
class FSM_API AFSMCharacterDemon : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFSMCharacterDemon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void MoveSide(float Scale);
	
};
