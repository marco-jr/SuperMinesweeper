// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/


#include "StartGameWidget.h"
#include "Components/Button.h"
#include "MinesweeperGameInstance.h"

void UStartGameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	StartGameButton->OnClicked.AddDynamic(this, &UStartGameWidget::StartGame);
	ExitGameButton->OnClicked.AddDynamic(this, &UStartGameWidget::ExitGame);

	MinesweeperGameInstance = Cast<UMinesweeperGameInstance>(GetWorld()->GetGameInstance());
}

void UStartGameWidget::StartGame()
{
	if (MinesweeperGameInstance)
	{
		if (MinesweeperGameInstance->WebSocket->IsConnected())
		{
			FString _Command = "new 1";
			MinesweeperGameInstance->WebSocket->Send(_Command);
			OnStartGame.Broadcast();
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Wait for the connection to start playing.");
		}
	}
}

void UStartGameWidget::ExitGame()
{
	OnExitGame.Broadcast();
}