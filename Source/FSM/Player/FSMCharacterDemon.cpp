// Fill out your copyright notice in the Description page of Project Settings.

#include "FSM.h"
#include "FSMCharacterDemon.h"


// Sets default values
AFSMCharacterDemon::AFSMCharacterDemon()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFSMCharacterDemon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFSMCharacterDemon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AFSMCharacterDemon::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveSidePlayer2", this, &AFSMCharacterDemon::MoveSide);
}

void AFSMCharacterDemon::MoveSide(float Scale)
{

}

