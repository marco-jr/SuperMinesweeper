// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/


#include "MinesweeperField.h"
#include "MinesweeperCell.h"
#include "GameOverWidget.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MinesweeperGameWidget.h"

// Sets default values
AMinesweeperField::AMinesweeperField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


}

// Called when the game starts or when spawned
void AMinesweeperField::BeginPlay()
{
	Super::BeginPlay();

	if (GameOverWidgetClass)
	{
		GameOverWidget = CreateWidget<UGameOverWidget>(GetWorld()->GetFirstPlayerController(), GameOverWidgetClass);
		GameOverWidget->OnRestartClicked.AddDynamic(this, &AMinesweeperField::RestartGame);
		GameOverWidget->OnExitClicked.AddDynamic(this, &AMinesweeperField::ExitGame);
	}

	if (MinesweeperGameWidgetClass)
	{
		MinesweeperGameWidget = CreateWidget<UMinesweeperGameWidget>(GetWorld()->GetFirstPlayerController(), MinesweeperGameWidgetClass);
		MinesweeperGameWidget->MinesweeperFieldReference = this;
		MinesweeperGameWidget->AddToViewport();
	}

	StartGame();
}

FVector AMinesweeperField::GetLocationFromCellIndex(int32 cellIndex)
{
	int32 _Column = cellIndex % FieldSize.X;
	int32 _Row = cellIndex / FieldSize.X;
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::White, FString::FromInt(_Row));

	float _LocationX = GetActorLocation().X + _Column * CellSize + (CellSize / 2);
	float _LocationY = GetActorLocation().Y + _Row * CellSize + (CellSize / 2);

	return FVector(_LocationX, _LocationY, 0);
}

int32 AMinesweeperField::GetBombsBesideIndex(int32 cellIndex)
{
	int32 _BombsAmount = 0;
	ECellDirection _CurrentDirection;

	for (int32 _CurrentIndex = 0; _CurrentIndex <= 7; _CurrentIndex++)
	{
		_CurrentDirection = (ECellDirection)_CurrentIndex;
		if (AMinesweeperCell* _FoundCell = GetNeighborCell(cellIndex, _CurrentDirection))
			if (_FoundCell->bIsBomb)
			{
				int32 _Index = CreatedCells.Find(_FoundCell);
				//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::White, FString::FromInt(_Index));
				_BombsAmount++;
			}
	}

	return _BombsAmount;
}

AMinesweeperCell* AMinesweeperField::GetNeighborCell(int32 referenceIndex, ECellDirection neighborDirection)
{
	int32 _IndexDifference;
	int32 _FindIndex;

	switch (neighborDirection)
	{
	case Up:
		_IndexDifference = FieldSize.X;
		_FindIndex = referenceIndex - _IndexDifference;
		if (_FindIndex >= 0)
		{
			return CreatedCells[_FindIndex];
		}
		break;
	case UpRight:
		_IndexDifference = FieldSize.X - 1;
		_FindIndex = referenceIndex - _IndexDifference;
		if (_FindIndex >= 0 && _FindIndex % FieldSize.X != 0)
		{
			return CreatedCells[_FindIndex];
		}
		break;
	case Right:
		_IndexDifference = 1;
		_FindIndex = referenceIndex + _IndexDifference;
		if (_FindIndex % FieldSize.X != 0 && _FindIndex < CreatedCells.Num())
		{
			return CreatedCells[_FindIndex];
		}
		break;
	case DownRight:
		_IndexDifference = FieldSize.X + 1;
		_FindIndex = referenceIndex + _IndexDifference;
		if (_FindIndex < CreatedCells.Num() && _FindIndex % FieldSize.X != 0)
		{
			return CreatedCells[_FindIndex];
		}
		break;
	case Down:
		_IndexDifference = FieldSize.X;
		_FindIndex = referenceIndex + _IndexDifference;
		if (_FindIndex < CreatedCells.Num())
		{
			return CreatedCells[_FindIndex];
		}
		break;
	case DownLeft:
		_IndexDifference = FieldSize.X - 1;
		_FindIndex = referenceIndex + _IndexDifference;
		if (_FindIndex < CreatedCells.Num() && (_FindIndex + 1) % FieldSize.X != 0)
		{
			return CreatedCells[_FindIndex];
		}
		break;
	case Left:
		_IndexDifference = 1;
		_FindIndex = referenceIndex - _IndexDifference;
		if (_FindIndex >= 0 && (_FindIndex + 1) % FieldSize.X != 0)
		{
			return CreatedCells[_FindIndex];
		}
		break;
	case UpLeft:
		_IndexDifference = FieldSize.X + 1;
		_FindIndex = referenceIndex - _IndexDifference;
		if (_FindIndex >= 0 && (_FindIndex + 1) % FieldSize.X != 0)
		{
			return CreatedCells[_FindIndex];
		}
		break;
	default:
		break;
	}

	return nullptr;
}

TArray<AMinesweeperCell*> AMinesweeperField::GetNeighborCells(AMinesweeperCell* cellReference)
{
	TArray<AMinesweeperCell*> _NeighborCells;
	ECellDirection _CurrentDirection;

	for (int32 _CurrentIndex = 0; _CurrentIndex <= 7; _CurrentIndex++)
	{
		_CurrentDirection = (ECellDirection)_CurrentIndex;
		int32 _FoundIndex = CreatedCells.Find(cellReference);

		if (AMinesweeperCell* _FoundCell = GetNeighborCell(_FoundIndex, _CurrentDirection))
		{
			_NeighborCells.Add(_FoundCell);
		}
	}

	return _NeighborCells;
}

bool AMinesweeperField::GetPlayerWins()
{
	for (AMinesweeperCell* _CurrentCell : CreatedCells)
	{
		if (!_CurrentCell->bIsBomb && !_CurrentCell->bHasBeenClicked)
		{
			return false;
		}
	}
	return true;
}

void AMinesweeperField::CreateField()
{
	if (MinesweeperCellClass)
	{
		for (int32 _CurrentCellIndex = 0; _CurrentCellIndex < CellsAmount; _CurrentCellIndex++)
		{
			AMinesweeperCell* _CreatedCell = GetWorld()->SpawnActor<AMinesweeperCell>(MinesweeperCellClass, GetLocationFromCellIndex(_CurrentCellIndex), FRotator(0,0,0));
			_CreatedCell->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
			_CreatedCell->MinesweeperFieldReference = this;
			if (MinesweeperGameWidget)
			{
				_CreatedCell->OnFlagged.AddDynamic(MinesweeperGameWidget, &UMinesweeperGameWidget::AddFlag);
				_CreatedCell->OnUnflagged.AddDynamic(MinesweeperGameWidget, &UMinesweeperGameWidget::RemoveFlag);
			}

			CreatedCells.Add(_CreatedCell);
		}
	}
}

void AMinesweeperField::GenerateBombs()
{
	int32 _BombsAmount = CellsAmount * BombsPercent;
	int32 _RandomInt = -1;
	TArray<int32> _BombsIndexes;
	
	for (int32 _Index = 0; _Index < _BombsAmount; _Index++)
	{
		while (_BombsIndexes.Contains(_RandomInt) || _RandomInt == -1)
		{
			_RandomInt = FMath::RandRange(0, CellsAmount - 1);
		}
		
		_BombsIndexes.Add(_RandomInt);
		CreatedCells[_RandomInt]->SetCellSettings(true);
		CreatedCells[_RandomInt]->OnBombClick.AddDynamic(this, &AMinesweeperField::GameOver);
	}

	if (MinesweeperGameWidget)
	{
		MinesweeperGameWidget->SetTotalMines(_BombsAmount);
	}
}

void AMinesweeperField::GenerateNonMinedNumbers()
{
	for (AMinesweeperCell* _CurrentCell : CreatedCells)
	{
		if (!_CurrentCell->bIsBomb)
		{
			int32 _BombsFound = GetBombsBesideIndex(CreatedCells.Find(_CurrentCell));
			_CurrentCell->SetCellSettings(false, _BombsFound);
			_CurrentCell->OnCellClick.AddDynamic(this, &AMinesweeperField::VerifyPlayerWins);
		}
	}
}

void AMinesweeperField::StartGame()
{
	CellsAmount = FieldSize.X * FieldSize.Y;

	if (CellsAmount > 0)
	{
		bIsGameOver = false;
		CreateField();
		GenerateBombs();
		GenerateNonMinedNumbers();
	}
}

void AMinesweeperField::GameOver()
{
	if (GameOverWidget)
	{
		bIsGameOver = true;
		GameOverWidget->AddToViewport();
		GameOverWidget->PlayGameOverAnim();
	}
}

void AMinesweeperField::RestartGame()
{
	for (AMinesweeperCell* _CurrentCell : CreatedCells)
	{
		_CurrentCell->Destroy();
	}

	CreatedCells.Empty();

	GameOverWidget->RemoveFromViewport();

	if (MinesweeperGameWidget)
	{
		MinesweeperGameWidget->ResetFlags();
	}

	StartGame();
}

void AMinesweeperField::VerifyPlayerWins()
{
	if (GetPlayerWins())
	{
		bIsGameOver = true;
		GameOverWidget->AddToViewport();
		GameOverWidget->PlayGameWinsAnim();
	}
}

void AMinesweeperField::ExitGame()
{
	APlayerController* _ControllerReference = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame(GetWorld(), _ControllerReference, EQuitPreference::Quit, true);
}