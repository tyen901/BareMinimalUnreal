#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

class AMyPawn;

/**
 * Custom game instance that creates a MyPawn instance
 */
UCLASS()
class BASICPLUGIN_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMyGameInstance();
	
	virtual void Init() override;

	UFUNCTION(BlueprintCallable, Category = "Game")
	AMyPawn* CreateMyPawn();

	UPROPERTY(BlueprintReadOnly, Category = "Game")
	AMyPawn* CurrentPawn;
};
