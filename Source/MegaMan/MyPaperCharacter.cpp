// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPaperCharacter.h"


void AMyPaperCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AMyPaperCharacter::SetCurrentFlipbook();
}

void AMyPaperCharacter::SetCurrentFlipbook()
{
	if (GetVelocity().Size() > 0)
	{
		GetSprite()->SetFlipbook(RunningFlipbook);
	}
	else {
		GetSprite()->SetFlipbook(IdleFlipbook);
	}
}

void AMyPaperCharacter::MakeItJump()
{
	Jump();
}

void AMyPaperCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(FVector(1, 0, 0), AxisValue);
	if (AxisValue < 0)
	{
		GetController()->SetControlRotation(FRotator(0, 180, 0));
	}
	else {
		if (AxisValue > 0)
		{
			GetController()->SetControlRotation(FRotator(0, 0, 0));
		}
		
	}
}

void AMyPaperCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyPaperCharacter::MakeItJump);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPaperCharacter::MoveRight);
}