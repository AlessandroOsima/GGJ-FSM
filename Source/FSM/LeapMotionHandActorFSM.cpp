// Fill out your copyright notice in the Description page of Project Settings.

#include "FSM.h"
#include "LeapMotionHandActorFSM.h"
#include "FSMCharacter.h"




void ALeapMotionHandActorFSM::FindPawnInRange(FVector Location, USphereComponent * SphereCollider, float SlowdownAmount, float MinSlowdownAmount)
{
	ensure(SphereCollider);

	TArray<AActor *> actors;
	SphereCollider->GetOverlappingActors(actors, AFSMCharacter::StaticClass());

	if (actors.Num() > 0)
	{
		for (auto actor : actors)
		{
			AFSMCharacter * character = Cast<AFSMCharacter>(actor);

			if (actor)
			{
				UCharacterMovementComponent * mvm = Cast<UCharacterMovementComponent>(character->GetMovementComponent());

				if (mvm && mvm->MaxWalkSpeed > MinSlowdownAmount)
				{
					mvm->MaxWalkSpeed -= SlowdownAmount;
				}
				else if(mvm)
				{
					mvm->MaxWalkSpeed = MinSlowdownAmount;
				}
			}
		}
	}
	

	
}
