// Fill out your copyright notice in the Description page of Project Settings.

#include "FSM.h"
#include "TorchManager.h"


// Sets default values
ATorchManager::ATorchManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	myTorchCount = 0;
}

// Called when the game starts or when spawned
void ATorchManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATorchManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATorchManager::OnTorchLightedEvent_Implementation()
{

}

void ATorchManager::OnTorchTurnOffEvent_Implementation()
{

}

void ATorchManager::OnTorchLighted()
{
	myTorchCount++;
	OnTorchLightedEvent();
}

void ATorchManager::OnTorchTurnOff()
{
	myTorchCount--;
	OnTorchTurnOffEvent();
}

