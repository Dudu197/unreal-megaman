// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Paper2D\Classes\PaperFlipbook.h>
#include <Paper2D\Classes\PaperFlipbookComponent.h>
#include "MyPaperCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MEGAMAN_API AMyPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()

	void Tick(float DeltaSeconds);

	void SetCurrentFlipbook();


	// Input functions
	void MoveRight(float AxisValue);
	void MakeItJump();
	void PressShoot();
	void ReleaseShoot();
	void Dash();

	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

	// Sprites
	UPROPERTY(EditAnywhere, Category="Flipbooks")
	UPaperFlipbook* IdleFlipbook;
	UPROPERTY(EditAnywhere, Category = "Flipbooks")
	UPaperFlipbook* RunningFlipbook;
	UPROPERTY(EditAnywhere, Category = "Flipbooks")
	UPaperFlipbook* ShootingFlipbook;
	UPROPERTY(EditAnywhere, Category = "Flipbooks")
	UPaperFlipbook* RunningShootingFlipbook;
	UPROPERTY(EditAnywhere, Category = "Flipbooks")
	UPaperFlipbook* FallingFlipbook;
	UPROPERTY(EditAnywhere, Category = "Flipbooks")
	UPaperFlipbook* DashingFlipbook;

	// Configs
	UPROPERTY(EditAnywhere, Category = "Dash")
	float DashSpeed;
	UPROPERTY(EditAnywhere, Category = "Dash")
	float DashHeight;

	private:
		bool IsShooting = false;
		bool IsDashing = false;
	
};
