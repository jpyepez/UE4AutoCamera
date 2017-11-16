// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraDirector.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    TimeToNextCameraChange -= DeltaTime;
    if(TimeToNextCameraChange <= 0.0f) {
        TimeToNextCameraChange += Cameras[CamIdx].GetCameraChangeInterval();
        
        // Find the actor that handles control for the local player
        APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
        if(OurPlayerController) {

			if (OurPlayerController->GetViewTarget() != Cameras[CamIdx].Camera && (Cameras[CamIdx].Camera != nullptr)) {
				// Blend smoothly to current camera
				OurPlayerController->SetViewTargetWithBlend(Cameras[CamIdx].Camera, Cameras[CamIdx].GetSmoothBlendtime());
			}

			// Increase CamIdx
			CamIdx++;
			CamIdx = CamIdx % Cameras.Num();
        }
    }
}

