// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/


#include "MinesweeperCell.h"
#include "Components/WidgetComponent.h"
#include "MinesweeperCellWidget.h"
#include "Components/SceneComponent.h"
#include "MinesweeperCellWidget.h"
#include "MinesweeperField.h"

// Sets default values
AMinesweeperCell::AMinesweeperCell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	CellWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Cell Widget Component"));

	RootComponent = SceneRoot;
	CellWidgetComponent->SetupAttachment(SceneRoot);

	if (MinesweeperCellWidgetClass)
	{
		CellWidgetComponent->SetWidgetClass(MinesweeperCellWidgetClass);
	}
}

void AMinesweeperCell::SetCellSettings(bool isBomb, int32 newCellNumber)
{
	bIsBomb = isBomb;
	CellNumber = newCellNumber;
	CellWidget->UpdateCellNumber(newCellNumber);
}

void AMinesweeperCell::SetFlag()
{
	if (bHasBeenClicked == false && CellWidget)
	{
		bIsFlagged = !bIsFlagged;

		if (bIsFlagged)
		{
			OnFlagged.Broadcast(this);
		}
		else
		{
			OnUnflagged.Broadcast(this);
		}

		CellWidget->SetFlagVisibility(bIsFlagged);
	}
}

void AMinesweeperCell::CellClicked()
{
	if (bHasBeenClicked == false && CellWidget && MinesweeperFieldReference)
	{
		if (!MinesweeperFieldReference->bIsGameOver)
		{
			if (bIsFlagged)
			{
				OnUnflagged.Broadcast(this);
				bIsFlagged = false;
			}
			bHasBeenClicked = true;

			if (bIsBomb)
			{
				CellWidget->SetBombVisibility(true);
				OnBombClick.Broadcast(this);
			}
			else
			{
				CellWidget->SetCellNumberVisibility(true);
				OnCellClick.Broadcast(this);

				if (CellNumber == 0)
				{
					TArray<AMinesweeperCell*> _FoundCells = MinesweeperFieldReference->GetNeighborCells(this);
					for (AMinesweeperCell* _CurrentCell : _FoundCells)
					{
						_CurrentCell->CellClicked();
					}
				}
			}
		}
	}
}

// Called when the game starts or when spawned
void AMinesweeperCell::BeginPlay()
{
	Super::BeginPlay();

	if (MinesweeperCellWidgetClass)
	{
		if (UMinesweeperCellWidget* _CastedWidget = Cast<UMinesweeperCellWidget>(CellWidgetComponent->GetWidget()))
		{
			CellWidget = _CastedWidget;
		}
	}
}

