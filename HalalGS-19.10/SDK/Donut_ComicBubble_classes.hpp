#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Donut_ComicBubble

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass Donut_ComicBubble.Donut_ComicBubble_C
// 0x0050 (0x0298 - 0x0248)
class UDonut_ComicBubble_C final : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0248(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       Close;                                             // 0x0250(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Open;                                              // 0x0258(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UBorder*                                Border_ComicBubble;                                // 0x0260(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonRichTextBlock*                   RichText_Dialogue;                                 // 0x0268(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	float                                         DialogueTime;                                      // 0x0270(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_274[0x4];                                      // 0x0274(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   DialogueText;                                      // 0x0278(0x0018)(Edit, BlueprintVisible)
	bool                                          bUseAlternateImage;                                // 0x0290(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bUseDownArrow;                                     // 0x0291(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bWhiteBubble;                                      // 0x0292(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DownArrowSelection;                                // 0x0293(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void Construct();
	void DialogueTimeOut();
	void ExecuteUbergraph_Donut_ComicBubble(int32 EntryPoint);
	void IntroFinished();
	void OnDialogueFinished();
	void PreConstruct(bool IsDesignTime);
	void SetNewDialogue(const class FText& NewText, float DisplayTime);
	void StartDialogueSequence();
	void StartExistingDialogue();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Donut_ComicBubble_C">();
	}
	static class UDonut_ComicBubble_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UDonut_ComicBubble_C>();
	}
};

}

