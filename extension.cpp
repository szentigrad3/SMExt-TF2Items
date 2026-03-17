
// TF2 Classified detection
bool IsTF2Classified()
{
    char game[64];
    GetGameFolderName(game, sizeof(game));
    return strstr(game, "tf2c") || strstr(game, "classified");
}
