// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MinesweeperField.generated.h"

class AMinesweeperCell;
class UGameOverWidget;
class UMinesweeperGameWidget;

// Enum of possible cells directions
UENUM(BlueprintType)
enum ECellDirection
{
	Up				UMETA(DisplayName = "Up"),
	UpRight		UMETA(DisplayName = "Up-Right"),
	Right			UMETA(DisplayName = "Right"),
	DownRight UMETA(DisplayName = "Down-Right"),
	Down		UMETA(DisplayName = "Down"),
	DownLeft	UMETA(DisplayName = "DownLeft"),
	Left			UMETA(DisplayName = "Left"),
	UpLeft		UMETA(DisplayName = "UpLeft")
};

// Integer 2D vector
USTRUCT(BlueprintType)
struct FVector2DInt
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
		int32 X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
		int32 Y;

	FVector2DInt() { X = 10; Y = 10; }

	FVector2DInt(int32 x, int32 y)
	{
		X = x;
		Y = y;
	}
};

UCLASS(config = Game, BlueprintType)
class EVOLUTIONCHALLENGE_API AMinesweeperField : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMinesweeperField();


// SETTINGS
	// The size of the Minesweeper field
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		FVector2DInt FieldSize;

	// The size of the each cell
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float CellSize = 100.0f;

	// The class of the Minesweeper Cell to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		TSubclassOf<AMinesweeperCell> MinesweeperCellClass;

	// The class of the Game Over Widget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		TSubclassOf<UGameOverWidget> GameOverWidgetClass;

	// The class of the Minesweeper Game Widget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		TSubclassOf<UMinesweeperGameWidget> MinesweeperGameWidgetClass;

	// The percentage of amount of bombs in the field
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float BombsPercent = 0.2f;

// LOGIC
	// Array of Minesweeper Cells
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		TArray<AMinesweeperCell*> CreatedCells;

	// Number of cells in the field
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		int32 CellsAmount;

	// The game over widget reference
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		UGameOverWidget* GameOverWidget;

	// The minesweeper game widget reference
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		UMinesweeperGameWidget* MinesweeperGameWidget;

	// Defines if the game is over or not
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Logic")
		bool bIsGameOver;

// FUNCTIONS
	// Called to get the location of a Cell by index
	UFUNCTION()
		FVector GetLocationFromCellIndex(int32 cellIndex);

	// Called to get the number of bombs beside the cell index
	UFUNCTION()
		int32 GetBombsBesideIndex(int32 cellIndex);

	// Called to get the neighbor Cell from a cell reference based in direction
	UFUNCTION()
		AMinesweeperCell* GetNeighborCell(int32 cellIndex, ECellDirection neighborDirection);

	// Return the indexes from cells with number zero
	UFUNCTION()
		TArray<AMinesweeperCell*> GetNeighborCells(AMinesweeperCell* cellReference);

	// Verify the winning condition
	UFUNCTION()
		bool GetPlayerWins();

// METHODS
	// Generate a new field with the FieldSize
	UFUNCTION()
		void CreateField();

	// Generate random bombs in the field
	UFUNCTION()
		void GenerateBombs();

	// Generate non-mined cells number
	UFUNCTION()
		void GenerateNonMinedNumbers();

	// Called when to make game start
	UFUNCTION()
		void StartGame();

	// Called when the player loses the game
	UFUNCTION()
		void GameOver();

	// Called when the player restart the game
	UFUNCTION()
		void RestartGame();

	// Called to verify if the player wins the game
	UFUNCTION()
		void VerifyPlayerWins();

	// Called to quit the game
	UFUNCTION()
		void ExitGame();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
