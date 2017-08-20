// Copyright Hilmi Ilyas Rizaldi 2017

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
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{

	AActor* Owner = GetOwner(); // Find the owning object
	FRotator NewRotation = FRotator(0.f, -60.f, 0.f);// Create a rotator
	Owner->SetActorRotation(NewRotation);	// Set the door rotation
}

void UOpenDoor::CloseDoor()
{

	AActor* Owner = GetOwner(); // Find the owning object
	FRotator NewRotation = FRotator(0.f, 0.f, 0.f);// Create a rotator
	Owner->SetActorRotation(NewRotation);	// Set the door rotation
}



// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the trigger Volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) // If ActorThatOpens is in the volume
	{
		OpenDoor();
	}
	else {
		CloseDoor();
	}
}

