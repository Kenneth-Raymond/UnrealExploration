// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class UNREALEXPLORATION_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, category = "ActorMeshComponents")
	UStaticMeshComponent* StaticMesh;

	// Location of actor that is set when BeginPlay() is called
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, category = "Floater Variables")
	FVector initialLocation;
	
	// Location of actor when dragged in from the editor
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, category = "Floater Variables")
	FVector placedLocation;

	//
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "Floater Variables")
	bool bInitializeFloaterLocations;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, category = "Floater Variables")
	FVector worldOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = "Floater Variables")
	FVector initialDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = "Floater Variables")
	bool bShouldFloat;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
