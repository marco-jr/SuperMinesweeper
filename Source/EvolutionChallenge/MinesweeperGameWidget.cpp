// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/


#include "MinesweeperGameWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "MinesweeperField.h"

void UMinesweeperGameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (MinesweeperFieldReference)
	{
		RestartButton->OnClicked.AddDynamic(MinesweeperFieldReference, &AMinesweeperField::RestartGame);
		HelpButton->OnClicked.AddDynamic(MinesweeperFieldReference, &AMinesweeperField::Help);
		MapButton->OnClicked.AddDynamic(MinesweeperFieldReference, &AMinesweeperField::Map);
		QuitButton->OnClicked.AddDynamic(MinesweeperFieldReference, &AMinesweeperField::ExitGame);
	}
}

void UMinesweeperGameWidget::AddFlag(AMinesweeperCell* minesweeperCell)
{
	TotalFlags++;
	int32 _MineShow = TotalMines - TotalFlags;
	MineCountText->SetText(FText::FromString(FString::FromInt(_MineShow)));
	FlagCountText->SetText(FText::FromString(FString::FromInt(TotalFlags)));
}

void UMinesweeperGameWidget::RemoveFlag(AMinesweeperCell* minesweeperCell)
{
	TotalFlags--;
	int32 _MineShow = TotalMines - TotalFlags;
	MineCountText->SetText(FText::FromString(FString::FromInt(_MineShow)));
	FlagCountText->SetText(FText::FromString(FString::FromInt(TotalFlags)));
}

void UMinesweeperGameWidget::ResetFlags()
{
	TotalFlags = 0;
	FlagCountText->SetText(FText::FromString("0"));
}

void UMinesweeperGameWidget::SetTotalMines(int32 newTotal)
{
	TotalMines = newTotal;
	MineCountText->SetText(FText::FromString(FString::FromInt(TotalMines)));
	FlagCountText->SetText(FText::FromString("0"));
}

