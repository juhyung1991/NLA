// CopyRight Nolla NLA


#include "NLAPlayerState.h"

#include "NLAAbilitySystemComponent.h"
#include "NLAAttributeSet.h"

ANLAPlayerState::ANLAPlayerState()
{

	AbilitySystemComponent = CreateDefaultSubobject<UNLAAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UNLAAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* ANLAPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
