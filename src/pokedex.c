#include "global.h"
#include "pokedex.h"
#include "pokedex_screen.h"

const u8 *sub_8088E20(u16 dexNum)
{
    return gPokedexEntries[dexNum].categoryName;
}

u16 GetPokedexHeightWeight(u16 dexNum, u8 data)
{
    switch (data)
    {
    case 0:  // height
        return gPokedexEntries[dexNum].height;
    case 1:  // weight
        return gPokedexEntries[dexNum].weight;
    default:
        return 1;
    }
}

s8 GetSetPokedexFlag(u16 nationalDexNo, u8 caseID)
{
    return DexScreen_GetSetPokedexFlag(nationalDexNo, caseID, 0);
}

u16 GetNationalPokedexCount(u8 caseID)
{
    u16 count = 0;
    u32 i;

    for (i = 0; i < NATIONAL_DEX_COUNT; i++)
    {
        switch (caseID)
        {
        case FLAG_GET_SEEN:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_SEEN_ANY_FORM))
                count++;
            break;
        case FLAG_GET_CAUGHT:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT_ANY_FORM))
                count++;
            break;
        }
    }
    return count;
}

u16 GetKantoPokedexCount(u8 caseID)
{
    u16 count = 0;
    u32 i;

    for (i = 0; i < KANTO_DEX_COUNT; i++)
    {
        switch (caseID)
        {
        case FLAG_GET_SEEN:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_SEEN_ANY_FORM))
                count++;
            break;
        case FLAG_GET_CAUGHT:
            if (GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT_ANY_FORM))
                count++;
            break;
        }
    }
    return count;
}

u16 GetExtendedPokedexCount(u8 caseID)
{
    u16 count = 0;
    u32 i;

    for (i = 0; i < EXTENDED_DEX_COUNT; i++)
    {
        switch (caseID)
        {
        case FLAG_GET_SEEN:
            if (GetSetPokedexFlag(ExtendedToNationalOrder(i + 1), FLAG_GET_SEEN_ANY_FORM))
                count++;
            break;
        case FLAG_GET_CAUGHT:
            if (GetSetPokedexFlag(ExtendedToNationalOrder(i + 1), FLAG_GET_CAUGHT_ANY_FORM))
                count++;
            break;
        }
    }
    return count;
}

bool16 HasAllHoennMons(void)
{
    u32 i;

    for (i = 0; i < HOENN_DEX_COUNT - 2; i++)
    {
        if (!GetSetPokedexFlag(HoennToNationalOrder(i + 1), FLAG_GET_CAUGHT_ANY_FORM))
            return FALSE;
    }
    return TRUE;
}

bool16 HasAllExtendedMons(void)
{
    u32 i;

    for (i = 0; i < EXTENDED_DEX_COUNT - 2; i++)
    {
        if (!GetSetPokedexFlag(ExtendedToNationalOrder(i + 1), FLAG_GET_CAUGHT_ANY_FORM))
            return FALSE;
    }
    return TRUE;
}

bool16 HasAllKantoMons(void)
{
    u32 i;

    for (i = 0; i < KANTO_DEX_COUNT - 1; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT_ANY_FORM))
            return FALSE;
    }
    return TRUE;
}

bool16 HasAllMons(void)
{
    u32 i;

    for (i = 0; i < NATIONAL_DEX_MEWTWO; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT_ANY_FORM))
            return FALSE;
    }
    for (i = NATIONAL_DEX_MEW; i < NATIONAL_DEX_TYRANITAR; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT_ANY_FORM))
            return FALSE;
    }
    for (i = NATIONAL_DEX_CELEBI; i < NATIONAL_DEX_RAYQUAZA; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT_ANY_FORM))
            return FALSE;
    }
    return TRUE;
}

bool16 HasNationalMon(void)
{   // checks if the player has a mon not in the Extended Dex
    u32 i;

    for (i = EXTENDED_DEX_COUNT + 1; i < NATIONAL_DEX_COUNT; i++)
    {
        if (GetSetPokedexFlag(ExtendedToNationalOrder(i + 1), FLAG_GET_CAUGHT_ANY_FORM))
            return TRUE;
    }
    return FALSE;
}

bool16 HasAllKantoMonsNew(void)
{   // separate from the old one because of link Trainer cards
    // this one includes Mew.
    u32 i;

    for (i = 0; i < KANTO_DEX_COUNT; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT_ANY_FORM))
            return FALSE;
    }
    return TRUE;
}

bool16 HasAllMonsNew(void)
{   // separate from the old one because of link Trainer cards
    // this one includes obtainable mythicals.
    u32 i;

    for (i = 0; i < NATIONAL_DEX_HO_OH; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
            return FALSE;
    }
    for (i = NATIONAL_DEX_CELEBI; i < NATIONAL_DEX_RAYQUAZA; i++)
    {
        if (!GetSetPokedexFlag(i + 1, FLAG_GET_CAUGHT))
            return FALSE;
    }
    if (!GetSetPokedexFlag(NATIONAL_DEX_DEOXYS, FLAG_GET_CAUGHT))
            return FALSE;
    return TRUE;
}
