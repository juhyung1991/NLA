// CopyRight Nolla NLA

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NLACharacterBase.generated.h"

UCLASS()
class NLA_API ANLACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANLACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
