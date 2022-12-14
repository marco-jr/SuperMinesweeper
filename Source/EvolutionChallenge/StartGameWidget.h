// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartGameWidget.generated.h"

class UButton;
class UMinesweeperGameInstance;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStartGameUpdate);

/**
 * 
 */
UCLASS()
class EVOLUTIONCHALLENGE_API UStartGameWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
// Native contrusct
	void NativeConstruct() override;

// COMPONENTS
	// Start game button
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
		UButton* StartGameButton;

	// Exit game button
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (BindWidget))
		UButton* ExitGameButton;

// LOGIC
	// Called when the start game button was pressed
	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		FStartGameUpdate OnStartGame;

	// Called when the Exit Game button was pressed
	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		FStartGameUpdate OnExitGame;

	// The minesweeper game instance
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		UMinesweeperGameInstance* MinesweeperGameInstance;

// METHODS
	// Called when the start game button was pressed
	UFUNCTION()
		void StartGame();

	// Called when the Exit Game button was pressed
	UFUNCTION()
		void ExitGame();
};
