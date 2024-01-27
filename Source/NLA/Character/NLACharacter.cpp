// CopyRight Nolla NLA


#include "NLACharacter.h"
#include "NLAPlayerState.h"
#include "AbilitysystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ANLACharacter::ANLACharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void ANLACharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Ability Actor info ���� �ʱ�ȭ
	// OnRep_PlayerState ���� Ŭ���̾�Ʈ �ʱ�ȭ
	InitAbilityActorInfo();

}

void ANLACharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Ability Actor info ���� �ʱ�ȭ
	// OnRep_PlayerState ���� Ŭ���̾�Ʈ �ʱ�ȭ
	InitAbilityActorInfo();
}

void ANLACharacter::InitAbilityActorInfo()
{
	ANLAPlayerState* NLAPlayerState = GetPlayerState<ANLAPlayerState>();
	check(NLAPlayerState);
	NLAPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(NLAPlayerState, this);
	AbilitySystemComponent = NLAPlayerState->GetAbilitySystemComponent();
	AttributeSet = NLAPlayerState->GetAttributeSet();
}
