#pragma once
#include <unordered_map>
#include <vector>

struct AttrOverride
{
    int id;
    float value;
};

struct ItemOverride
{
    std::vector<AttrOverride> attrs;
};

extern std::unordered_map<int, ItemOverride> g_ItemOverrides;
