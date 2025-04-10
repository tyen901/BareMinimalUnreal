// Copyright Epic Games, Inc. All Rights Reserved.

#include "CustomActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACustomActor::ACustomActor()
{
 	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;
	
	// Create and set up the mesh component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SetRootComponent(MeshComponent);
	
	// Initialize custom property
	CustomValue = 100.0f;
}

// Called when the game starts or when spawned
void ACustomActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("CustomActor: Begin Play - CustomValue: %f"), CustomValue);
}

// Called every frame
void ACustomActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Example of something happening every tick
	AddActorLocalRotation(FRotator(0, DeltaTime * 20.0f * CustomValue / 100.0f, 0));
}

void ACustomActor::PerformCustomAction()
{
	UE_LOG(LogTemp, Display, TEXT("CustomActor: Performing custom action"));
	
	// Increase the custom value
	CustomValue += 10.0f;
	UE_LOG(LogTemp, Warning, TEXT("CustomActor: Custom value increased to %f"), CustomValue);
	
	// Flash the actor (example of a visual effect)
	FVector OriginalScale = GetActorScale3D();
	SetActorScale3D(OriginalScale * 1.5f);
	
	// You could schedule it to return to original size using a timer
	// For a simple example, we'll just log the action performed
}