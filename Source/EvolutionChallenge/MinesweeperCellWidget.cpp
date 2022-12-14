// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/


#include "MinesweeperCellWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UMinesweeperCellWidget::SetFlagVisibility(bool bVisible)
{
	FlagImage->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	BombImage->SetVisibility(ESlateVisibility::Hidden);
	CellNumber->SetVisibility(ESlateVisibility::Hidden);
}

void UMinesweeperCellWidget::SetBombVisibility(bool bVisible)
{
	BombImage->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	FlagImage->SetVisibility(ESlateVisibility::Hidden);
	CellNumber->SetVisibility(ESlateVisibility::Hidden);
}

void UMinesweeperCellWidget::SetCellNumberVisibility(bool bVisible)
{
	CellNumber->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	FlagImage->SetVisibility(ESlateVisibility::Hidden);
	BombImage->SetVisibility(ESlateVisibility::Hidden);
}

void UMinesweeperCellWidget::UpdateCellNumber(int newNumber)
{
	FLinearColor _TextColor;

	if (newNumber == 1)
	{
		_TextColor = OneColor;
	}
	else if (newNumber == 2)
	{
		_TextColor = TwoColor;
	}
	else if (newNumber == 3)
	{
		_TextColor = ThreeColor;
	}
	else if (newNumber == 4)
	{
		_TextColor = FourColor;
	}
	else if (newNumber == 5)
	{
		_TextColor = FiveColor;
	}
	else if (newNumber == 6)
	{
		_TextColor = SixColor;
	}
	else if (newNumber == 7)
	{
		_TextColor = SevenColor;
	}
	else if (newNumber == 8)
	{
		_TextColor = EightColor;
	}
	else
	{
		_TextColor = FLinearColor::White;
	}

	CellNumber->SetText(FText::FromString(FString::FromInt(newNumber)));
	CellNumber->SetColorAndOpacity(_TextColor);
}
