// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomActor.generated.h"

UCLASS()
class SOURCEMODULE_API ACustomActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Custom function that can be called from blueprints
	UFUNCTION(BlueprintCallable, Category = "Custom")
	void PerformCustomAction();

	// Property that can be edited in the editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	float CustomValue;

	// Component that can be accessed from blueprints
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* MeshComponent;
};