#include "index_map.h"

void ApplyOverrides(int defIndex, void* item)
{
    auto it = g_ItemOverrides.find(defIndex);
    if (it == g_ItemOverrides.end())
        return;

    for (auto& attr : it->second.attrs)
    {
        TF2Attrib_SetByDefIndex(item, attr.id, attr.value);
    }
}
