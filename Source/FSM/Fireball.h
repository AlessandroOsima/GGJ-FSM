// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Projectile.h"
#include "Fireball.generated.h"

/**
*
*/
UCLASS()
class FSM_API AFireball : public AProjectile
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "Projectile")
		float GetDamage();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float Damage;


};
