#ifndef GUARD_CONSTANTS_FORMS_H
#define GUARD_CONSTANTS_FORMS_H

#include "species.h"


#define FORM_FLAG_SHIFT 14
// zero form is simply the 'normal' Gen 3 pokemon!
#define FORM_FLAG_VALUE(form) ((u16) form << FORM_FLAG_SHIFT)
#define FIRST_FORM FORM_FLAG_VALUE(1)
#define SECOND_FORM FORM_FLAG_VALUE(1)
#define THIRD_FORM FORM_FLAG_VALUE(1)
#define FORM_SPECIES_MASK (FIRST_FORM - 1)
#define FORM_PART(formSpecies) (formSpecies >> FORM_FLAG_SHIFT)
#define SPECIES_PART(species) (species & ((u16) FORM_SPECIES_MASK))
#define FORM_SPECIES_NUMBER(form, species) (species | form)


// this is the exact order pokemon forms appear in ROM pokemon data tables
// These definitions should only be used inside data files
#define FORM_FOSSILIZED_KABUTOPS 0
#define NUM_TOTAL_VARIANTS 1



// Order of this list is unimportant, these definitions can be used in
// wild pokemon encounters, trainer party data etc..
#define SPECIES_FOSSILIZED_KABUTOPS FORM_SPECIES_NUMBER(FIRST_FORM, SPECIES_KABUTOPS)


// Lists the order of the actual species ids
const u16 gFormsOrder[] = 
{
    [FORM_FOSSILIZED_KABUTOPS] = SPECIES_FOSSILIZED_KABUTOPS,
};

//#define SPECIES_FOSSILIZED_KABUTOPS (FIRST_FORM + SPECIES_KABUTOPS)

#endif // GUARD_CONSTANTS_FORMS_H
