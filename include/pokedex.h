#ifndef GUARD_POKEDEX_H
#define GUARD_POKEDEX_H

#define KANTO_DEX_COUNT 151
#define EXTENDED_DEX_COUNT 246
#define HOENN_DEX_COUNT 202
#define NATIONAL_DEX_COUNT 386

enum
{
    DEX_MODE_KANTO,
    DEX_MODE_NATIONAL
};

enum
{
    FLAG_GET_SEEN,
    FLAG_GET_CAUGHT,
    FLAG_SET_SEEN,
    FLAG_SET_CAUGHT,
    FLAG_GET_SEEN_ANY_FORM,
    FLAG_GET_CAUGHT_ANY_FORM
};

struct PokedexEntry
{
    /*0x00*/ u8 categoryName[12];
    /*0x0C*/ u16 height; //in decimeters
    /*0x0E*/ u16 weight; //in hectograms
    /*0x10*/ const u8 *description_FR;
    /*0x14*/ const u8 *description_LG;
    /*0x18*/ u16 unused;
    /*0x1A*/ u16 pokemonScale;
    /*0x1C*/ u16 pokemonOffset;
    /*0x1E*/ u16 trainerScale;
    /*0x20*/ u16 trainerOffset;
};  /*size = 0x24*/

void ResetPokedex(void);
void CopyMonCategoryText(u16 species, u8 *dst);
u16 GetPokedexHeightWeight(u16 dexNum, u8 data);
u16 GetNationalPokedexCount(u8);
u16 GetKantoPokedexCount(u8);
bool16 HasAllMons(void);
u8 CreateDexDisplayMonDataTask(u16 dexNum, u32 trainerId, u32 personality);
s8 GetSetPokedexFlag(u16 nationalNum, u8 caseId);
u16 GetNationalPokedexCount(u8);
u16 sub_80C0844(u8);
u16 GetKantoPokedexCount(u8);
bool16 HasAllHoennMons(void);
bool16 HasAllKantoMons(void);
bool16 HasAllMons(void);
bool16 HasAllExtendedMons(void);
u16 GetExtendedPokedexCount(u8 caseID);
bool16 HasNationalMon(void);
u8 DexScreen_RegisterMonToPokedex(u16 species);
bool16 HasAllKantoMonsNew(void);
bool16 HasAllMonsNew(void);

#endif // GUARD_POKEDEX_H
