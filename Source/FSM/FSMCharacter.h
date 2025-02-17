// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "FSMCharacter.generated.h"

UCLASS(config=Game)
class AFSMCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	/** Called for side to side input */
	void MoveRight(float Value);

	void MoveForward(float Value);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface


public:
	AFSMCharacter();
};
