// Copyright by Ivan Engelbrecht 2020. All Rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ND_FloatingButton.generated.h"

class UARPlaneGeometry;
class AND_PlayerPawn;

UCLASS()
class NAKATOMIDEMO_API AND_FloatingButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AND_FloatingButton();

	UFUNCTION(BlueprintCallable, Category="Setup")
	void AskPlayerPawnToSpawnSystem();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetMyOwner(APawn* MyOwningPawn);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	AND_PlayerPawn* MyOwner = nullptr;
};
