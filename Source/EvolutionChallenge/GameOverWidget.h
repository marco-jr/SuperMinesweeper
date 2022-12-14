// Code made by Marco Antônio, bio: https://www.linkedin.com/in/marco-a-junior/

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

class UButton;
class UTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameOverUpdate);
/**
 * 
 */
UCLASS()
class EVOLUTIONCHALLENGE_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Native constructor
	void NativeConstruct() override;

// COMPONENTS

	// The restart game button
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (BindWidget))
		UButton* RestartButton;

	// The quit game button
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (BindWidget))
		UButton* QuitButton;

	// The center text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (BindWidget))
		UTextBlock* GameOverText;

// ANIMATIONS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category = "Animations", meta = (BindWidgetAnim))
		UWidgetAnimation* GameOverAnim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category = "Animations", meta = (BindWidgetAnim))
		UWidgetAnimation* WinGameAnim;
	
// METHODS
	UFUNCTION()
		void PlayGameOverAnim();

	UFUNCTION()
		void PlayGameWinsAnim();

	UFUNCTION()
		void RestartGameClicked();

	UFUNCTION()
		void QuitGameClicked();

// LOGIC
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FGameOverUpdate OnRestartClicked;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FGameOverUpdate OnExitClicked;
};
