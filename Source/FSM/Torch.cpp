// Fill out your copyright notice in the Description page of Project Settings.

#include "FSM.h"
#include "Torch.h"


// Sets default values
ATorch::ATorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	isLighted = false;

}

// Called when the game starts or when spawned
void ATorch::BeginPlay()
{
	Super::BeginPlay();
	Light();
	TurnOff();
	
}

// Called every frame
void ATorch::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATorch::Light()
{
	if (!isLighted)
	{
		isLighted = true;
		OnLighted();
	}
}

void ATorch::TurnOff()
{
	if (isLighted)
	{
		isLighted = false;
		OnTurnOff();
	}	
}

void ATorch::OnLighted_Implementation()
{

}

void ATorch::OnTurnOff_Implementation()
{

}

