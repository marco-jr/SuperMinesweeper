// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/


#include "StartGameWidget.h"
#include "Components/Button.h"

void UStartGameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	StartGameButton->OnClicked.AddDynamic(this, &UStartGameWidget::StartGame);
	ExitGameButton->OnClicked.AddDynamic(this, &UStartGameWidget::ExitGame);
}

void UStartGameWidget::StartGame()
{
	OnStartGame.Broadcast();
}

void UStartGameWidget::ExitGame()
{
	OnExitGame.Broadcast();
}