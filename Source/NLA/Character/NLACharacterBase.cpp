// CopyRight Nolla NLA


#include "NLACharacterBase.h"

// Sets default values
ANLACharacterBase::ANLACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ANLACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ANLACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

