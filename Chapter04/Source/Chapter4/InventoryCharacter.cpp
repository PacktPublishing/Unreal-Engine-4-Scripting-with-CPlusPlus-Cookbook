// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter4.h"
#include "InventoryCharacter.h"


// Sets default values
AInventoryCharacter::AInventoryCharacter()
	:Super()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyInventory = CreateDefaultSubobject<UInventoryComponent>("MyInventory");
	MainCamera = CreateDefaultSubobject<UCameraComponent>("MainCamera");
	MainCamera->bUsePawnControlRotation = 0;
	
	
	
}

// Called when the game starts or when spawned
void AInventoryCharacter::BeginPlay()
{
	Super::BeginPlay();
	MainCamera->AttachTo(RootComponent);
	
}

// Called every frame
void AInventoryCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
	if (!MovementInput.IsZero())
	{
		MovementInput *= 100;
		//Scale our movement input axis values by 100 units per second
		FVector InputVector = FVector(0,0,0);
		InputVector += GetActorForwardVector()* MovementInput.X * DeltaTime;
		InputVector += GetActorRightVector()* MovementInput.Y * DeltaTime;
		GetCharacterMovement()->AddInputVector(InputVector);
		//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("x- %f, y - %f, z - %f"),InputVector.X, InputVector.Y, InputVector.Z));
		
	}

	if (!CameraInput.IsNearlyZero())
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Pitch += CameraInput.Y;
		NewRotation.Yaw += CameraInput.X;
		
		APlayerController* MyPlayerController =Cast<APlayerController>(GetController());
		if (MyPlayerController != nullptr)
		{
			MyPlayerController->AddYawInput(CameraInput.X);
			MyPlayerController->AddPitchInput(CameraInput.Y);
		}
		SetActorRotation(NewRotation);
	}
}

// Called to bind functionality to input
void AInventoryCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &AInventoryCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AInventoryCharacter::MoveRight);
	InputComponent->BindAxis("CameraPitch", this, &AInventoryCharacter::PitchCamera);
	InputComponent->BindAxis("CameraYaw", this, &AInventoryCharacter::YawCamera);
	InputComponent->BindAction("DropItem", EInputEvent::IE_Pressed, this, &AInventoryCharacter::DropItem);

}

void AInventoryCharacter::DropItem()
{
	if (MyInventory->CurrentInventory.Num() == 0)
	{
		return;
	}
	AInventoryActor* Item = MyInventory->CurrentInventory.Last();
		MyInventory->RemoveFromInventory(Item);
		//should probably use scaled bounding box
		FVector ItemOrigin;
		FVector ItemBounds;
		Item->GetActorBounds(false, ItemOrigin, ItemBounds);
		FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
		Item->PutDown(PutDownLocation);
}

void AInventoryCharacter::MoveForward(float AxisValue)
{
	MovementInput.X = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void AInventoryCharacter::MoveRight(float AxisValue)
{
	MovementInput.Y = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void AInventoryCharacter::PitchCamera(float AxisValue)
{
	CameraInput.Y = AxisValue;
}

void AInventoryCharacter::YawCamera(float AxisValue)
{
	CameraInput.X = AxisValue;
}

void AInventoryCharacter::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AInventoryActor* InventoryItem = Cast<AInventoryActor>(Other);
	if (InventoryItem != nullptr)
	{
		TakeItem(InventoryItem);

	}

}

void AInventoryCharacter::TakeItem(AInventoryActor* InventoryItem)
{
	InventoryItem->PickUp();
	MyInventory->AddToInventory(InventoryItem);
}
