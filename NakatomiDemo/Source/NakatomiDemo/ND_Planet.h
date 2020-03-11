// Copyright by Ivan Engelbrecht 2020. All Rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ND_Planet.generated.h"

class UWidgetComponent;

UCLASS()
class NAKATOMIDEMO_API AND_Planet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AND_Planet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	FName GetMyPlanetName();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void EnableDisableName();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	float GetNameAplha();

	UPROPERTY(EditDefaultsOnly, Category="Setup")
	FName PlanetName = FName("Planet");

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetIsFocusedSpawn(bool IsFocused);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	bool GetIsFocusedSpawn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Setup")   // Defined in BP, not C++ due to it being blueprint implementable.
	void PhaseMeOut();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float NameAlpha = 1.0f;

	bool bIsFocusedSpawn = false;

	
};
