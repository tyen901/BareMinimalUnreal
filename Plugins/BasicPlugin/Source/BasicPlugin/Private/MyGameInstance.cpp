#include "MyGameInstance.h"
#include "MyPawn.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

UMyGameInstance::UMyGameInstance()
{
	CurrentPawn = nullptr;
}

void UMyGameInstance::Init()
{
	Super::Init();
	
	// You can automatically create the pawn at game initialization if desired
	// CreateMyPawn();
	
	UE_LOG(LogTemp, Log, TEXT("MyGameInstance initialized"));
}

AMyPawn* UMyGameInstance::CreateMyPawn()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get World reference in MyGameInstance"));
		return nullptr;
	}

	// Get player controller
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World, 0);
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get PlayerController in MyGameInstance"));
		return nullptr;
	}

	// Spawn the pawn
	FVector SpawnLocation = FVector::ZeroVector;
	FRotator SpawnRotation = FRotator::ZeroRotator;
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	CurrentPawn = World->SpawnActor<AMyPawn>(AMyPawn::StaticClass(), SpawnLocation, SpawnRotation, SpawnParams);
	
	if (CurrentPawn)
	{
		// Possess the newly spawned pawn
		PlayerController->Possess(CurrentPawn);
		UE_LOG(LogTemp, Log, TEXT("MyPawn created and possessed by player controller"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to spawn MyPawn in MyGameInstance"));
	}

	return CurrentPawn;
}
