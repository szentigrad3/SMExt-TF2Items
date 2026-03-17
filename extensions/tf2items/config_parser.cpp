#include "index_map.h"
#include "KeyValues.h"
#include <sstream>

void ParseConfig(KeyValues* kv)
{
    for (KeyValues* sub = kv->GetFirstSubKey(); sub; sub = sub->GetNextKey())
    {
        const char* idx = sub->GetString("index", "");
        if (!idx[0]) continue;

        std::stringstream ss(idx);
        std::string token;

        while (std::getline(ss, token, ';'))
        {
            int def = atoi(token.c_str());
            ItemOverride& ov = g_ItemOverrides[def];

            KeyValues* attrs = sub->FindKey("attributes");
            if (!attrs) continue;

            for (KeyValues* a = attrs->GetFirstSubKey(); a; a = a->GetNextKey())
            {
                int id = atoi(a->GetName());
                float val = atof(a->GetString(NULL, "1.0"));

                // safety check
                if (id <= 0 || id > 5000)
                    continue;

                ov.attrs.push_back({id, val});
            }
        }
    }
}
