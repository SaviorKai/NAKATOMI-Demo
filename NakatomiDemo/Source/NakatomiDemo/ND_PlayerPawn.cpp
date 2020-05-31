// Copyright by Ivan Engelbrecht 2020. All Rights reserved.


#include "ND_PlayerPawn.h"
#include "ARBlueprintLibrary.h"
#include "ND_Planet.h"
#include "ND_FloatingButton.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"					// For LineTrace
#include "Engine/EngineTypes.h"             // For FHitResult



// Sets default values
AND_PlayerPawn::AND_PlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AND_PlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	// Disable Screensaver
	UKismetSystemLibrary::ControlScreensaver(false);


}

FVector AND_PlayerPawn::GetSolSpawnLocation()
{
	return SpawnLocation;
}

bool AND_PlayerPawn::GetHasSpawned()
{
	return bHasSpawned;
}

void AND_PlayerPawn::SetHasSpawned(bool HasSpawned)
{
	bHasSpawned = HasSpawned;
}

// Called every frame
void AND_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AND_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AND_PlayerPawn::CreateSolarSystem(FVector SpawnLocationArg)
{
	// Save Spawn location to Var
	SpawnLocation = SpawnLocationArg;
	
	// Check if the value is set in Blueprints before moving on
	if (!SunPlanet) { return; }

	// Spawn Solar System
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	auto MySolarSystem = GetWorld()->SpawnActor<AND_Planet>(SunPlanet, SpawnLocation, FRotator(0, 0, 0), SpawnParams);
	
	// Update Spawned Bool to Stop Tracking
	bHasSpawned = true;

	// Destroy all Existing Spawn buttons
	TArray<AActor*> OUT_TempButtonActorArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AND_FloatingButton::StaticClass(), OUT_TempButtonActorArray);
	
	if (OUT_TempButtonActorArray.Num() < 1) { return; }

	for (auto item : OUT_TempButtonActorArray)
	{
		item->Destroy();
	}

	/// Remove Intro Text
	RemoveFindSurfaceText();
}

void AND_PlayerPawn::RespawnSolarSystem()
{
	// Check if planet is set in BP
	if (!SunPlanet) { return; }
	
	// Setup Spawn Params
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// Spawn Solar System
	auto MySolarSystem = GetWorld()->SpawnActor<AND_Planet>(SunPlanet, SpawnLocation, FRotator(0, 0, 0), SpawnParams);
}
