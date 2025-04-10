#pragma once

#include "Engine/DataAsset.h"
#include "CustomDataAsset.generated.h"

UCLASS(BlueprintType)
class BAREMINIMAL_API UCustomDataAsset : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
    FString UniqueIdentifier;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
    FString Name;
};