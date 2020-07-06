// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	initialLocation = FVector(0.0f);
	placedLocation = FVector(0.0f);
	worldOrigin = FVector(0.0f);
	initialDirection = FVector(0.0f);

	bInitializeFloaterLocations = false;
	bShouldFloat = false;
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	placedLocation = GetActorLocation();

	if (bInitializeFloaterLocations)
	{
		SetActorLocation(initialLocation);
	}

	// Set actor position using temporary FVector variable
	//SetActorLocation(FVector(0.0f, 0.0f,0.0f));
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bShouldFloat)
	{
		FHitResult hitResult;
		AddActorLocalOffset(initialDirection, false,& hitResult);
	}

}

