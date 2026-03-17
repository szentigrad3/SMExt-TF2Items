
// === TF2C CORE REWRITE HOOK ===
#include "index_map.h"

void OnItemCreated(void* item, int defIndex)
{
    ApplyOverrides(defIndex, item);
}
