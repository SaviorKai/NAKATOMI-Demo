// Copyright by Ivan Engelbrecht 2020. All Rights reserved.


#include "ND_Planet.h"
#include "Components/WidgetComponent.h"

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

// Called every frame
void AND_Planet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FName AND_Planet::GetMyPlanetName()
{
	return PlanetName;
}

void AND_Planet::EnableDisableName()
{
	if (NameAlpha < 1)
	{
		NameAlpha = 1.0f;
	}
	else
	{
		NameAlpha = 0.0f;
	}
}

float AND_Planet::GetNameAplha()
{
	return NameAlpha;
}





