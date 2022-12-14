// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MinesweeperCharacter.generated.h"

class UCameraComponent;

UCLASS(config = Game, BlueprintType)
class EVOLUTIONCHALLENGE_API AMinesweeperCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMinesweeperCharacter();

// COMPONENTS
	// The camera component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UCameraComponent* CameraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
