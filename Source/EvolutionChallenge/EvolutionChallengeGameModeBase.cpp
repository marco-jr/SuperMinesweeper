// Copyright Epic Games, Inc. All Rights Reserved.


#include "EvolutionChallengeGameModeBase.h"
#include "MinesweeperCharacter.h"
#include "MinesweeperController.h"

AEvolutionChallengeGameModeBase::AEvolutionChallengeGameModeBase()
{
	static ConstructorHelpers::FClassFinder<AMinesweeperCharacter> CharacterClassAsset(TEXT("/Game/Blueprints/Character/BP_MinesweeperCharacter"));
	if (CharacterClassAsset.Class)
	{
		DefaultPawnClass = CharacterClassAsset.Class;
	}

	static ConstructorHelpers::FClassFinder<AMinesweeperController> ControllerClassAsset(TEXT("/Game/Blueprints/Character/BP_MinesweeperController"));
	if (ControllerClassAsset.Class)
	{
		PlayerControllerClass = ControllerClassAsset.Class;
	}
}
