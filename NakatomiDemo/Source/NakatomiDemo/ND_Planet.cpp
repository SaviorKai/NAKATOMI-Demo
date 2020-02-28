// Copyright by Ivan Engelbrecht 2020. All Rights reserved.


#include "ND_Planet.h"

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

