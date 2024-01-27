// CopyRight Nolla NLA

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NLAPlayerController.generated.h"

class UInputMappingContext;
struct FInputActionValue;
class UInputAction;
class IEnemyInterface;
/**
 * 
 */
UCLASS()
class NLA_API ANLAPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ANLAPlayerController();
public:
	virtual void PlayerTick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> NLAContext;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;

};
