// Copyright by Ivan Engelbrecht 2020. All Rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "ND_PlanetArmComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (PlanetParts), meta = (BlueprintSpawnableComponent) )
class NAKATOMIDEMO_API UND_PlanetArmComponent : public USpringArmComponent
{
	GENERATED_BODY()

public:
	UND_PlanetArmComponent();


	UFUNCTION(BlueprintCallable, Category = "Setup")
	float GetDefaultArmLength();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	float DefaultArmLength{ 50.0f };
};
