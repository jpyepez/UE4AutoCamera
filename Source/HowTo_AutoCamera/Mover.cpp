// Fill out your copyright notice in the Description page of Project Settings.

#include "Mover.h"


// Sets default values
AMover::AMover()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMover::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FVector NewLocation = GetActorLocation();
    float Displacement = FMath::Sin(4.0f * RunningTime);
    NewLocation.X = 200 * Displacement;
    RunningTime += DeltaTime;
    SetActorLocation(NewLocation);
}

