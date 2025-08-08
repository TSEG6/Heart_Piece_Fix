#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

extern u8 sFanfareState;

bool shouldStopFanfare = false;
bool hasPlayedFanfare = false;


RECOMP_HOOK ("func_8082ECE0")
void PickupCheck(Player* this, PlayState* play) {

 
    if (this->getItemId == GI_HEART_PIECE && (GET_QUEST_HEART_PIECE_COUNT == 3)) {
        shouldStopFanfare = true;
        hasPlayedFanfare = false;
    }
    else {
        shouldStopFanfare = false;
        hasPlayedFanfare = false;
    }
}

RECOMP_HOOK_RETURN("func_808482E0")
void StopNormalFanfare(PlayState* play) {
    if (shouldStopFanfare && !hasPlayedFanfare) {
        sFanfareState = 0;
        Audio_PlayFanfare(NA_BGM_GET_HEART);
        hasPlayedFanfare = true;
    }
}

RECOMP_HOOK ("func_80848294")
void ResetFanfare(PlayState* play) {

    if (hasPlayedFanfare) {

        hasPlayedFanfare = false;

    }

}
