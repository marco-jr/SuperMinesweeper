// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "WebSockets/Public/IWebSocket.h"
#include "MinesweeperGameInstance.generated.h"

// class IWebSocket;

/**
 * 
 */
UCLASS()
class EVOLUTIONCHALLENGE_API UMinesweeperGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	virtual void Shutdown() override;

	TSharedPtr<IWebSocket> WebSocket;
};
