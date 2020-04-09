// Copyright by Ivan Engelbrecht 2020. All Rights reserved.


#include "ND_Planet.h"
#include "Components/WidgetComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AND_Planet::AND_Planet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AND_Planet::BeginPlay()
{
	Super::BeginPlay(); 
	
}

void AND_Planet::SetIsFocusedSpawn(bool IsFocused)
{
	bIsFocusedSpawn = IsFocused;
}

bool AND_Planet::GetIsFocusedSpawn()
{
	return bIsFocusedSpawn;
}

// Called every frame
void AND_Planet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FName AND_Planet::GetMyPlanetName()
{
	return PlanetName;
}

void AND_Planet::EnableName()
{
	NameAlpha = 1.0f;
}

void AND_Planet::DisableName()
{
	NameAlpha = 0.0f;
}

float AND_Planet::GetNameAplha()
{
	return NameAlpha;
}





