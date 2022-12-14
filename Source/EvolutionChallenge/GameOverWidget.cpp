// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/


#include "GameOverWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UGameOverWidget::NativeConstruct()
{
	RestartButton->OnClicked.AddDynamic(this, &UGameOverWidget::RestartGameClicked);
	QuitButton->OnClicked.AddDynamic(this, &UGameOverWidget::QuitGameClicked);
}

void UGameOverWidget::PlayGameOverAnim()
{
	GameOverText->SetColorAndOpacity(FLinearColor::White);
	GameOverText->SetText(FText::FromString("Game Over"));
	PlayAnimation(GameOverAnim);
}

void UGameOverWidget::PlayGameWinsAnim()
{
	GameOverText->SetColorAndOpacity(FLinearColor::Green);
	GameOverText->SetText(FText::FromString("You Win!"));
	PlayAnimation(WinGameAnim);
}

void UGameOverWidget::RestartGameClicked()
{
	OnRestartClicked.Broadcast();
}

void UGameOverWidget::QuitGameClicked()
{
	OnExitClicked.Broadcast();
}
