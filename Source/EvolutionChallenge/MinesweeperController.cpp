// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/


#include "MinesweeperController.h"
#include "MinesweeperCell.h"

// Called when the game starts or when spawned
void AMinesweeperController::BeginPlay()
{
	Super::BeginPlay();

	SetShowMouseCursor(true);
	SetInputMode(FInputModeGameAndUI());
}

void AMinesweeperController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MouseClick", IE_Released, this, &AMinesweeperController::MouseClick);
	InputComponent->BindAction("RightClick", IE_Released, this, &AMinesweeperController::RightClick);
}

void AMinesweeperController::MouseClick()
{
	FHitResult _HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, _HitResult);

	if (_HitResult.Actor != nullptr)
	{
		if (AMinesweeperCell* _CellReference = Cast<AMinesweeperCell>(_HitResult.Actor))
		{
			_CellReference->CellClicked();
		}
	}
}

void AMinesweeperController::RightClick()
{
	FHitResult _HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, _HitResult);

	if (_HitResult.Actor != nullptr)
	{
		if (AMinesweeperCell* _CellReference = Cast<AMinesweeperCell>(_HitResult.Actor))
		{
			_CellReference->SetFlag();
		}
	}
}
