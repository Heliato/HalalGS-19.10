#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TemplateSequence

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "CoreUObject_classes.hpp"
#include "MovieScene_structs.hpp"
#include "MovieScene_classes.hpp"
#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "CinematicCamera_structs.hpp"
#include "TemplateSequence_structs.hpp"


namespace SDK
{

// Class TemplateSequence.TemplateSequenceActor
// 0x0058 (0x0278 - 0x0220)
class ATemplateSequenceActor final : public AActor
{
public:
	uint8                                         Pad_220[0x10];                                     // 0x0220(0x0010)(Fixing Size After Last Property [ Dumper-7 ])
	struct FMovieSceneSequencePlaybackSettings    PlaybackSettings;                                  // 0x0230(0x0014)(Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_244[0x4];                                      // 0x0244(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UTemplateSequencePlayer*                SequencePlayer;                                    // 0x0248(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, Transient, InstancedReference, IsPlainOldData, NoDestructor, PersistentInstance, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FSoftObjectPath                        TemplateSequence;                                  // 0x0250(0x0018)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FTemplateSequenceBindingOverrideData   BindingOverride;                                   // 0x0268(0x000C)(BlueprintVisible, BlueprintReadOnly, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_274[0x4];                                      // 0x0274(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void SetBinding(class AActor* Actor, bool bOverridesDefault);
	void SetSequence(class UTemplateSequence* InSequence);

	class UTemplateSequence* GetSequence() const;
	class UTemplateSequencePlayer* GetSequencePlayer() const;
	class UTemplateSequence* LoadSequence() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TemplateSequenceActor">();
	}
	static class ATemplateSequenceActor* GetDefaultObj()
	{
		return GetDefaultObjImpl<ATemplateSequenceActor>();
	}
};

// Class TemplateSequence.TemplateSequence
// 0x00A8 (0x0108 - 0x0060)
class UTemplateSequence : public UMovieSceneSequence
{
public:
	class UMovieScene*                            MovieScene;                                        // 0x0060(0x0008)(ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSoftClassPtr<class UClass>                   BoundActorClass;                                   // 0x0068(0x0028)(UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSoftObjectPtr<class AActor>                  BoundPreviewActor;                                 // 0x0090(0x0028)(UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TMap<struct FGuid, class FName>               BoundActorComponents;                              // 0x00B8(0x0050)(NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TemplateSequence">();
	}
	static class UTemplateSequence* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTemplateSequence>();
	}
};

// Class TemplateSequence.CameraAnimationSequence
// 0x0000 (0x0108 - 0x0108)
class UCameraAnimationSequence final : public UTemplateSequence
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"CameraAnimationSequence">();
	}
	static class UCameraAnimationSequence* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCameraAnimationSequence>();
	}
};

// Class TemplateSequence.CameraAnimationSequenceCameraStandIn
// 0x0698 (0x06C0 - 0x0028)
class UCameraAnimationSequenceCameraStandIn final : public UObject
{
public:
	uint8                                         Pad_28[0x8];                                       // 0x0028(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         FieldOfView;                                       // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         bConstrainAspectRatio : 1;                         // 0x0034(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_35[0x3];                                       // 0x0035(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         AspectRatio;                                       // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_3C[0x4];                                       // 0x003C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPostProcessSettings                   PostProcessSettings;                               // 0x0040(0x05B0)(NativeAccessSpecifierPublic)
	float                                         PostProcessBlendWeight;                            // 0x05F0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FCameraFilmbackSettings                Filmback;                                          // 0x05F4(0x000C)(NoDestructor, NativeAccessSpecifierPublic)
	struct FCameraLensSettings                    LensSettings;                                      // 0x0600(0x0018)(NoDestructor, NativeAccessSpecifierPublic)
	struct FCameraFocusSettings                   FocusSettings;                                     // 0x0618(0x0058)(NativeAccessSpecifierPublic)
	float                                         CurrentFocalLength;                                // 0x0670(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         CurrentAperture;                                   // 0x0674(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         CurrentFocusDistance;                              // 0x0678(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_67C[0x44];                                     // 0x067C(0x0044)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"CameraAnimationSequenceCameraStandIn">();
	}
	static class UCameraAnimationSequenceCameraStandIn* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCameraAnimationSequenceCameraStandIn>();
	}
};

// Class TemplateSequence.CameraAnimationSequencePlayer
// 0x0400 (0x0428 - 0x0028)
class UCameraAnimationSequencePlayer final : public UObject
{
public:
	uint8                                         Pad_28[0x2A8];                                     // 0x0028(0x02A8)(Fixing Size After Last Property [ Dumper-7 ])
	class UObject*                                BoundObjectOverride;                               // 0x02D0(0x0008)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class UMovieSceneSequence*                    Sequence;                                          // 0x02D8(0x0008)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	struct FMovieSceneRootEvaluationTemplateInstance RootTemplateInstance;                              // 0x02E0(0x00E8)(Transient, NativeAccessSpecifierPrivate)
	uint8                                         Pad_3C8[0x60];                                     // 0x03C8(0x0060)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"CameraAnimationSequencePlayer">();
	}
	static class UCameraAnimationSequencePlayer* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCameraAnimationSequencePlayer>();
	}
};

// Class TemplateSequence.CameraAnimationSequenceSubsystem
// 0x0078 (0x00A8 - 0x0030)
class UCameraAnimationSequenceSubsystem final : public UWorldSubsystem
{
public:
	class UMovieSceneEntitySystemLinker*          Linker;                                            // 0x0030(0x0008)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_38[0x70];                                      // 0x0038(0x0070)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"CameraAnimationSequenceSubsystem">();
	}
	static class UCameraAnimationSequenceSubsystem* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCameraAnimationSequenceSubsystem>();
	}
};

// Class TemplateSequence.SequenceCameraShakePattern
// 0x0030 (0x0058 - 0x0028)
class USequenceCameraShakePattern final : public UCameraShakePattern
{
public:
	class UCameraAnimationSequence*               Sequence;                                          // 0x0028(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         PlayRate;                                          // 0x0030(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Scale;                                             // 0x0034(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         BlendInTime;                                       // 0x0038(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         BlendOutTime;                                      // 0x003C(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         RandomSegmentDuration;                             // 0x0040(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bRandomSegment;                                    // 0x0044(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_45[0x3];                                       // 0x0045(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UCameraAnimationSequencePlayer*         Player;                                            // 0x0048(0x0008)(ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData, NoDestructor, PersistentInstance, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class UCameraAnimationSequenceCameraStandIn*  CameraStandIn;                                     // 0x0050(0x0008)(ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData, NoDestructor, PersistentInstance, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPrivate)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"SequenceCameraShakePattern">();
	}
	static class USequenceCameraShakePattern* GetDefaultObj()
	{
		return GetDefaultObjImpl<USequenceCameraShakePattern>();
	}
};

// Class TemplateSequence.SequenceCameraShakeTestUtil
// 0x0000 (0x0028 - 0x0028)
class USequenceCameraShakeTestUtil final : public UBlueprintFunctionLibrary
{
public:
	static struct FMinimalViewInfo GetCameraCachePOV(class APlayerController* PlayerController);
	static struct FMinimalViewInfo GetLastFrameCameraCachePOV(class APlayerController* PlayerController);
	static bool GetPostProcessBlendCache(class APlayerController* PlayerController, int32 PPIndex, struct FPostProcessSettings* OutPPSettings, float* OutPPBlendWeight);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"SequenceCameraShakeTestUtil">();
	}
	static class USequenceCameraShakeTestUtil* GetDefaultObj()
	{
		return GetDefaultObjImpl<USequenceCameraShakeTestUtil>();
	}
};

// Class TemplateSequence.TemplateSequencePlayer
// 0x0008 (0x0508 - 0x0500)
class UTemplateSequencePlayer final : public UMovieSceneSequencePlayer
{
public:
	uint8                                         Pad_500[0x8];                                      // 0x0500(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UTemplateSequencePlayer* CreateTemplateSequencePlayer(class UObject* WorldContextObject, class UTemplateSequence* TemplateSequence, const struct FMovieSceneSequencePlaybackSettings& Settings, class ATemplateSequenceActor** OutActor);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TemplateSequencePlayer">();
	}
	static class UTemplateSequencePlayer* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTemplateSequencePlayer>();
	}
};

// Class TemplateSequence.TemplateSequenceSection
// 0x0018 (0x0140 - 0x0128)
class UTemplateSequenceSection final : public UMovieSceneSubSection
{
public:
	uint8                                         Pad_128[0x8];                                      // 0x0128(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FTemplateSectionPropertyScale>  PropertyScales;                                    // 0x0130(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TemplateSequenceSection">();
	}
	static class UTemplateSequenceSection* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTemplateSequenceSection>();
	}
};

// Class TemplateSequence.TemplateSequenceSystem
// 0x0070 (0x00B0 - 0x0040)
class UTemplateSequenceSystem final : public UMovieSceneEntitySystem
{
public:
	uint8                                         Pad_40[0x70];                                      // 0x0040(0x0070)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TemplateSequenceSystem">();
	}
	static class UTemplateSequenceSystem* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTemplateSequenceSystem>();
	}
};

// Class TemplateSequence.TemplateSequencePropertyScalingInstantiatorSystem
// 0x0058 (0x0098 - 0x0040)
class UTemplateSequencePropertyScalingInstantiatorSystem final : public UMovieSceneEntitySystem
{
public:
	uint8                                         Pad_40[0x58];                                      // 0x0040(0x0058)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TemplateSequencePropertyScalingInstantiatorSystem">();
	}
	static class UTemplateSequencePropertyScalingInstantiatorSystem* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTemplateSequencePropertyScalingInstantiatorSystem>();
	}
};

// Class TemplateSequence.TemplateSequencePropertyScalingEvaluatorSystem
// 0x0050 (0x0090 - 0x0040)
class UTemplateSequencePropertyScalingEvaluatorSystem final : public UMovieSceneEntitySystem
{
public:
	uint8                                         Pad_40[0x50];                                      // 0x0040(0x0050)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TemplateSequencePropertyScalingEvaluatorSystem">();
	}
	static class UTemplateSequencePropertyScalingEvaluatorSystem* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTemplateSequencePropertyScalingEvaluatorSystem>();
	}
};

// Class TemplateSequence.TemplateSequenceTrack
// 0x0000 (0x00A0 - 0x00A0)
class UTemplateSequenceTrack final : public UMovieSceneSubTrack
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"TemplateSequenceTrack">();
	}
	static class UTemplateSequenceTrack* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTemplateSequenceTrack>();
	}
};

}

