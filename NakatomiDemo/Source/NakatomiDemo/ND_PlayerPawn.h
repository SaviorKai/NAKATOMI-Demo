// Copyright by Ivan Engelbrecht 2020. All Rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ND_PlayerPawn.generated.h"


class AND_Planet;
class AND_FloatingButton;
class UARPlaneGeometry;

UCLASS()
class NAKATOMIDEMO_API AND_PlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AND_PlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AND_FloatingButton> SpawnButton; // Set in Blueprint

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AND_Planet> SunPlanet; // Set in Blueprint

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup") //// Defined in BP, not C++ due to it being blueprint implementable.
	void RemoveFindSurfaceText();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	FVector GetSolSpawnLocation();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	bool GetHasSpawned();
	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetHasSpawned(bool booleanvalue);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void CreateSolarSystem(FVector SpawnLocationArg);  // Triggered by BP Widget button released
	
	UFUNCTION(BlueprintCallable, Category="Setup")
	void RespawnSolarSystem(); 

private:

	TArray<UARPlaneGeometry*> AllPlanesArray;
	TArray<UARPlaneGeometry*> CreatedPlanesArray;

	bool bHasSpawned = false;
	FVector SpawnLocation = FVector(0, 0, 0);

};
