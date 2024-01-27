// CopyRight Nolla NLA

#pragma once

#include "CoreMinimal.h"
#include "NLACharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "NLAEnemy.generated.h"


/**
 * 
 */
UCLASS()
class NLA_API ANLAEnemy : public ANLACharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	ANLAEnemy();
public:	

	// Enemy Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	// end Enemy Interface

protected:
	virtual void BeginPlay() override;

};
