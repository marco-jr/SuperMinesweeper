// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MinesweeperCellWidget.generated.h"

class UImage;
class UTextBlock;

/**
 * 
 */
UCLASS()
class EVOLUTIONCHALLENGE_API UMinesweeperCellWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
// SETTINGS
	// The color of the number text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		FLinearColor OneColor;

	// The color of the number text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		FLinearColor TwoColor;

	// The color of the number text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		FLinearColor ThreeColor;

	// The color of the number text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		FLinearColor FourColor;

	// The color of the number text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		FLinearColor FiveColor;

	// The color of the number text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		FLinearColor SixColor;

	// The color of the number text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		FLinearColor SevenColor;

	// The color of the number text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		FLinearColor EightColor;

// COMPONENTS
	// The flag image component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (BindWidget))
		UImage* FlagImage;

	// The bomb image component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (BindWidget))
		UImage* BombImage;

	// The cell number component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (BindWidget))
		UTextBlock* CellNumber;

// METHODS
	// Called to update the Flag visibility
	UFUNCTION()
		void SetFlagVisibility(bool bVisible);

	// Called to update the Bomb visibility
	UFUNCTION()
		void SetBombVisibility(bool bVisible);

	// Called to update the Cell Number visibility
	UFUNCTION()
		void SetCellNumberVisibility(bool bVisible);

	// Called to update the cell number text
	UFUNCTION()
		void UpdateCellNumber(int newNumber);
};
