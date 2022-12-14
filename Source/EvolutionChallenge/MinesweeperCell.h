// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MinesweeperCell.generated.h"

class UWidgetComponent;
class UMinesweeperCellWidget;
class AMinesweeperField;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMinesweeperUpdate, AMinesweeperCell*, mineSweeperCell);

UCLASS(config = Game, BlueprintType)
class EVOLUTIONCHALLENGE_API AMinesweeperCell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMinesweeperCell();

// SETTINGS
	// The Minesweeper Cell widget class
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		TSubclassOf<UMinesweeperCellWidget> MinesweeperCellWidgetClass;

// LOGIC
	// The 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		FVector2D CellPosition;

	// The number that represents how many bombs beside the cell
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		int32 CellNumber;

	// The value that defines if the cell is a Bomb
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		bool bIsBomb;

	// The value that defines if the cell is flagged
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		bool bIsFlagged;

	// Called when the Bomb Cell has been clicked
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		FMinesweeperUpdate OnBombClick;

	// Called when the common Cell has been clicked
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		FMinesweeperUpdate OnCellClick;

	// Called when the common Cell has been flagged
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		FMinesweeperUpdate OnFlagged;

	// Called when the common Cell has been unflagged
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		FMinesweeperUpdate OnUnflagged;

	// The value that defines if the cell has been clicked
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		bool bHasBeenClicked;

	// Called to get the Widget object from the Widget component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		UMinesweeperCellWidget* CellWidget;

	// The minesweeper field reference
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		AMinesweeperField* MinesweeperFieldReference;

// COMPONENTS
	// The cell widget component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UWidgetComponent* CellWidgetComponent;

	// The main root component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* SceneRoot;

// METHODS
	// Called to update the Cell settings
	UFUNCTION()
		void SetCellSettings(bool isBomb, int32 newCellNumber = 0);

	// Called to update the Cell flag condition
	UFUNCTION()
		void SetFlag();

	// Called when the flag was clicked
	UFUNCTION()
		void CellClicked();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
