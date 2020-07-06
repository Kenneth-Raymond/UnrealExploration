// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UNREALEXPLORATION_API UMyObject : public UObject
{
	GENERATED_BODY()
	public:

		UPROPERTY(BlueprintReadWrite, Category = "My Variables")
		float myFloat;

		UMyObject();
		//UCLASS(BlueprintCallable, Category = "My Fuctions")
		void MyFunction();
		
		
};
