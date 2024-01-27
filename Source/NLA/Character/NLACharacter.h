// CopyRight Nolla NLA

#pragma once

#include "CoreMinimal.h"
#include "NLACharacterBase.h"
#include "NLACharacter.generated.h"

/**
 * 
 */
UCLASS()
class NLA_API ANLACharacter : public ANLACharacterBase
{
	GENERATED_BODY()
public:
	ANLACharacter();
public:
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
private:
	void InitAbilityActorInfo();
};
