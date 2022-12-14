// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MinesweeperController.generated.h"

/**
 * 
 */
UCLASS()
class EVOLUTIONCHALLENGE_API AMinesweeperController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

protected:
// METHODS
	// Called when the player release the left mouse button
	UFUNCTION()
		void MouseClick();

	// Called when the player release the right mouse button
	UFUNCTION()
		void RightClick();
};
