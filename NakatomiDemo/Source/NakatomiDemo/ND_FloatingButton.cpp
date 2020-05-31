// Copyright by Ivan Engelbrecht 2020. All Rights reserved.


#include "ND_FloatingButton.h"
#include "ND_PlayerPawn.h"

// Sets default values
AND_FloatingButton::AND_FloatingButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AND_FloatingButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AND_FloatingButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AND_FloatingButton::SetMyOwner(APawn* MyOwningPawn)
{
	if (Cast<AND_PlayerPawn>(MyOwningPawn))				//Pointer Protection
	{
		MyOwner = Cast<AND_PlayerPawn>(MyOwningPawn);
	}
}

void AND_FloatingButton::AskPlayerPawnToSpawnSystem()
{
	if (!MyOwner) { return; } 
	
	MyOwner->CreateSolarSystem(GetActorLocation());
}


