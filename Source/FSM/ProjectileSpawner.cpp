// Fill out your copyright notice in the Description page of Project Settings.

#include "FSM.h"
#include "ProjectileSpawner.h"
#include "Projectile.h"
#include "KismetDebugUtilities.h"


// Sets default values for this component's properties
UProjectileSpawner::UProjectileSpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UProjectileSpawner::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UProjectileSpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UProjectileSpawner::SpawnProjectile(FVector DirectionNormal) {
	if (ProjectileObject != NULL) {
		UWorld*	const World = GetWorld();
		if (World) {
			FVector SpawnLocation = GetOwner()->GetActorLocation() + FVector(0.0f, -2.0f, 0.0f);
			DrawDebugLine(World, GetOwner()->GetActorLocation(), FVector(0.0f, 0.0f, 0.0f), FColor(255, 0, 255), true);

			FActorSpawnParameters Params;
			FRotator Rotation;
			AProjectile* const SpawnedProjectile = World->SpawnActor<AProjectile>(ProjectileObject, SpawnLocation, Rotation, Params);
		}
	}
}