// CopyRight Nolla NLA


#include "NLACharacterBase.h"

// Sets default values
ANLACharacterBase::ANLACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANLACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANLACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANLACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

