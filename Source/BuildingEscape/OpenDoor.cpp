// Copyright Joseph Magdalena IV 2019

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void UOpenDoor::OpenDoor()
{
	//Get Owner
	AActor* Owner = GetOwner();

	//Create a rotator
	FRotator NewRotation = FRotator(0.0f, -160.0f, 0.0f);
	FString RotationAsString = NewRotation.ToString();
	UE_LOG(LogTemp, Warning, TEXT("Door Rotation is at %s"), *RotationAsString);


	//Change Rotation
	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the trigger Volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
	}
	// If the ActorThatOpens is in the volume
		
	// ...
}

