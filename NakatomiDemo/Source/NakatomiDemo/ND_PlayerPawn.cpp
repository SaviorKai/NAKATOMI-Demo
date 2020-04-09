// Copyright by Ivan Engelbrecht 2020. All Rights reserved.


#include "ND_PlayerPawn.h"
#include "ARBlueprintLibrary.h"
#include "ND_Planet.h"
#include "ND_FloatingButton.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"


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

// Called every frame
void AND_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/// Skip if we have already spawned something
	if (bHasSpawned) { return; }

	/// Get All Geometries
	TArray<UARPlaneGeometry*> MyGeometries = UARBlueprintLibrary::GetAllTrackedPlanes();
	
	/// Spawnn Buttons and Check if it's already spawned against AllPlanesArray
	if (MyGeometries.Num() > 0)
	{
		for (auto item : MyGeometries)
		{
			if (AllPlanesArray.Num() >= 1)
			{
				bool bExistsAlready = false;

				for (auto PlaneItem : AllPlanesArray)
				{
					if (item == PlaneItem)
					{
						bExistsAlready = true;
					}
				}

				if (!bExistsAlready)
				{
					AllPlanesArray.Add(item);
					CreateButtonObject(item->GetLocalToWorldTransform().GetLocation(), item);
					//UE_LOG(LogTemp, Warning, TEXT("AllPlanesArray > 0, And we Spawned!! :D"));
				}
			}
			else
			{
				AllPlanesArray.Add(item);
				CreateButtonObject(item->GetLocalToWorldTransform().GetLocation(), item);
				//UE_LOG(LogTemp, Warning, TEXT("AllPlanesArray = 0, So we Spawned"));
			}
		}
	}
}

// Called to bind functionality to input
void AND_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AND_PlayerPawn::CreateButtonObject(FVector Location, UARPlaneGeometry* GeometryItem)
{
	if (!SpawnButton) { return; }
	
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;

	auto MyButton = GetWorld()->SpawnActor<AND_FloatingButton>(SpawnButton, Location, FRotator(0,0,0), SpawnParams);
	MyButton->SetMyOwningGeometry(GeometryItem);
	MyButton->SetOwner(this);
}

void AND_PlayerPawn::CreateSolarSystem(UARPlaneGeometry* GeometryItem)
{
	if (!GeometryItem) { return; }

	SpawnLocation = GeometryItem->GetLocalToWorldTransform().GetLocation();

	if (!SunPlanet) { return; }

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// Spawn Solar System
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
