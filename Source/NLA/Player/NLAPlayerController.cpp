// CopyRight Nolla NLA


#include "NLAPlayerController.h"
#include "EnemyInterface.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

ANLAPlayerController::ANLAPlayerController()
{
	bReplicates = true;
}

void ANLAPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();

}

void ANLAPlayerController::CursorTrace()
{
	FHitResult CursorHit;

	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit)
		return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	// Ŀ���� ���� Ʈ���̽��� ��
	// 1. (LastActor == null&& ThisActor == null)
	// - �ƹ��͵� ����
	// 2. (LastActor == null && ThisActor != null)
	// - ThisActor ���̶���Ʈ
	// 3. (LastActor != null && ThisActor == null)
	// - LastActor �����̶���Ʈ
	// 4. (LastActor != null && ThisActor != null) && (LastActor != ThisActor)
	// - LastActor �����̶���Ʈ, ThisActor ���̶���Ʈ
	// 5. (LastActor != null && ThisActor != null) && (LastActor == ThisActor)
	// - �ƹ��͵� ����

	if (LastActor == nullptr)
	{
		if (ThisActor == nullptr)
		{
			// Case 1 �ƹ��͵� ����
		}
		else
		{
			
			// Case 2
			ThisActor->HighlightActor();
		}
	}
	else // LastActor != null
	{
		if (ThisActor == nullptr)
		{
			// Case 3
			LastActor->UnHighlightActor();

		}
		else // ThisActor != nullptr
		{

			if (LastActor != ThisActor)
			{
				// Case 4
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// Case 5 �ƹ��͵� ����
			}
		}
	}
}


void ANLAPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(NLAContext);

	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(SubSystem);
	SubSystem->AddMappingContext(NLAContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);



}

void ANLAPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ANLAPlayerController::Move);

}

void ANLAPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);

	}

}


