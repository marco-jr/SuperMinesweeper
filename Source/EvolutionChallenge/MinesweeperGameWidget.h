// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MinesweeperGameWidget.generated.h"

class UTextBlock;
class UButton;
class AMinesweeperField;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameWidgetUpdate);

/**
 * 
 */
UCLASS()
class EVOLUTIONCHALLENGE_API UMinesweeperGameWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct() override;

// COMPONENTS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
		UTextBlock* MineCountText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
		UTextBlock* FlagCountText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
		UButton* RestartButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
		UButton* HelpButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
		UButton* MapButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
		UButton* QuitButton;

// LOGIC
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		AMinesweeperField* MinesweeperFieldReference;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		int32 TotalMines;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		int32 TotalFlags;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		FGameWidgetUpdate OnHelpClicked;

// METHODS
	UFUNCTION()
		void AddFlag(AMinesweeperCell* minesweeperCell);

	UFUNCTION()
		void RemoveFlag(AMinesweeperCell* minesweeperCell);

	UFUNCTION()
		void ResetFlags();

	UFUNCTION()
		void SetTotalMines(int32 newTotal);
};
