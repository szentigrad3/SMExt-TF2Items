#include "extension.h"

TF2CItems g_Ext;
SMEXT_LINK(&g_Ext);

bool TF2CItems::SDK_OnLoad(char *error, size_t maxlength, bool late)
{
    char game[64];
    GetGameFolderName(game, sizeof(game));

    if (!strstr(game, "tf2c") && !strstr(game, "classified"))
    {
        snprintf(error, maxlength, "Not TF2C");
        return false;
    }

    return true;
}
