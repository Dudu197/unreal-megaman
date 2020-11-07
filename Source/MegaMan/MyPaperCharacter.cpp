// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPaperCharacter.h"


void AMyPaperCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AMyPaperCharacter::SetCurrentFlipbook();
}

void AMyPaperCharacter::SetCurrentFlipbook()
{
	UCharacterMovementComponent* movementComp = GetCharacterMovement();

	if (movementComp->IsFalling())
	{
		if (IsDashing)
		{
			GetSprite()->SetFlipbook(DashingFlipbook);
		}
		else
		{
			GetSprite()->SetFlipbook(FallingFlipbook);
		}
		return;
	}

	IsDashing = false;

	if (GetVelocity().Size() > 0)
	{
		if (IsShooting)
		{
			GetSprite()->SetFlipbook(RunningShootingFlipbook);
		}
		else {
			GetSprite()->SetFlipbook(RunningFlipbook);
		}
	}
	else {
		if (IsShooting)
		{
			GetSprite()->SetFlipbook(ShootingFlipbook);
		}
		else
		{
			GetSprite()->SetFlipbook(IdleFlipbook);
		}
	}
}

void AMyPaperCharacter::MakeItJump()
{
	Jump();
}

void AMyPaperCharacter::PressShoot()
{
	IsShooting = true;
}

void AMyPaperCharacter::ReleaseShoot()
{
	IsShooting = false;
}

void AMyPaperCharacter::Dash()
{
	if (!IsDashing)
	{
		IsDashing = true;

		UCharacterMovementComponent* movementComp = GetCharacterMovement();
		if (GetController()->GetControlRotation().Yaw == 0)
		{
			LaunchCharacter(FVector(DashSpeed, 0, DashHeight), true, false);
		}
		else
		{
			LaunchCharacter(FVector(-DashSpeed, 0, DashHeight), true, false);
		}
	}
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
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AMyPaperCharacter::PressShoot);
	PlayerInputComponent->BindAction("Shoot", IE_Released, this, &AMyPaperCharacter::ReleaseShoot);
	PlayerInputComponent->BindAction("Dash", IE_Pressed, this, &AMyPaperCharacter::Dash);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPaperCharacter::MoveRight);
}