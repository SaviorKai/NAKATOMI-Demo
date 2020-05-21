// Copyright by Ivan Engelbrecht 2020. All Rights reserved.

#include "ND_PlanetArmComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
UND_PlanetArmComponent::UND_PlanetArmComponent()
{
	bDoCollisionTest = false;
	SetRelativeLocation(FVector(0.0f, 0.0f, 40.0f));
}

void UND_PlanetArmComponent::BeginPlay()
{
	Super::BeginPlay();

	DefaultArmLength = TargetArmLength;
}

float UND_PlanetArmComponent::GetDefaultArmLength()
{
	return DefaultArmLength;
}
