// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/


#include "MinesweeperGameInstance.h"
#include "WebSockets/Public/WebSocketsModule.h"

void UMinesweeperGameInstance::Init()
{
	Super::Init();

	if (!FModuleManager::Get().IsModuleLoaded("WebSockets"))
	{
		FModuleManager::Get().LoadModule("WebSockets");
	}

	WebSocket = FWebSocketsModule::Get().CreateWebSocket("wss://hometask.eg1236.com/game1/");

	// ON CONECTED
	WebSocket->OnConnected().AddLambda([]()
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, "Successfully connected");
		});

	// ON CONNECTION ERROR
	WebSocket->OnConnectionError().AddLambda([](const FString& Error)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, Error);
		});

	// ON CLOSED
	WebSocket->OnClosed().AddLambda([](int32 StatusCode, const FString& Reason, bool bWasClean)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, bWasClean ? FColor::Green : FColor::Red, "Connection closed " + Reason);
		});

	// ON MESSAGE
	WebSocket->OnMessage().AddLambda([](const FString& Message)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, "Received message: " + Message);
		});

	// ON MESSAGE SENT
	WebSocket->OnMessageSent().AddLambda([](const FString& Message)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, "Sent message: " + Message);
		});

	WebSocket->Connect();
}

void UMinesweeperGameInstance::Shutdown()
{
	if (WebSocket->IsConnected())
	{
		WebSocket->Close();
	}

	Super::Shutdown();
}